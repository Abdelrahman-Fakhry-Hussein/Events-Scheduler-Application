#ifndef ERRORPANEL_H
#define ERRORPANEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class errorPanel; }
QT_END_NAMESPACE

class errorPanel : public QMainWindow
{
    Q_OBJECT

public:
    errorPanel(QWidget *parent = nullptr);
    void erPannel(std::string);
    ~errorPanel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::errorPanel *ui;
};
#endif // ERRORPANEL_H
