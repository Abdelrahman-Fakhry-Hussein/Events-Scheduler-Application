#include "allevents.h"
#include "Date.h"
#include "Vec.h"
#include "./scheduler.h"
#include "./ui_allevents.h"
#include<QCheckBox>
#include<QModelIndex>
#include<QtWidgets/QApplication>
#include<QList>
#include <Qmainwindow>
const char* dir = R"(Scheduler.db)";

allEvents::allEvents(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::allEvents) {
    ui->setupUi(this);
    QMainWindow::setWindowTitle("All Events");
    QMainWindow::setWindowIcon(QIcon("./image.png"));
    ui->pushButton_3->setText("Sort By Start Date");
    ui->pushButton_2->setText("Sort By Reminder Date");
    ui->tableWidget->setSelectionMode(QTableView::SingleSelection);
}

void allEvents::rowUpdate() {
    allEvents::close();
}

void allEvents::intialize(vector <Vec> intializedVec) {
    int count = 0;
 
    for (int i = 0; i < intializedVec.size(); i++) {
        QCheckBox* ch = new QCheckBox();
        //inserts a row

        ui->tableWidget->insertRow(count);

        ui->tableWidget->setCellWidget(count, 7, ch);


        if (intializedVec[i].Done == 0)
            ch->setChecked(0);
        else
            ch->setChecked(1);

        //changes normal std:: string to Qstring 34an yzhr fel gui

        //by3ml add fel cells bta3t el grid/
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
        if (intializedVec[i].missedEvent) { //horizontal line in row if the event is missed
            QFont f;
            f.setStrikeOut(true);
            ui->tableWidget->item(count, 0)->setFont(f);
            ui->tableWidget->item(count, 1)->setFont(f);
            ui->tableWidget->item(count, 2)->setFont(f);
            ui->tableWidget->item(count, 3)->setFont(f);
            ui->tableWidget->item(count, 4)->setFont(f);
            ui->tableWidget->item(count, 5)->setFont(f);
            ui->tableWidget->item(count, 6)->setFont(f);
        }
        else {//just incase of errors 
            QFont fo;
            fo.setStrikeOut(false);
            ui->tableWidget->item(count, 0)->setFont(fo);
            ui->tableWidget->item(count, 1)->setFont(fo);
            ui->tableWidget->item(count, 2)->setFont(fo);
            ui->tableWidget->item(count, 3)->setFont(fo);
            ui->tableWidget->item(count, 4)->setFont(fo);
            ui->tableWidget->item(count, 5)->setFont(fo);
            ui->tableWidget->item(count, 6)->setFont(fo);
        }
        count++;
        connect(ch, &QCheckBox::toggled, [=](bool checked) {
            int id;
            QItemSelection selection = ui->tableWidget->selectionModel()->selection();
            QList<int> Rows;
            foreach(QModelIndex index, selection.indexes()) {
                if (!Rows.contains(index.row())) {
                    Rows.append(index.row());
                    
                    //get selected id 
                    Vec tmp;
                    QString cell;
                    cell = ui->tableWidget->model()->data(ui->tableWidget->model()->index(index.row(), 0)).toString();
                    id = tmp.getIdFromName(cell.toStdString());
                    
                    
                    break;
                }
            }
            emit checkBox1Checked(ch, id);
            });

    }
}

void allEvents::checkBox1Checked(QCheckBox* ch, const int count) {
    Vec editedEvent;
    editedEvent.vecCheck(count);
    Scheduler sched;
    sched.updateDone(dir, editedEvent.vecRet(count));
}
// delete data 

