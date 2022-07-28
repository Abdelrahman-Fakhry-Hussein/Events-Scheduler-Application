#ifndef ALLEVENTS_H
#define ALLEVENTS_H

#include <QTableWidgetItem>
#include <QTableWidget>
#include <QCheckBox>
#include <QMainWindow>
#include "scheduler.h"
#include "Date.h"
#include "addevents.h"
#include "dh.h"
#include "Vec.h"

#include <QIcon>
QT_BEGIN_NAMESPACE
namespace Ui { class allEvents; }
QT_END_NAMESPACE

class allEvents : public QMainWindow
{
    Q_OBJECT

public:
    allEvents(QWidget *parent = nullptr);
    void intialize(vector<Vec>);
    void rowUpdate();
    ~allEvents();
private slots:
    void checkBox1Checked(QCheckBox* checkBox, int);
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    




    void on_pushButton_5_clicked();

private:
    addEvents* edit;
    dh* deleteHistory;
    Scheduler s;
    Ui::allEvents *ui;
};
#endif // ALLEVENTS_H
