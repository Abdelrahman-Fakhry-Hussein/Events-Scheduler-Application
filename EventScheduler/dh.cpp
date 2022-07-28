#include "dh.h"
#include "./ui_dh.h"
#include<QtWidgets/QApplication>
#include<QList>
#include <Qmainwindow>



vector <Vec> deleteHistoryVec;
dh::dh(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dh)
{

    ui->setupUi(this);
    QDialog::setWindowTitle("Delete History");
    QDialog::setWindowIcon(QIcon("./image.png"));
}
void dh::intialize(vector <Vec> intializedVec) {
    int count = 0;
    deleteHistoryVec = intializedVec;
    for (int i = 0; i < intializedVec.size(); i++) {
        ui->tableWidget->insertRow(count);
        QTableWidgetItem* eName = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(intializedVec[i].eventName)));
        QTableWidgetItem* sDate = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(intializedVec[i].startDate)));
        QTableWidgetItem* eDate = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(intializedVec[i].endDate)));
        QTableWidgetItem* ePlace = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(intializedVec[i].place)));
        QTableWidgetItem* sTime = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(intializedVec[i].startTime)));
        QTableWidgetItem* eTime = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(intializedVec[i].endTime)));
        QTableWidgetItem* rTime = new
            QTableWidgetItem(tr("%1").arg(QString::fromStdString(intializedVec[i].reminderTime)));
        ui->tableWidget->setItem(count, 0, eName);
        ui->tableWidget->setItem(count, 1, sDate);
        ui->tableWidget->setItem(count, 2, eDate);
        ui->tableWidget->setItem(count, 3, ePlace);
        ui->tableWidget->setItem(count, 4, sTime);
        ui->tableWidget->setItem(count, 5, eTime);
        ui->tableWidget->setItem(count, 6, rTime);

        count++;
    }
}
void dh::on_pushButton_clicked()
{
    const char* dir = R"(Scheduler.db)";
    QItemSelection selection = ui->tableWidget->selectionModel()->selection();
    Vec deletedRow;
    Scheduler sched;
    //find out selected rows and it's indexes
    QList<int> removeRows;
    foreach(QModelIndex
        index, selection.indexes()) {
        if (!removeRows.contains(index.row())) {
            removeRows.append(index.row());
 
            // deletes from database
            sched.deleteData(dir, deleteHistoryVec[index.row()], 3);
            sched.insertData(dir, deleteHistoryVec[index.row()], 0);
            sched.insertData(dir, deleteHistoryVec[index.row()], 2);
            deletedRow.vecAdd(deleteHistoryVec[index.row()]);
        }
    }
    int j = 0;
    //loop through all selected rows
    for (int i = 0; i < removeRows.count(); ++i) {
        //decrement all rows after the current - as the row-number will change if we remove the current
        for (j = i; j < removeRows.count(); ++j) {
            if (removeRows.at(j) > removeRows.at(i)) {
                removeRows[j]--;
            }
        }
        //remove the selected row
        ui->tableWidget->model()->removeRows(removeRows.at(i), 1);

    }

}
dh::~dh()
{
    delete ui;
}

