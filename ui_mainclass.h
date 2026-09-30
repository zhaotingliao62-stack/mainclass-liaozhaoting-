/********************************************************************************
** Form generated from reading UI file 'mainclass.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCLASS_H
#define UI_MAINCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainClass
{
public:
    QWidget *centralwidget;
    QCustomPlot *Grapf_qcustomplot;
    QGroupBox *SignalParams_group;
    QLabel *SampleRate_label;
    QLineEdit *SampleRate_edit;
    QLabel *ChannelsNum_label;
    QLineEdit *ChannelsCount_edit;
    QPushButton *OpenSignal_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainClass)
    {
        if (MainClass->objectName().isEmpty())
            MainClass->setObjectName(QString::fromUtf8("MainClass"));
        MainClass->resize(800, 600);
        centralwidget = new QWidget(MainClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Grapf_qcustomplot = new QCustomPlot(centralwidget);
        Grapf_qcustomplot->setObjectName(QString::fromUtf8("Grapf_qcustomplot"));
        Grapf_qcustomplot->setGeometry(QRect(170, 10, 620, 540));
        SignalParams_group = new QGroupBox(centralwidget);
        SignalParams_group->setObjectName(QString::fromUtf8("SignalParams_group"));
        SignalParams_group->setGeometry(QRect(10, 20, 150, 100));
        SampleRate_label = new QLabel(SignalParams_group);
        SampleRate_label->setObjectName(QString::fromUtf8("SampleRate_label"));
        SampleRate_label->setGeometry(QRect(10, 25, 75, 20));
        SampleRate_edit = new QLineEdit(SignalParams_group);
        SampleRate_edit->setObjectName(QString::fromUtf8("SampleRate_edit"));
        SampleRate_edit->setGeometry(QRect(85, 25, 55, 20));
        ChannelsNum_label = new QLabel(SignalParams_group);
        ChannelsNum_label->setObjectName(QString::fromUtf8("ChannelsNum_label"));
        ChannelsNum_label->setGeometry(QRect(10, 60, 90, 20));
        ChannelsCount_edit = new QLineEdit(SignalParams_group);
        ChannelsCount_edit->setObjectName(QString::fromUtf8("ChannelsCount_edit"));
        ChannelsCount_edit->setGeometry(QRect(105, 60, 35, 20));
        OpenSignal_button = new QPushButton(centralwidget);
        OpenSignal_button->setObjectName(QString::fromUtf8("OpenSignal_button"));
        OpenSignal_button->setGeometry(QRect(10, 130, 150, 30));
        MainClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainClass->setMenuBar(menubar);
        statusbar = new QStatusBar(MainClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainClass->setStatusBar(statusbar);

        retranslateUi(MainClass);

        QMetaObject::connectSlotsByName(MainClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainClass)
    {
        MainClass->setWindowTitle(QCoreApplication::translate("MainClass", "MainClass", nullptr));
        SignalParams_group->setTitle(QCoreApplication::translate("MainClass", "Signal params", nullptr));
        SampleRate_label->setText(QCoreApplication::translate("MainClass", "SampleRate =", nullptr));
        SampleRate_edit->setText(QCoreApplication::translate("MainClass", "2000", nullptr));
        ChannelsNum_label->setText(QCoreApplication::translate("MainClass", "Channels count =", nullptr));
        ChannelsCount_edit->setText(QCoreApplication::translate("MainClass", "1", nullptr));
        OpenSignal_button->setText(QCoreApplication::translate("MainClass", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainClass: public Ui_MainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLASS_H
