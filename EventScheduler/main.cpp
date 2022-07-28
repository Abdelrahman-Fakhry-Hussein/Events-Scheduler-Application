#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "mainwindow.h"
#include "current_events.h"
#include "addevents.h"
#include "allevents.h"
#include "errorpanel.h"
#include <QtWidgets/QApplication>
#include <sqlite3.h>
#include <vector>
#include"Scheduler.h"

bool eventReminder(std::string d)
{   
    
    time_t now = time(0);
    std::string dt = ctime(&now);
    tm* ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    Date startDate(d);
    int reminderDay;
    int reminderMonth;
    int reminderYear;

    if (startDate.getDay() == 1)
    {
        if (startDate.getMonth() == 1)
        {
            reminderDay = 31;
            reminderMonth = 12;
            reminderYear = startDate.getYear() - 1;

        }

        else
        {
            reminderMonth = startDate.getMonth() - 1;
            reminderYear = startDate.getYear();
            switch (reminderMonth)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                reminderDay = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                reminderDay = 30;
                break;
            case 2:
                if (reminderYear % 4 == 0)
                {
                    reminderDay = 29;
                }
                else
                {
                    reminderDay = 28;
                }
                break;
            }
        }
    }

    else
    {
        reminderYear = startDate.getYear();
        reminderMonth = startDate.getMonth();
        reminderDay = startDate.getDay() - 1;
    }

    if (reminderDay == currentDay && reminderMonth == currentMonth && reminderYear == currentYear)
    {
        return true;
    }

    else
    {
        return false;
    }
}


int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    MainWindow mainWindowPannel;
    errorPanel er = new errorPanel;
    mainWindowPannel.show();
    Scheduler sched;
    

    const char* dir = R"(Scheduler.db)";
       vector <row> rowData;
        Vec rowEvent;
        sched.createDB(dir);
        sched.createTable(dir);
        rowData = sched.selectData(dir,0);
        // intialize lldata get it from db to table in gui 
        if (rowData.size() > 0) {
            for (int i = 0; i < rowData.size(); i++)
            {
                rowEvent.eventName = rowData[i].eventName;
                rowEvent.startDate = rowData.at(i).startDate;
                rowEvent.endDate = rowData.at(i).endDate;
                rowEvent.place = rowData.at(i).Place;
                rowEvent.startTime = rowData.at(i).startTime;
                rowEvent.endTime = rowData.at(i).endTime;
                rowEvent.reminderTime = rowData.at(i).reminderTime;
                if (rowData.at(i).Done == "true")
                    rowEvent.Done = true;
                else
                    rowEvent.Done = false;
                rowEvent.missedEvent = rowEvent.MissedEvents(rowEvent);
                rowEvent.vecAdd(rowEvent);
            }


            //if there is an event today
            vector <row> eventsSortedByStartDate;
            eventsSortedByStartDate = sched.sortByStartDate(rowData);
            bool res = false;
            int rowIndex;
            for (rowIndex = 0; rowIndex < rowData.size(); rowIndex++)
            {
                if (eventReminder(eventsSortedByStartDate.at(rowIndex).startDate))
                {
                    res = true;
                    break;
                }
            }
            std::string msg = " ";
            er.setWindowTitle("Reminder");
            er.setWindowIcon(QIcon("./image.png"));
            if (res == true)
            {
                msg = "You Have An Up-Coming Event Soon, Event : " + eventsSortedByStartDate[rowIndex].eventName;
                er.erPannel(msg);
                er.show();
            }          
        }
    return a.exec();
}
