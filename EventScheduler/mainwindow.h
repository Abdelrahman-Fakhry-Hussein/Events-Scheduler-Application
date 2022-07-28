#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "current_events.h"
#include "addevents.h"
#include "errorpanel.h"
#include "allevents.h"
#include "donePanel.h"
#include "Vec.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

public slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    current_events *curent;
    addEvents *newEvent;
    allEvents* allWindow;
    errorPanel* er;
    donePanel* donePan;
};
#endif // MAINWINDOW_H
