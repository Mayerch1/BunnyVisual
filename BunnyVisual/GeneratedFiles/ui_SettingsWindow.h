/********************************************************************************
** Form generated from reading UI file 'SettingsWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *boxGridX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *boxGridY;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QCheckBox *checkLoad;
    QLineEdit *boxLoad;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QCheckBox *checkSave;
    QLineEdit *boxSave;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QCheckBox *checkLog;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QCheckBox *checkNoLog;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QSpinBox *boxStartBunnies;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *boxFoodCount;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QSpinBox *boxFoodDuration;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpinBox *boxMaxColonySize;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QSpinBox *boxInfectionProb;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QSpinBox *boxSleepTime;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QSpinBox *boxMaxHunger;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnExit;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(549, 422);
        horizontalLayout_15 = new QHBoxLayout(SettingsWindow);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SettingsWindow);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        boxGridX = new QSpinBox(SettingsWindow);
        boxGridX->setObjectName(QStringLiteral("boxGridX"));
        boxGridX->setMinimum(1);
        boxGridX->setMaximum(2147483647);

        horizontalLayout->addWidget(boxGridX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(SettingsWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        boxGridY = new QSpinBox(SettingsWindow);
        boxGridY->setObjectName(QStringLiteral("boxGridY"));
        boxGridY->setMinimum(1);
        boxGridY->setMaximum(2147483647);

        horizontalLayout_2->addWidget(boxGridY);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(SettingsWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        checkLoad = new QCheckBox(SettingsWindow);
        checkLoad->setObjectName(QStringLiteral("checkLoad"));

        horizontalLayout_4->addWidget(checkLoad);

        boxLoad = new QLineEdit(SettingsWindow);
        boxLoad->setObjectName(QStringLiteral("boxLoad"));
        boxLoad->setToolTipDuration(5);

        horizontalLayout_4->addWidget(boxLoad);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(SettingsWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setToolTipDuration(2);

        horizontalLayout_3->addWidget(label_4);

        checkSave = new QCheckBox(SettingsWindow);
        checkSave->setObjectName(QStringLiteral("checkSave"));

        horizontalLayout_3->addWidget(checkSave);

        boxSave = new QLineEdit(SettingsWindow);
        boxSave->setObjectName(QStringLiteral("boxSave"));
        boxSave->setToolTipDuration(5);

        horizontalLayout_3->addWidget(boxSave);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(SettingsWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        checkLog = new QCheckBox(SettingsWindow);
        checkLog->setObjectName(QStringLiteral("checkLog"));

        horizontalLayout_6->addWidget(checkLog);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(SettingsWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        checkNoLog = new QCheckBox(SettingsWindow);
        checkNoLog->setObjectName(QStringLiteral("checkNoLog"));

        horizontalLayout_5->addWidget(checkNoLog);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(SettingsWindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_10->addWidget(label_10);

        boxStartBunnies = new QSpinBox(SettingsWindow);
        boxStartBunnies->setObjectName(QStringLiteral("boxStartBunnies"));
        boxStartBunnies->setMinimum(1);
        boxStartBunnies->setMaximum(2147483647);

        horizontalLayout_10->addWidget(boxStartBunnies);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(SettingsWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);

        boxFoodCount = new QSpinBox(SettingsWindow);
        boxFoodCount->setObjectName(QStringLiteral("boxFoodCount"));
        boxFoodCount->setMaximum(2147483647);

        horizontalLayout_7->addWidget(boxFoodCount);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(SettingsWindow);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        horizontalLayout_12->addWidget(label_12);

        boxFoodDuration = new QSpinBox(SettingsWindow);
        boxFoodDuration->setObjectName(QStringLiteral("boxFoodDuration"));
        boxFoodDuration->setMaximum(2147483647);

        horizontalLayout_12->addWidget(boxFoodDuration);


        verticalLayout_4->addLayout(horizontalLayout_12);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);


        horizontalLayout_15->addLayout(verticalLayout_6);

        horizontalSpacer = new QSpacerItem(141, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(SettingsWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_8->addWidget(label_8);

        boxMaxColonySize = new QSpinBox(SettingsWindow);
        boxMaxColonySize->setObjectName(QStringLiteral("boxMaxColonySize"));
        boxMaxColonySize->setMaximum(2147483647);

        horizontalLayout_8->addWidget(boxMaxColonySize);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(SettingsWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_9->addWidget(label_9);

        boxInfectionProb = new QSpinBox(SettingsWindow);
        boxInfectionProb->setObjectName(QStringLiteral("boxInfectionProb"));
        boxInfectionProb->setMaximum(100);

        horizontalLayout_9->addWidget(boxInfectionProb);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(SettingsWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_11->addWidget(label_11);

        boxSleepTime = new QSpinBox(SettingsWindow);
        boxSleepTime->setObjectName(QStringLiteral("boxSleepTime"));
        boxSleepTime->setMinimum(125);
        boxSleepTime->setMaximum(2147483647);

        horizontalLayout_11->addWidget(boxSleepTime);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_13 = new QLabel(SettingsWindow);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        horizontalLayout_13->addWidget(label_13);

        boxMaxHunger = new QSpinBox(SettingsWindow);
        boxMaxHunger->setObjectName(QStringLiteral("boxMaxHunger"));
        boxMaxHunger->setMaximum(2147483647);

        horizontalLayout_13->addWidget(boxMaxHunger);


        verticalLayout_5->addLayout(horizontalLayout_13);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 188, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);

        btnExit = new QPushButton(SettingsWindow);
        btnExit->setObjectName(QStringLiteral("btnExit"));

        horizontalLayout_14->addWidget(btnExit);


        verticalLayout_7->addLayout(horizontalLayout_14);


        horizontalLayout_15->addLayout(verticalLayout_7);

        QWidget::setTabOrder(boxGridX, boxGridY);
        QWidget::setTabOrder(boxGridY, checkLoad);
        QWidget::setTabOrder(checkLoad, boxLoad);
        QWidget::setTabOrder(boxLoad, checkSave);
        QWidget::setTabOrder(checkSave, boxSave);
        QWidget::setTabOrder(boxSave, checkLog);
        QWidget::setTabOrder(checkLog, checkNoLog);
        QWidget::setTabOrder(checkNoLog, boxFoodCount);
        QWidget::setTabOrder(boxFoodCount, boxMaxColonySize);
        QWidget::setTabOrder(boxMaxColonySize, boxInfectionProb);
        QWidget::setTabOrder(boxInfectionProb, boxStartBunnies);
        QWidget::setTabOrder(boxStartBunnies, boxSleepTime);
        QWidget::setTabOrder(boxSleepTime, boxFoodDuration);
        QWidget::setTabOrder(boxFoodDuration, boxMaxHunger);
        QWidget::setTabOrder(boxMaxHunger, btnExit);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "SettingsWindow", nullptr));
        label->setText(QApplication::translate("SettingsWindow", "gridX:", nullptr));
        label_2->setText(QApplication::translate("SettingsWindow", "gridY:", nullptr));
        label_3->setText(QApplication::translate("SettingsWindow", "load", nullptr));
        checkLoad->setText(QString());
#ifndef QT_NO_TOOLTIP
        boxLoad->setToolTip(QApplication::translate("SettingsWindow", "<Return>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("SettingsWindow", "continuos save", nullptr));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("SettingsWindow", "save", nullptr));
        checkSave->setText(QString());
#ifndef QT_NO_TOOLTIP
        boxSave->setToolTip(QApplication::translate("SettingsWindow", "<Return>", nullptr));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("SettingsWindow", "log", nullptr));
        checkLog->setText(QString());
        label_6->setText(QApplication::translate("SettingsWindow", "noLog", nullptr));
        checkNoLog->setText(QString());
        label_10->setText(QApplication::translate("SettingsWindow", "start_Bunnies", nullptr));
        label_7->setText(QApplication::translate("SettingsWindow", "foodCount", nullptr));
        label_12->setText(QApplication::translate("SettingsWindow", "food_duration", nullptr));
        label_8->setText(QApplication::translate("SettingsWindow", "max_colony_size", nullptr));
        label_9->setText(QApplication::translate("SettingsWindow", "infection_prob", nullptr));
        boxInfectionProb->setSuffix(QApplication::translate("SettingsWindow", "%", nullptr));
        boxInfectionProb->setPrefix(QString());
        label_11->setText(QApplication::translate("SettingsWindow", "sleep_time", nullptr));
        boxSleepTime->setSuffix(QApplication::translate("SettingsWindow", " ms", nullptr));
        label_13->setText(QApplication::translate("SettingsWindow", "maxHunger", nullptr));
        btnExit->setText(QApplication::translate("SettingsWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
