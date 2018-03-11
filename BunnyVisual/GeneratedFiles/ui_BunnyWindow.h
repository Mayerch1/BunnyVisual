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
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_text_2;
    QLabel *lblCycles;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_text;
    QLabel *blbBunnyCount;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_text_3;
    QLabel *lblInfectRate;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_text_4;
    QLabel *lblFeedRate;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_text_5;
    QLabel *lblMoveRate;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_text_6;
    QLabel *lblStarveRate;
    QWidget *widget5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLabel *lblFamineRate;
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
        layoutWidget2->setGeometry(QRect(1180, 340, 92, 26));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lbl_text_2 = new QLabel(layoutWidget2);
        lbl_text_2->setObjectName(QStringLiteral("lbl_text_2"));

        horizontalLayout_3->addWidget(lbl_text_2);

        lblCycles = new QLabel(layoutWidget2);
        lblCycles->setObjectName(QStringLiteral("lblCycles"));

        horizontalLayout_3->addWidget(lblCycles);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1180, 380, 92, 15));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        lbl_text = new QLabel(widget);
        lbl_text->setObjectName(QStringLiteral("lbl_text"));

        horizontalLayout_5->addWidget(lbl_text);

        blbBunnyCount = new QLabel(widget);
        blbBunnyCount->setObjectName(QStringLiteral("blbBunnyCount"));

        horizontalLayout_5->addWidget(blbBunnyCount);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(1180, 410, 81, 15));
        horizontalLayout_6 = new QHBoxLayout(widget1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        lbl_text_3 = new QLabel(widget1);
        lbl_text_3->setObjectName(QStringLiteral("lbl_text_3"));

        horizontalLayout_6->addWidget(lbl_text_3);

        lblInfectRate = new QLabel(widget1);
        lblInfectRate->setObjectName(QStringLiteral("lblInfectRate"));

        horizontalLayout_6->addWidget(lblInfectRate);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(1180, 440, 76, 15));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_text_4 = new QLabel(widget2);
        lbl_text_4->setObjectName(QStringLiteral("lbl_text_4"));

        horizontalLayout_2->addWidget(lbl_text_4);

        lblFeedRate = new QLabel(widget2);
        lblFeedRate->setObjectName(QStringLiteral("lblFeedRate"));

        horizontalLayout_2->addWidget(lblFeedRate);

        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(1180, 470, 78, 15));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lbl_text_5 = new QLabel(widget3);
        lbl_text_5->setObjectName(QStringLiteral("lbl_text_5"));

        horizontalLayout_4->addWidget(lbl_text_5);

        lblMoveRate = new QLabel(widget3);
        lblMoveRate->setObjectName(QStringLiteral("lblMoveRate"));

        horizontalLayout_4->addWidget(lblMoveRate);

        widget4 = new QWidget(centralWidget);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(1180, 500, 84, 15));
        horizontalLayout_7 = new QHBoxLayout(widget4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        lbl_text_6 = new QLabel(widget4);
        lbl_text_6->setObjectName(QStringLiteral("lbl_text_6"));

        horizontalLayout_7->addWidget(lbl_text_6);

        lblStarveRate = new QLabel(widget4);
        lblStarveRate->setObjectName(QStringLiteral("lblStarveRate"));

        horizontalLayout_7->addWidget(lblStarveRate);

        widget5 = new QWidget(centralWidget);
        widget5->setObjectName(QStringLiteral("widget5"));
        widget5->setGeometry(QRect(1180, 530, 105, 15));
        horizontalLayout_8 = new QHBoxLayout(widget5);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget5);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_8->addWidget(label);

        lblFamineRate = new QLabel(widget5);
        lblFamineRate->setObjectName(QStringLiteral("lblFamineRate"));

        horizontalLayout_8->addWidget(lblFamineRate);

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
        lbl_text_2->setText(QApplication::translate("BunnyWindowClass", "Cycle nr.:", nullptr));
        lblCycles->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
        lbl_text->setText(QApplication::translate("BunnyWindowClass", "Bunnies alive:", nullptr));
        blbBunnyCount->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
        lbl_text_3->setText(QApplication::translate("BunnyWindowClass", "Infect Rate", nullptr));
        lblInfectRate->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
        lbl_text_4->setText(QApplication::translate("BunnyWindowClass", "Feed Rate", nullptr));
        lblFeedRate->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
        lbl_text_5->setText(QApplication::translate("BunnyWindowClass", "Move Rate", nullptr));
        lblMoveRate->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
        lbl_text_6->setText(QApplication::translate("BunnyWindowClass", "Starve Rate", nullptr));
        lblStarveRate->setText(QApplication::translate("BunnyWindowClass", "N/A", nullptr));
        label->setText(QApplication::translate("BunnyWindowClass", "Mystery Number", nullptr));
        lblFamineRate->setText(QApplication::translate("BunnyWindowClass", "167", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BunnyWindowClass: public Ui_BunnyWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUNNYWINDOW_H
