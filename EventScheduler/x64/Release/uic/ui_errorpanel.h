/********************************************************************************
** Form generated from reading UI file 'errorpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORPANEL_H
#define UI_ERRORPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_errorPanel
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *errorPanel)
    {
        if (errorPanel->objectName().isEmpty())
            errorPanel->setObjectName(QString::fromUtf8("errorPanel"));
        errorPanel->resize(800, 285);
        centralwidget = new QWidget(errorPanel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        errorPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(errorPanel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        errorPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(errorPanel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        errorPanel->setStatusBar(statusbar);

        retranslateUi(errorPanel);

        QMetaObject::connectSlotsByName(errorPanel);
    } // setupUi

    void retranslateUi(QMainWindow *errorPanel)
    {
        errorPanel->setWindowTitle(QCoreApplication::translate("errorPanel", "errorPanel", nullptr));
        label->setText(QCoreApplication::translate("errorPanel", "TEXT", nullptr));
        pushButton->setText(QCoreApplication::translate("errorPanel", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class errorPanel: public Ui_errorPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORPANEL_H
