/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_view
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QRadioButton *cpu_agent;
    QRadioButton *memory_agent;
    QRadioButton *network_agent;
    QRadioButton *dop_agent;
    QLineEdit *timer;
    QPushButton *start;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *view)
    {
        if (view->objectName().isEmpty())
            view->setObjectName(QString::fromUtf8("view"));
        view->resize(1310, 832);
        centralwidget = new QWidget(view);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 1301, 601));
        textBrowser->setMouseTracking(false);
        textBrowser->setLineWidth(2);
        textBrowser->setReadOnly(false);
        cpu_agent = new QRadioButton(centralwidget);
        cpu_agent->setObjectName(QString::fromUtf8("cpu_agent"));
        cpu_agent->setGeometry(QRect(60, 640, 141, 41));
        memory_agent = new QRadioButton(centralwidget);
        memory_agent->setObjectName(QString::fromUtf8("memory_agent"));
        memory_agent->setGeometry(QRect(250, 640, 141, 41));
        network_agent = new QRadioButton(centralwidget);
        network_agent->setObjectName(QString::fromUtf8("network_agent"));
        network_agent->setGeometry(QRect(450, 640, 141, 41));
        dop_agent = new QRadioButton(centralwidget);
        dop_agent->setObjectName(QString::fromUtf8("dop_agent"));
        dop_agent->setGeometry(QRect(630, 640, 141, 41));
        timer = new QLineEdit(centralwidget);
        timer->setObjectName(QString::fromUtf8("timer"));
        timer->setGeometry(QRect(840, 650, 113, 24));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(1090, 650, 131, 41));
        view->setCentralWidget(centralwidget);
        menubar = new QMenuBar(view);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1310, 21));
        view->setMenuBar(menubar);
        statusbar = new QStatusBar(view);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        view->setStatusBar(statusbar);

        retranslateUi(view);

        QMetaObject::connectSlotsByName(view);
    } // setupUi

    void retranslateUi(QMainWindow *view)
    {
        view->setWindowTitle(QCoreApplication::translate("view", "view", nullptr));
        cpu_agent->setText(QCoreApplication::translate("view", "RadioButton", nullptr));
        memory_agent->setText(QCoreApplication::translate("view", "RadioButton", nullptr));
        network_agent->setText(QCoreApplication::translate("view", "RadioButton", nullptr));
        dop_agent->setText(QCoreApplication::translate("view", "RadioButton", nullptr));
        start->setText(QCoreApplication::translate("view", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class view: public Ui_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
