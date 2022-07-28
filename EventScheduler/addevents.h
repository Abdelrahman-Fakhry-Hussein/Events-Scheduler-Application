#ifndef ADDEVENTS_H
#define ADDEVENTS_H

#include <QMainWindow>
#include "Date.h"
#include "scheduler.h"
#include "errorpanel.h"
#include "vec.h"
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class addEvents; }
QT_END_NAMESPACE

class addEvents : public QMainWindow
{
    Q_OBJECT

public:
    Scheduler s;
    addEvents(QWidget *parent = nullptr);
    void editEvents(Vec);
    ~addEvents();
    

private slots:
    void on_pushButton_clicked();

private:
    errorPanel* er;
    //void closeEvent(QCloseEvent* events);
    Ui::addEvents *ui;
};
#endif // ADDEVENTS_H
