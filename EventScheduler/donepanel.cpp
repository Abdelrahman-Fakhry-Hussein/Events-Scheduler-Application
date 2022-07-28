#include "donepanel.h"
#include "./ui_donepanel.h"
#include"Date.h"
#include"Vec.h"
#include"scheduler.h"
#include<qcheckbox>
donePanel::donePanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::donePanel)
{
   
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Done Events");
    QMainWindow::setWindowIcon(QIcon("./image.png"));
}
void donePanel::intialize(vector <Vec> v) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        ui->tableWidget->insertRow(count);
        //changes normal std:: string to Qstring 34an yzhr fel gui
        QTableWidgetItem* done = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString("True")));
        QTableWidgetItem* eName = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(v[i].eventName)));
        QTableWidgetItem* sDate = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(v[i].startDate)));
        QTableWidgetItem* eDate = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(v[i].endDate)));
        QTableWidgetItem* ePlace = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(v[i].place)));
        QTableWidgetItem* sTime = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(v[i].startTime)));
        QTableWidgetItem* eTime = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(v[i].endTime)));
        QTableWidgetItem* rTime = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(v[i].reminderTime)));
        ui->tableWidget->setItem(count, 0, eName);
        ui->tableWidget->setItem(count, 1, sDate);
        ui->tableWidget->setItem(count, 2, eDate);
        ui->tableWidget->setItem(count, 3, ePlace);
        ui->tableWidget->setItem(count, 4, sTime);
        ui->tableWidget->setItem(count, 5, eTime);
        ui->tableWidget->setItem(count, 6, rTime);
        ui->tableWidget->setItem(count, 7, done);
        count++;
    }
}


void donePanel::on_pushButton_clicked()//starts
{
    const char* dir = R"(Scheduler.db)";
    ui->tableWidget->setRowCount(0);
    Scheduler sched;
    vector <row> rowData;
    vector <Vec>vecDone;
    Vec rowVec;
    rowData = sched.selectDone(dir, 1);
    for (int i = 0; i < rowData.size(); i++)
    {
        rowVec.eventName = rowData.at(i).eventName;
        rowVec.startDate = rowData.at(i).startDate;
        rowVec.endDate = rowData.at(i).endDate;
        rowVec.place = rowData.at(i).Place;
        rowVec.startTime = rowData.at(i).startTime;
        rowVec.endTime = rowData.at(i).endTime;
        rowVec.reminderTime = rowData.at(i).reminderTime;
        rowVec.Done = true;
        vecDone.push_back(rowVec);
    }
    intialize(vecDone);
}

void donePanel::on_pushButton_2_clicked()//reminder
{
    const char* dir = R"(Scheduler.db)";
    ui->tableWidget->setRowCount(0);
    Scheduler sched;
    vector <row> rowData;
    vector <Vec>vecDone;
    Vec rowVec;
    rowData = sched.selectDone(dir, 2);
    for (int i = 0; i < rowData.size(); i++)
    {
        rowVec.eventName = rowData.at(i).eventName;
        rowVec.startDate = rowData.at(i).startDate;
        rowVec.endDate = rowData.at(i).endDate;
        rowVec.place = rowData.at(i).Place;
        rowVec.startTime = rowData.at(i).startTime;
        rowVec.endTime = rowData.at(i).endTime;
        rowVec.reminderTime = rowData.at(i).reminderTime;
        rowVec.Done = true;
        vecDone.push_back(rowVec);
    }
    intialize(vecDone);
    rowData.clear();
    vecDone.clear();
}

donePanel::~donePanel()
{
    delete ui;
}
