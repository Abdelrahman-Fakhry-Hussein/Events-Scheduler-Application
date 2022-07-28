#include"Date.h"
#include"Vec.h"
#include "mainwindow.h"
#include "current_events.h"
#include "addevents.h"
#include "scheduler.h"
#include "allevents.h"
#include "donePanel.h"
#include "./ui_mainwindow.h"
#include "./ui_current_events.h"
#include "./ui_donePanel.h"
#include "./ui_addevents.h"
#include "./ui_allevents.h"
#include "errorpanel.h"
#include <QTableWidget>
#include <QDialog>
#include <Qmainwindow>
#include <QIcon>
#include <ctime>
#include <vector>


vector <Vec> allRowsVec;

int editedRow=-1;//to avoid erros 

bool editFlag = false;//34an a3rf if it is an edit panel or add panel

bool Vec::inVec(std::string name) {
    for (int i = 0; i < allRowsVec.size(); i++) {
        if (allRowsVec[i].eventName == name)
            return 1;
    }

    return 0;
}


int Vec::getIdFromName(std::string eventName) 
{
    int id;
    for (int i = 0; i < allRowsVec.size(); i++) {
        if (allRowsVec[i].eventName == eventName) {
            id = i;
            break;
        }
    }
    return id;
}


void Vec::vecIntialize() {
}


int Vec::getVecSize() { //return size
    return allRowsVec.size();
}


void Vec::vecAdd(Vec i) { //add an item
    i.id = allRowsVec.size();
    allRowsVec.push_back(i);
}


Vec Vec::vecRet(int i) {  // ret element
    return allRowsVec[i];
}


int Vec::setEditedRow(int i) { // return edited row 34an a3rf where to edit 3la 7sb el row in table my3ml4 m4akl
    editedRow = i;
    return 0;
}


int Vec::getEditedRow() { // return edited row 
    return editedRow;
}


bool Vec::getEditedRowDone(int i) {
    return allRowsVec[i].Done;
}


void Vec::setEditFlag(bool x) {
    editFlag = x;
}


bool Vec::getEditFlag() {
    return editFlag;
}


void Vec::vecDelete(int i) { // deletes from vector
    //removes from vector
    allRowsVec.erase(allRowsVec.begin() + i);
    //decrement all rows after the current - as the row-number will change if we remove the current
    for (int l = i; l < allRowsVec.size(); l++)
        allRowsVec[l].id--;
}



void Vec::vecCheck(int l) { //changes the check box 
    if (allRowsVec[l].Done == false) {
        allRowsVec[l].Done = true;
    }
    else {
        allRowsVec[l].Done = false;
    }
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Event Schedule");
    QMainWindow::setWindowIcon(QIcon("./image.png"));

}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_3_clicked() { // first button ely hwa ==UPCOMING EVENTS==
    curent = new current_events;
    curent->setAttribute(Qt::WA_DeleteOnClose); // 34an m3ml4 destructor 
    curent->show();
    curent->intialize(allRowsVec);

}

void MainWindow::on_pushButton_clicked() { // ADD EVENTS PANEL
    newEvent = new addEvents;
    newEvent->setAttribute(Qt::WA_DeleteOnClose);
    editFlag = false;
    newEvent->show();
}

void MainWindow::on_pushButton_2_clicked() {// ALL EVENTS
    allWindow = new allEvents;
    allWindow->setAttribute(Qt::WA_DeleteOnClose);
    allWindow->intialize(allRowsVec);
    allWindow->show();
}


void MainWindow::on_pushButton_4_clicked() //DE bta3t el SHOW DONE 
{
    Scheduler sched;

    const char* dir = R"(Scheduler.db)";
    vector <row> rowData;
    sched.createDB(dir);
    sched.createTable(dir);
    rowData = sched.selectDone(dir, 0);


    vector <Vec> vectorDone; // done Vec (different data structure)
    Vec rowVec;


    for (int i = 0; i < rowData.size(); i++)
    {
        rowVec.eventName = rowData[i].eventName;
        rowVec.place = rowData[i].Place;
        rowVec.startDate = rowData[i].startDate;
        rowVec.endDate = rowData[i].endDate;
        rowVec.startTime = rowData[i].startTime;
        rowVec.endTime = rowData.at(i).endTime;
        rowVec.reminderTime = rowData[i].reminderTime;
        rowVec.Done = true;
        vectorDone.push_back(rowVec);
    }
    donePan = new donePanel;
    donePan->setAttribute(Qt::WA_DeleteOnClose);;
    donePan->intialize(vectorDone);
    donePan->show();
    vectorDone.clear(); // 34an yb2a feh daymn el done bs (incase of errors)
}

void Vec::vecEdit(Vec editedVs) { //edit an item
    MainWindow m;
    editFlag = true;
    allRowsVec[editedVs.id] = editedVs;
    m.on_pushButton_2_clicked();
}
bool Vec:: MissedEvents(Vec rowEvent)
{
    Scheduler sched;
    time_t now = time(0);
    std::string dt = ctime(&now);
    tm* ltm = localtime(&now);
    Date endDate(rowEvent.endDate);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;
    int currentHour = ltm->tm_hour;
    int currentMinute = ltm->tm_min;
    Time eventEndTime(rowEvent.endTime);
    int eventEndHour = eventEndTime.getHour();
    int eventEndMinute = eventEndTime.getMinute();
    if (endDate.getYear() < currentYear)
    {
        return true;
    }
    else if (endDate.getYear() == currentYear) 
    {
        if (endDate.getMonth() < currentMonth)
        {
            return true;
        }
        else if (endDate.getMonth() == currentMonth)
        {
            if (endDate.getDay() < currentDay)
            {
                return true;
            }
            else if (endDate.getDay() == currentDay)
            {
                if (eventEndHour < currentHour)
                {
                    return true;
                }
                else if (eventEndHour == currentHour)
                {
                    if (eventEndMinute <= currentMinute)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}