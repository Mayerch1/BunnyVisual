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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BunnyWindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_11;
    QFrame *RenderArea;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listMsg;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btnDetails;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStart;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSettings;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_text_2;
    QLabel *lblCycles;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_text;
    QLabel *blbBunnyCount;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_text_3;
    QLabel *lblInfectRate;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_text_4;
    QLabel *lblFeedRate;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_text_5;
    QLabel *lblMoveRate;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_text_6;
    QLabel *lblStarveRate;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLabel *lblFamineRate;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *boxSnapshot;
    QPushButton *btnSnapshot;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *BunnyWindowClass)
    {
        if (BunnyWindowClass->objectName().isEmpty())
            BunnyWindowClass->setObjectName(QStringLiteral("BunnyWindowClass"));
        BunnyWindowClass->resize(1174, 749);
        BunnyWindowClass->setMinimumSize(QSize(836, 400));
        BunnyWindowClass->setMaximumSize(QSize(16777215, 16777215));
        BunnyWindowClass->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(BunnyWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_11 = new QHBoxLayout(centralWidget);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        RenderArea = new QFrame(centralWidget);
        RenderArea->setObjectName(QStringLiteral("RenderArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RenderArea->sizePolicy().hasHeightForWidth());
        RenderArea->setSizePolicy(sizePolicy);
        RenderArea->setMinimumSize(QSize(100, 100));
        RenderArea->setFrameShape(QFrame::StyledPanel);
        RenderArea->setFrameShadow(QFrame::Raised);

        horizontalLayout_11->addWidget(RenderArea);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listMsg = new QListWidget(centralWidget);
        listMsg->setObjectName(QStringLiteral("listMsg"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listMsg->sizePolicy().hasHeightForWidth());
        listMsg->setSizePolicy(sizePolicy1);
        listMsg->setFocusPolicy(Qt::NoFocus);
        listMsg->setUniformItemSizes(true);

        verticalLayout->addWidget(listMsg);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);

        btnDetails = new QPushButton(centralWidget);
        btnDetails->setObjectName(QStringLiteral("btnDetails"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnDetails->sizePolicy().hasHeightForWidth());
        btnDetails->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(btnDetails);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        sizePolicy2.setHeightForWidth(btnStart->sizePolicy().hasHeightForWidth());
        btnStart->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(btnStart);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSettings = new QPushButton(centralWidget);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        sizePolicy2.setHeightForWidth(btnSettings->sizePolicy().hasHeightForWidth());
        btnSettings->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(btnSettings);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbl_text_2 = new QLabel(centralWidget);
        lbl_text_2->setObjectName(QStringLiteral("lbl_text_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lbl_text_2->sizePolicy().hasHeightForWidth());
        lbl_text_2->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(lbl_text_2);

        lblCycles = new QLabel(centralWidget);
        lblCycles->setObjectName(QStringLiteral("lblCycles"));
        sizePolicy3.setHeightForWidth(lblCycles->sizePolicy().hasHeightForWidth());
        lblCycles->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(lblCycles);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lbl_text = new QLabel(centralWidget);
        lbl_text->setObjectName(QStringLiteral("lbl_text"));
        sizePolicy3.setHeightForWidth(lbl_text->sizePolicy().hasHeightForWidth());
        lbl_text->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(lbl_text);

        blbBunnyCount = new QLabel(centralWidget);
        blbBunnyCount->setObjectName(QStringLiteral("blbBunnyCount"));
        sizePolicy3.setHeightForWidth(blbBunnyCount->sizePolicy().hasHeightForWidth());
        blbBunnyCount->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(blbBunnyCount);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lbl_text_3 = new QLabel(centralWidget);
        lbl_text_3->setObjectName(QStringLiteral("lbl_text_3"));
        sizePolicy3.setHeightForWidth(lbl_text_3->sizePolicy().hasHeightForWidth());
        lbl_text_3->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(lbl_text_3);

        lblInfectRate = new QLabel(centralWidget);
        lblInfectRate->setObjectName(QStringLiteral("lblInfectRate"));
        sizePolicy3.setHeightForWidth(lblInfectRate->sizePolicy().hasHeightForWidth());
        lblInfectRate->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(lblInfectRate);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbl_text_4 = new QLabel(centralWidget);
        lbl_text_4->setObjectName(QStringLiteral("lbl_text_4"));
        sizePolicy3.setHeightForWidth(lbl_text_4->sizePolicy().hasHeightForWidth());
        lbl_text_4->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(lbl_text_4);

        lblFeedRate = new QLabel(centralWidget);
        lblFeedRate->setObjectName(QStringLiteral("lblFeedRate"));
        sizePolicy3.setHeightForWidth(lblFeedRate->sizePolicy().hasHeightForWidth());
        lblFeedRate->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(lblFeedRate);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbl_text_5 = new QLabel(centralWidget);
        lbl_text_5->setObjectName(QStringLiteral("lbl_text_5"));
        sizePolicy3.setHeightForWidth(lbl_text_5->sizePolicy().hasHeightForWidth());
        lbl_text_5->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(lbl_text_5);

        lblMoveRate = new QLabel(centralWidget);
        lblMoveRate->setObjectName(QStringLiteral("lblMoveRate"));
        sizePolicy3.setHeightForWidth(lblMoveRate->sizePolicy().hasHeightForWidth());
        lblMoveRate->setSizePolicy(sizePolicy3);

        horizontalLayout_7->addWidget(lblMoveRate);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lbl_text_6 = new QLabel(centralWidget);
        lbl_text_6->setObjectName(QStringLiteral("lbl_text_6"));
        sizePolicy3.setHeightForWidth(lbl_text_6->sizePolicy().hasHeightForWidth());
        lbl_text_6->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(lbl_text_6);

        lblStarveRate = new QLabel(centralWidget);
        lblStarveRate->setObjectName(QStringLiteral("lblStarveRate"));
        sizePolicy3.setHeightForWidth(lblStarveRate->sizePolicy().hasHeightForWidth());
        lblStarveRate->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(lblStarveRate);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(label);

        lblFamineRate = new QLabel(centralWidget);
        lblFamineRate->setObjectName(QStringLiteral("lblFamineRate"));
        sizePolicy3.setHeightForWidth(lblFamineRate->sizePolicy().hasHeightForWidth());
        lblFamineRate->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(lblFamineRate);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        boxSnapshot = new QLineEdit(centralWidget);
        boxSnapshot->setObjectName(QStringLiteral("boxSnapshot"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(boxSnapshot->sizePolicy().hasHeightForWidth());
        boxSnapshot->setSizePolicy(sizePolicy4);

        horizontalLayout_10->addWidget(boxSnapshot);

        btnSnapshot = new QPushButton(centralWidget);
        btnSnapshot->setObjectName(QStringLiteral("btnSnapshot"));
        sizePolicy4.setHeightForWidth(btnSnapshot->sizePolicy().hasHeightForWidth());
        btnSnapshot->setSizePolicy(sizePolicy4);

        horizontalLayout_10->addWidget(btnSnapshot);


        verticalLayout_2->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_11->addLayout(verticalLayout_2);

        BunnyWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BunnyWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1174, 21));
        BunnyWindowClass->setMenuBar(menuBar);

        retranslateUi(BunnyWindowClass);

        QMetaObject::connectSlotsByName(BunnyWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *BunnyWindowClass)
    {
        BunnyWindowClass->setWindowTitle(QApplication::translate("BunnyWindowClass", "Bunny.exe", nullptr));
        btnDetails->setText(QApplication::translate("BunnyWindowClass", "Details", nullptr));
        btnStart->setText(QApplication::translate("BunnyWindowClass", "Computer says no", nullptr));
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
        lblFamineRate->setText(QApplication::translate("BunnyWindowClass", "0", nullptr));
        boxSnapshot->setText(QApplication::translate("BunnyWindowClass", "Snapshot_001.save", nullptr));
        btnSnapshot->setText(QApplication::translate("BunnyWindowClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BunnyWindowClass: public Ui_BunnyWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUNNYWINDOW_H
