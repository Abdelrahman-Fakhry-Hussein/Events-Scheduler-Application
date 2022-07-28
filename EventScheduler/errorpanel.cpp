#include "errorpanel.h"
#include "./ui_errorpanel.h"

errorPanel::errorPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::errorPanel)
{
    //QMainWindow::setWindowTitle("ERROR");
    //QMainWindow::setWindowIcon(QIcon("./image.png"));
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel { color : red; }");
}

void errorPanel::erPannel(std::string errormsg) {
    QString eror = QString::fromStdString(errormsg);
    ui->label->setText(eror);

}


void errorPanel::on_pushButton_clicked()
{
    errorPanel::close();
}

errorPanel::~errorPanel()
{
    delete ui;
}