#include "addevents.h"
#include "errorPanel.h"
#include "./ui_addevents.h"
#include "allevents.h"
#include "./ui_allevents.h"
#include<QCheckBox>
#include<QModelIndex>
#include <QCloseEvent>
#include<QtWidgets/QApplication>
#include<Qstring>
#include <regex>
#include<string>

using namespace std;

string msg;//error msg or alert msg 


addEvents::addEvents(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::addEvents) {
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Add Event");
    QMainWindow::setWindowIcon(QIcon("./image.png"));

}


bool isValidTime(std::string str)
{
    // Regex to check valid time in 24-hour format
    const regex pattern("([01]?[0-9]|2[0-3]):[0-5][0-9]");
    if (regex_match(str, pattern))  // Return true if the time in 24-hour format matched the ReGex
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool validate(Vec event) {
 
    //----validation-----(checks if input is empty)
    if (event.eventName == "" || event.eventName == " " || event.eventName.empty()) {
        msg = "U FORGOT TO ENTER EVENT NAME";
        return 0;
    }
    if (event.startDate == "" || event.startDate == " "||event.startDate.empty()) {
        msg = "U FORGOT TO ENTER START DATE";
        return 0;
    }
    if (event.endDate == "" || event.endDate == " " || event.endDate.empty())  {
        msg = "U FORGOT TO ENTER END DATE";
        return 0;
    }
    if (event.place == "" || event.place == " " || event.place.empty()) {
        msg = "YOU FORGOT TO ENTER PLACE!";
        return 0;
    }
    if (event.startTime == "" || event.startTime == " " || event.startTime.empty()) {
        msg = "YOU FORGOT TO ENTER START TIME!";
        return 0;
    }
    if (event.endTime == "" || event.endTime == " " || event.endTime.empty()) {
        msg = "YOU FORGOT TO ENTER END TIME!";
        return 0;
    }
    if (event.reminderTime == "" || event.reminderTime == " " || event.reminderTime.empty()) {
        msg = "YOU FORGOT TO ENTER REMINDER TIME!";
        return 0;
    }
    //---------------------------------------
    Date tempStartDate(event.startDate);
    Date tempEndDate(event.endDate);
    if (tempStartDate.getIsItIncorrect())
    {
        msg = "YOU WROTE THE START DATE WRONG";
        return 0;
    }
    if (tempEndDate.getIsItIncorrect())
    {
        msg = "YOU WROTE THE END DATE WRONG";
        return 0;
    }
    //---------------------------------------------
    if (!isValidTime(event.startTime)) {
        msg = "START TIME IS INVALID";
        return 0;
    }
    if (!isValidTime(event.endTime)) {
        msg = "END TIME IS INVALID";
        return 0;
    }
    if (!isValidTime(event.reminderTime)) {
        msg = "REMINDER TIME IS INVALID";
        return 0;
    }
    //------------------------------------
    return 1;
}
bool can_be_added(Vec event, int update) {
    //checks if there is no problem in boxes
    if (!validate(event)) {
        return 0;
    }
    else {
        const char* dir = R"(Scheduler.db)";
        Scheduler sched;
        vector<row> rowData = sched.selectrows(dir);

        if (update == 1)
            rowData.erase(rowData.begin() + event.id);


        bool endBool = true, dateValidatyBool = true, sDateBool = false, eDateBool = false, tempBool = true, startBool = true;

        errorPanel  er = new errorPanel;

        string startDate = event.startDate, endDate = event.endDate;

        int numberOfRows = rowData.size();

        Date tempStartDate(startDate), tempEndDate(endDate);

        string temp1, temp2;

        for (int i = 0; i < rowData.size(); i++)
        {
            temp1 = rowData.at(i).startDate;
            temp2 = rowData.at(i).endDate;
            if ((sched.compareDate(startDate, temp1)) && (sched.compareDate(temp2, startDate)))
            {
                startBool = false;
                msg = "Invalid Date. It intersects with another event!";
                numberOfRows--;
            }

            else
            {
                startBool = true;
            }

            if ((sched.compareDate(endDate, temp1)) && (sched.compareDate(temp2, endDate)))
            {
                endBool = false;
                msg = "Invalid Entry. It intersects with another event!";
                numberOfRows--;
            }
            else
            {
                endBool = true;
            }

            if ((sched.compareDate(temp1, startDate)) && (sched.compareDate(endDate, temp2)))
            {
                endBool = false;
                msg = "Invalid Entry. It intersects with another event!";
                numberOfRows--;
            }
            else
            {
                endBool = true;
            }
        }

        if (startBool == true && (numberOfRows == rowData.size()))
        {
            sDateBool = true;
        }

        if (sched.checkEventDateValidity(startDate, endDate))
        {
            dateValidatyBool = false;
            msg = "Invalid Date. It's end date is less than the start date!";
            numberOfRows--;
        }
        else
        {
            dateValidatyBool = true;
        }

        if (tempStartDate.getIsItIncorrect() || tempEndDate.getIsItIncorrect())
        {
            msg = "There's an error with the date";
            tempBool = false;
        }
        if (endBool == true && dateValidatyBool == true && (numberOfRows == rowData.size()) && tempBool == true)
        {
            eDateBool = true;
        }
        if (eDateBool == true && sDateBool == true)
            return 1;
        else
            return 0;
    }
}


void addEvents::on_pushButton_clicked() {
    Vec event;
    const char* dir = R"(Scheduler.db)";
    Scheduler sched;
    er = new errorPanel;
    er->setWindowTitle("Error");
    er->setWindowIcon(QIcon("./image.png"));
    //--------------------------------------



    event.eventName = ui->lineEdit->text().toStdString();
    event.startDate = ui->lineEdit_6->text().toStdString();
    event.endDate = ui->lineEdit_5->text().toStdString();
    event.place = ui->lineEdit_2->text().toStdString();
    event.startTime = ui->lineEdit_3->text().toStdString();
    event.reminderTime = ui->lineEdit_4->text().toStdString();
    event.endTime = ui->lineEdit_7->text().toStdString();




    //---------------------------------------



    if (event.getEditFlag() == false) {//if pannel us the add pannel
        event.Done = false;
        event.id = event.getVecSize() - 1;
        if (event.inVec(event.eventName) == false) // checks if there is an event with the same name
        {
            if (can_be_added(event, 0)) {
                sched.insertData(dir, event, 0);
                sched.insertData(dir, event, 2);
                event.vecAdd(event);
                addEvents::close();
            }
            else
            {
                er->show();
                er->erPannel(msg);
            }
        }
        else
        {
            er->show();
            er->erPannel("There Is An Event With The Same Name Please Change Event Name");
        }
    }





    else {//if pannel is EDIT pannel
        Vec retrunV;

        event.id = event.getEditedRow() - 1;
        retrunV = retrunV.vecRet(event.id);
        event.Done = event.getEditedRowDone(event.getEditedRow() - 1);
        event.vecDelete(event.getEditedRow() - 1);


        if (can_be_added(event, 1) == true) {
            event.vecAdd(event);
            sched.updateData(dir, event, retrunV);
            addEvents::close();
        }
        else
        {
            event.vecAdd(retrunV);
            er->show();
            er->erPannel("EVENT CANNOT BE UPDATED");
        }
    }
}

void addEvents::editEvents(Vec editedEvent)
{

    QMainWindow::setWindowTitle("Edit Event");;
    ui->pushButton->setText("Edit Event");
    ui->lineEdit->setText(QString::fromStdString(editedEvent.eventName));
    ui->lineEdit_6->setText(QString::fromStdString(editedEvent.startDate));
    ui->lineEdit_5->setText(QString::fromStdString(editedEvent.endDate));
    ui->lineEdit_2->setText(QString::fromStdString(editedEvent.place));
    ui->lineEdit_3->setText(QString::fromStdString(editedEvent.startTime));
    ui->lineEdit_4->setText(QString::fromStdString(editedEvent.reminderTime));
    ui->lineEdit_7->setText(QString::fromStdString(editedEvent.endTime));


    editedEvent.setEditFlag(true);
    editedEvent.setEditedRow(editedEvent.id + 1);


}

addEvents::~addEvents() {
    delete ui;
}