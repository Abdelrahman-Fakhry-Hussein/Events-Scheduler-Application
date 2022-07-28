/********************************************************************************
** Form generated from reading UI file 'EventScheduler.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTSCHEDULER_H
#define UI_EVENTSCHEDULER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventSchedulerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EventSchedulerClass)
    {
        if (EventSchedulerClass->objectName().isEmpty())
            EventSchedulerClass->setObjectName(QString::fromUtf8("EventSchedulerClass"));
        EventSchedulerClass->resize(600, 400);
        menuBar = new QMenuBar(EventSchedulerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        EventSchedulerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EventSchedulerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        EventSchedulerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(EventSchedulerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        EventSchedulerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(EventSchedulerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EventSchedulerClass->setStatusBar(statusBar);

        retranslateUi(EventSchedulerClass);

        QMetaObject::connectSlotsByName(EventSchedulerClass);
    } // setupUi

    void retranslateUi(QMainWindow *EventSchedulerClass)
    {
        EventSchedulerClass->setWindowTitle(QCoreApplication::translate("EventSchedulerClass", "EventScheduler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventSchedulerClass: public Ui_EventSchedulerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTSCHEDULER_H
