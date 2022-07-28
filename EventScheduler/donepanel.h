#ifndef DONEPANEL_H
#define DONEPANEL_H

#include <QMainWindow>
#include "Date.h"
#include "Vec.h"

QT_BEGIN_NAMESPACE
namespace Ui { class donePanel; }
QT_END_NAMESPACE

class donePanel : public QMainWindow
{
    Q_OBJECT

public:
    donePanel(QWidget *parent = nullptr);
    void intialize(vector<Vec>);
    ~donePanel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::donePanel *ui;
};
#endif // DONEPANEL_H
