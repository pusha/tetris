/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "renderarea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    RenderArea *renderArea;
    QGridLayout *gridLayout_2;
    QPushButton *btnCycloid;
    QPushButton *btnHuygens;
    QPushButton *btnAstroid;
    QPushButton *btnHypo;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(359, 342);
        MainWindow->setMinimumSize(QSize(300, 300));
        MainWindow->setMaximumSize(QSize(500, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(22, 22, 321, 291));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        renderArea = new RenderArea(layoutWidget);
        renderArea->setObjectName(QString::fromUtf8("renderArea"));

        gridLayout->addWidget(renderArea, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnCycloid = new QPushButton(layoutWidget);
        btnCycloid->setObjectName(QString::fromUtf8("btnCycloid"));

        gridLayout_2->addWidget(btnCycloid, 1, 0, 1, 1);

        btnHuygens = new QPushButton(layoutWidget);
        btnHuygens->setObjectName(QString::fromUtf8("btnHuygens"));

        gridLayout_2->addWidget(btnHuygens, 2, 0, 1, 1);

        btnAstroid = new QPushButton(layoutWidget);
        btnAstroid->setObjectName(QString::fromUtf8("btnAstroid"));

        gridLayout_2->addWidget(btnAstroid, 0, 0, 1, 1);

        btnHypo = new QPushButton(layoutWidget);
        btnHypo->setObjectName(QString::fromUtf8("btnHypo"));

        gridLayout_2->addWidget(btnHypo, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(btnAstroid, btnCycloid);
        QWidget::setTabOrder(btnCycloid, btnHuygens);
        QWidget::setTabOrder(btnHuygens, btnHypo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnCycloid->setText(QApplication::translate("MainWindow", "Cycloid", nullptr));
        btnHuygens->setText(QApplication::translate("MainWindow", "Huygens", nullptr));
        btnAstroid->setText(QApplication::translate("MainWindow", "Astroid", nullptr));
        btnHypo->setText(QApplication::translate("MainWindow", "Hypo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
