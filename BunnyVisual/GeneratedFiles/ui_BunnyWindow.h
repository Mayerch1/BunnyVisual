/********************************************************************************
** Form generated from reading UI file 'BunnyWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUNNYWINDOW_H
#define UI_BUNNYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BunnyWindowClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStart;
    QWidget *RenderArea;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QListWidget *listMsg;
    QPushButton *btnDetails;
    QPushButton *btnSettings;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_text;
    QLabel *blbBunnyCount;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_text_2;
    QLabel *lblCycles;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_text_3;
    QLabel *lblInfects;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BunnyWindowClass)
    {
        if (BunnyWindowClass->objectName().isEmpty())
            BunnyWindowClass->setObjectName(QStringLiteral("BunnyWindowClass"));
        BunnyWindowClass->resize(1400, 900);
        BunnyWindowClass->setMinimumSize(QSize(1400, 900));
        BunnyWindowClass->setMaximumSize(QSize(1400, 900));
        BunnyWindowClass->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(BunnyWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(1180, 260, 211, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnStart = new QPushButton(layoutWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        horizontalLayout->addWidget(btnStart);

        RenderArea = new QWidget(centralWidget);
        RenderArea->setObjectName(QStringLiteral("RenderArea"));
        RenderArea->setGeometry(QRect(2, 11, 1161, 831));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1170, 10, 221, 231));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listMsg = new QListWidget(layoutWidget1);
        listMsg->setObjectName(QStringLiteral("listMsg"));
        listMsg->setFocusPolicy(Qt::NoFocus);
        listMsg->setUniformItemSizes(true);

        verticalLayout->addWidget(listMsg);

        btnDetails = new QPushButton(layoutWidget1);
        btnDetails->setObjectName(QStringLiteral("btnDetails"));

        verticalLayout->addWidget(btnDetails);

        btnSettings = new QPushButton(centralWidget);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        btnSettings->setGeometry(QRect(1180, 290, 211, 23));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(1180, 360, 92, 15));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_text = new QLabel(layoutWidget2);
        lbl_text->setObjectName(QStringLiteral("lbl_text"));

        horizontalLayout_2->addWidget(lbl_text);

        blbBunnyCount = new QLabel(layoutWidget2);
        blbBunnyCount->setObjectName(QStringLiteral("blbBunnyCount"));

        horizontalLayout_2->addWidget(blbBunnyCount);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(1180, 330, 73, 15));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lbl_text_2 = new QLabel(layoutWidget3);
        lbl_text_2->setObjectName(QStringLiteral("lbl_text_2"));

        horizontalLayout_3->addWidget(lbl_text_2);

        lblCycles = new QLabel(layoutWidget3);
        lblCycles->setObjectName(QStringLiteral("lblCycles"));

        horizontalLayout_3->addWidget(lblCycles);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(1180, 390, 114, 15));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lbl_text_3 = new QLabel(layoutWidget4);
        lbl_text_3->setObjectName(QStringLiteral("lbl_text_3"));

        horizontalLayout_4->addWidget(lbl_text_3);

        lblInfects = new QLabel(layoutWidget4);
        lblInfects->setObjectName(QStringLiteral("lblInfects"));

        horizontalLayout_4->addWidget(lblInfects);

        BunnyWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BunnyWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1400, 21));
        BunnyWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BunnyWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BunnyWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BunnyWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BunnyWindowClass->setStatusBar(statusBar);

        retranslateUi(BunnyWindowClass);

        QMetaObject::connectSlotsByName(BunnyWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *BunnyWindowClass)
    {
        BunnyWindowClass->setWindowTitle(QApplication::translate("BunnyWindowClass", "Bunny.exe", nullptr));
        btnStart->setText(QApplication::translate("BunnyWindowClass", "Start", nullptr));
        btnDetails->setText(QApplication::translate("BunnyWindowClass", "Details", nullptr));
        btnSettings->setText(QApplication::translate("BunnyWindowClass", "Settings", nullptr));
        lbl_text->setText(QApplication::translate("BunnyWindowClass", "Bunnies alive:", nullptr));
        blbBunnyCount->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
        lbl_text_2->setText(QApplication::translate("BunnyWindowClass", "Cycle nr.:", nullptr));
        lblCycles->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
        lbl_text_3->setText(QApplication::translate("BunnyWindowClass", "Infect Rate", nullptr));
        lblInfects->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BunnyWindowClass: public Ui_BunnyWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUNNYWINDOW_H
