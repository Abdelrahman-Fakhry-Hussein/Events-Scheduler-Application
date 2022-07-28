/********************************************************************************
** Form generated from reading UI file 'addevents.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENTS_H
#define UI_ADDEVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addEvents
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_6;
    QLabel *label_4;
    QLineEdit *lineEdit_7;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *addEvents)
    {
        if (addEvents->objectName().isEmpty())
            addEvents->setObjectName(QString::fromUtf8("addEvents"));
        addEvents->setEnabled(true);
        addEvents->resize(723, 348);
        centralwidget = new QWidget(addEvents);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 8, 0, 1, 1);

        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 3, 1, 1, 4);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 4, 1, 1, 4);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 10, 0, 1, 5);

        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 8, 1, 1, 4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 6, 1, 1, 4);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 4);

        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 1, 1, 1, 4);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 7, 1, 1, 4);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        addEvents->setCentralWidget(centralwidget);
        menubar = new QMenuBar(addEvents);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 723, 26));
        addEvents->setMenuBar(menubar);
        statusbar = new QStatusBar(addEvents);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        addEvents->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEdit, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, pushButton);

        retranslateUi(addEvents);

        QMetaObject::connectSlotsByName(addEvents);
    } // setupUi

    void retranslateUi(QMainWindow *addEvents)
    {
        addEvents->setWindowTitle(QCoreApplication::translate("addEvents", "Add a new EVENT", nullptr));
        label_5->setText(QCoreApplication::translate("addEvents", "Start Date", nullptr));
        label->setText(QCoreApplication::translate("addEvents", "Reminder Time", nullptr));
        label_6->setText(QCoreApplication::translate("addEvents", "Event Name", nullptr));
        pushButton->setText(QCoreApplication::translate("addEvents", "Add Event", nullptr));
        label_2->setText(QCoreApplication::translate("addEvents", "Start Time", nullptr));
        label_3->setText(QCoreApplication::translate("addEvents", "Place", nullptr));
        label_4->setText(QCoreApplication::translate("addEvents", "End Date", nullptr));
        label_7->setText(QCoreApplication::translate("addEvents", "End Time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addEvents: public Ui_addEvents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENTS_H
