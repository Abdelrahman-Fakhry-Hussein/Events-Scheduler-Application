#ifndef CURRENT_EVENTS_H
#define CURRENT_EVENTS_H
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QCheckBox>
#include <QMainWindow>
#include "Date.h"
#include "Vec.h"

QT_BEGIN_NAMESPACE
namespace Ui { class current_events; }
QT_END_NAMESPACE

class current_events : public QMainWindow
{
    Q_OBJECT

public:
    current_events(QWidget* parent = 0);
    void intialize(vector<Vec>);
    void addEvent();
    ~current_events();
public slots:
    void checkBoxChecked(QCheckBox* checkBox,int,int);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::current_events* ui;

};
#endif // CURRENT_EVENTS_H
