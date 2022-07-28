#ifndef DH_H
#define DH_H

#include <QDialog>

#include "scheduler.h"
#include "Date.h"
#include "addevents.h"
#include "dh.h"
#include "Vec.h"

//#define vector std::vector
QT_BEGIN_NAMESPACE
namespace Ui { class dh; }
QT_END_NAMESPACE

class dh : public QDialog
{
    Q_OBJECT

public:
    dh(QWidget *parent = nullptr);
    void intialize(vector <Vec>);
    ~dh();
private slots:
    void on_pushButton_clicked();

private:
    Ui::dh *ui;
};
#endif // DH_H
