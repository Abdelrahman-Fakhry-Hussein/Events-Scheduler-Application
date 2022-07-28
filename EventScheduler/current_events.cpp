#include"Date.h"
#include"Vec.h"
#include "current_events.h"
#include "scheduler.h"
#include "./ui_current_events.h"
#include<Qcheckbox>

#include<QStandardItem>
#include <QTableWidget>
#include <QDialog>
#include <Qmainwindow>
#include<QModelIndex>
#include<QtWidgets/QApplication>

//tb3 el gui
current_events::current_events(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::current_events) {
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Current Events");
    QMainWindow::setWindowIcon(QIcon("./image.png"));
    ui->tableWidget->setSelectionMode(QTableView::SingleSelection);

}

void current_events::intialize(vector <Vec> v) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].Done == 0) {
            if (v[i].missedEvent == false) 
            {

                QCheckBox* ch = new QCheckBox();
                //inserts a row

                ui->tableWidget->insertRow(count);
                ui->tableWidget->setCellWidget(count, 7, ch);
            
                
                //changes normal std:: string to Qstring 34an yzhr fel gui
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
                count++;
                //mfe4 event handler lel user-made checkbox fa de aknha event handler bt3ml connect lel function
                connect(ch, &QCheckBox::toggled, [=](bool checked) {
                    int id;
                    QModelIndex index;
                    QItemSelection selection = ui->tableWidget->selectionModel()->selection();
                    QList<int> Rows;
                    foreach(index, selection.indexes()) {
                        if (!Rows.contains(index.row())) {
                            Rows.append(index.row());
                            Vec tmp;
                            QStandardItem cellFont;
                            QString cell;
                         
                                cell = ui->tableWidget->model()->data(ui->tableWidget->model()->index(index.row(), 0)).toString();

                            id = tmp.getIdFromName(cell.toStdString());
                            break;
                        }
                    }
                    emit checkBoxChecked(ch, index.row(), id);
                    });

            }
            //else 

        }
    }
}

void current_events::checkBoxChecked(QCheckBox* ch, int count, int i) {
    Scheduler sched;
    Vec editedEvent;
    const char* dir = R"(Scheduler.db)";
    editedEvent.vecCheck(i);
    ui->tableWidget->removeRow(count);
    sched.updateDone(dir, editedEvent.vecRet(i));
}

current_events::~current_events() {
    delete ui;
}

void current_events::on_pushButton_clicked()
{
    const char* dir = R"(Scheduler.db)";
    ui->tableWidget->setRowCount(0);
    Scheduler sched;
    vector <row> rowData;
    vector <Vec>intializeVect;
    Vec rowVec;
    rowData = sched.selectData(dir, 1);
    for (int i = 0; i < rowData.size(); i++)
    {
        rowVec.eventName = rowData.at(i).eventName;
        rowVec.startDate = rowData.at(i).startDate;
        rowVec.endDate = rowData.at(i).endDate;
        rowVec.place = rowData.at(i).Place;
        rowVec.startTime = rowData.at(i).startTime;
        rowVec.endTime = rowData.at(i).endTime;
        rowVec.reminderTime = rowData.at(i).reminderTime;

        if (rowData.at(i).Done == "true")
            rowVec.Done = true;
        else
            rowVec.Done = false;
        intializeVect.push_back(rowVec);
    }
    intialize(intializeVect);
    rowData.clear();
    intializeVect.clear();
}


void current_events::on_pushButton_2_clicked()
{
    const char* dir = R"(Scheduler.db)";
    ui->tableWidget->setRowCount(0);

    Scheduler sched;
    vector <row> rowData;
    vector <Vec>intializeVect;
    Vec rowVec;
    rowData = sched.selectData(dir, 2);
    for (int i = 0; i < rowData.size(); i++)
    {
        rowVec.eventName = rowData.at(i).eventName;
        rowVec.startDate = rowData.at(i).startDate;
        rowVec.endDate = rowData.at(i).endDate;
        rowVec.place = rowData.at(i).Place;
        rowVec.startTime = rowData.at(i).startTime;
        rowVec.endTime = rowData.at(i).endTime;
        rowVec.reminderTime = rowData.at(i).reminderTime;
        if (rowData.at(i).Done == "true")
            rowVec.Done = true;
        else
            rowVec.Done = false;
        intializeVect.push_back(rowVec);
    }

    intialize(intializeVect);
    intializeVect.clear();
    rowData.clear();
}