void allEvents::on_pushButton_clicked() {//delete
    //get selections
    errorPanel er = new errorPanel;
    QItemSelection selection = ui->tableWidget->selectionModel()->selection();
    Vec deletedRow;
    Scheduler sched;
    //find out selected rows and it's indexes
    QList<int> removeRows;
    foreach(QModelIndex
        index, selection.indexes()) {
        if (!removeRows.contains(index.row())) {
            removeRows.append(index.row());          
            
            
            
           //get id from selected cell
       
            QString cell;
            
            cell = ui->tableWidget->model()->data(ui->tableWidget->model()->index(index.row(), 0)).toString(); //gets event name in selected cells

            int id = deletedRow.getIdFromName(cell.toStdString()); // gets id of the event using event.eventName
            
                         

            // deletes from database
            sched.insertData(dir, deletedRow.vecRet(id),3);
            sched.deleteData(dir, deletedRow.vecRet(id), 0);
            sched.deleteData(dir, deletedRow.vecRet(id), 1);
            sched.deleteData(dir, deletedRow.vecRet(id), 2);
            deletedRow.vecDelete(id);// deletes from vector
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

void allEvents::on_pushButton_3_clicked() {//sort by start date
    //sort 1 button clears all rows

    ui->tableWidget->setRowCount(0);
    Scheduler sched;
    vector <row> rowData;
    vector <Vec>intializeVect;
    Vec vecRow;
    rowData = sched.selectData(dir,1);//select sorted by start date


    for (int i = 0; i < rowData.size(); i++)
    {
        vecRow.eventName = rowData.at(i).eventName;
        vecRow.startDate = rowData.at(i).startDate;
        vecRow.endDate = rowData.at(i).endDate;
        vecRow.place = rowData.at(i).Place;
        vecRow.startTime = rowData.at(i).startTime;
        vecRow.endTime = rowData.at(i).endTime;
        vecRow.reminderTime = rowData.at(i).reminderTime;

        if (rowData.at(i).Done == "true")
            vecRow.Done = true;
        else
            vecRow.Done = false;
        vecRow.missedEvent = vecRow.MissedEvents(vecRow);
        intializeVect.push_back(vecRow);
    }

    intialize(intializeVect);
    rowData.clear();
    intializeVect.clear();
}


void allEvents::on_pushButton_2_clicked() {
    //sort by reminder TIme
    ui->tableWidget->setRowCount(0);
    Scheduler sched;
    vector <row> rowData;
    vector <Vec>intializeVect;


    Vec vecRow;
    rowData = sched.selectData(dir, 2);//select sorted by reminder time

    time_t now = time(0);
    std::string dt = ctime(&now);
    tm* ltm = localtime(&now);

    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;
    int currentDay = ltm->tm_mday;

    for (int i = 0; i < rowData.size(); i++)
    {
        vecRow.eventName = rowData.at(i).eventName;
        vecRow.startDate = rowData.at(i).startDate;
        vecRow.endDate = rowData.at(i).endDate;
        vecRow.place = rowData.at(i).Place;
        vecRow.startTime = rowData.at(i).startTime;
        vecRow.endTime = rowData.at(i).endTime;
        vecRow.reminderTime = rowData.at(i).reminderTime;

        if (rowData.at(i).Done == "true")
            vecRow.Done = true;
        else
            vecRow.Done = false;
        vecRow.missedEvent = vecRow.MissedEvents(vecRow);
        intializeVect.push_back(vecRow);
    }
    intialize(intializeVect);
    rowData.clear();
    intializeVect.clear();
}

void allEvents::on_pushButton_4_clicked() // update events
{
    QItemSelection selection = ui->tableWidget->selectionModel()->selection();
    Vec editedRow;
    edit = new addEvents;
    //find out selected rows
    QList<int> editRows;
    foreach(QModelIndex
        index, selection.indexes()) {
        if (!editRows.contains(index.row())) {
            editRows.append(index.row());
            QString cell;

            //getting id of selected cell
            cell = ui->tableWidget->model()->data(ui->tableWidget->model()->index(index.row(), 0)).toString(); //gets event name in selected cell
            int id = editedRow.getIdFromName(cell.toStdString());



            edit->show();
            edit->editEvents(editedRow.vecRet(id));
            editedRow.setEditFlag(true);
            allEvents::close();

        }
    }
}


void allEvents::on_pushButton_5_clicked()
{
    allEvents::close();
    deleteHistory = new dh;
    Scheduler sched;
    vector <row> rowData;
    vector <Vec>intializeVect;


    Vec vecRow;
    rowData = sched.selectDeleted(dir);

    for (int i = 0; i < rowData.size(); i++)
    {
        vecRow.eventName = rowData.at(i).eventName;
        vecRow.startDate = rowData.at(i).startDate;
        vecRow.endDate = rowData.at(i).endDate;
        vecRow.place = rowData.at(i).Place;
        vecRow.startTime = rowData.at(i).startTime;
        vecRow.endTime = rowData.at(i).endTime;
        vecRow.reminderTime = rowData.at(i).reminderTime;
        vecRow.Done = false;
        vecRow.missedEvent = vecRow.MissedEvents(vecRow);
        intializeVect.push_back(vecRow);
    }
    deleteHistory->show();
    deleteHistory->intialize(intializeVect);
    rowData.clear();
    intializeVect.clear();
}


allEvents::~allEvents() {
    delete ui;
}

