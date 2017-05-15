/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "src/scribblearea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QProgressBar *progressBar;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    ScribbleArea *widgetDraw;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonOk;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(526, 320);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_3->addWidget(progressBar, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(groupBox_2);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout_3->addWidget(graphicsView, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widgetDraw = new ScribbleArea(groupBox);
        widgetDraw->setObjectName(QString::fromUtf8("widgetDraw"));

        gridLayout_2->addWidget(widgetDraw, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEdit, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        horizontalLayout->addWidget(pushButtonClear);

        pushButtonOk = new QPushButton(centralwidget);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));

        horizontalLayout->addWidget(pushButtonOk);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 526, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Processing", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Draw a number", 0));
        lineEdit->setInputMask(QApplication::translate("MainWindow", "0", 0));
        pushButtonClear->setText(QApplication::translate("MainWindow", "Clear", 0));
        pushButtonOk->setText(QApplication::translate("MainWindow", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
