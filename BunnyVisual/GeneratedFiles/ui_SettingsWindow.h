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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QPushButton *btnExit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *boxGridX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *boxGridY;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QCheckBox *checkLoad;
    QLineEdit *boxLoad;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QCheckBox *checkSave;
    QLineEdit *boxSave;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QCheckBox *checkLog;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QCheckBox *checkNoLog;
    QWidget *widget3;
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
    QWidget *widget4;
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

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QStringLiteral("SettingsWindow"));
        SettingsWindow->resize(549, 422);
        btnExit = new QPushButton(SettingsWindow);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        btnExit->setGeometry(QRect(450, 390, 75, 23));
        widget = new QWidget(SettingsWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 127, 52));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        boxGridX = new QSpinBox(widget);
        boxGridX->setObjectName(QStringLiteral("boxGridX"));
        boxGridX->setMinimum(1);
        boxGridX->setMaximum(2147483647);

        horizontalLayout->addWidget(boxGridX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        boxGridY = new QSpinBox(widget);
        boxGridY->setObjectName(QStringLiteral("boxGridY"));
        boxGridY->setMinimum(1);
        boxGridY->setMaximum(2147483647);

        horizontalLayout_2->addWidget(boxGridY);


        verticalLayout->addLayout(horizontalLayout_2);

        widget1 = new QWidget(SettingsWindow);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 110, 186, 52));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        checkLoad = new QCheckBox(widget1);
        checkLoad->setObjectName(QStringLiteral("checkLoad"));

        horizontalLayout_4->addWidget(checkLoad);

        boxLoad = new QLineEdit(widget1);
        boxLoad->setObjectName(QStringLiteral("boxLoad"));
        boxLoad->setToolTipDuration(5);

        horizontalLayout_4->addWidget(boxLoad);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        checkSave = new QCheckBox(widget1);
        checkSave->setObjectName(QStringLiteral("checkSave"));

        horizontalLayout_3->addWidget(checkSave);

        boxSave = new QLineEdit(widget1);
        boxSave->setObjectName(QStringLiteral("boxSave"));
        boxSave->setToolTipDuration(5);

        horizontalLayout_3->addWidget(boxSave);


        verticalLayout_2->addLayout(horizontalLayout_3);

        widget2 = new QWidget(SettingsWindow);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(20, 180, 57, 40));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(widget2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        checkLog = new QCheckBox(widget2);
        checkLog->setObjectName(QStringLiteral("checkLog"));

        horizontalLayout_6->addWidget(checkLog);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(widget2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        checkNoLog = new QCheckBox(widget2);
        checkNoLog->setObjectName(QStringLiteral("checkNoLog"));

        horizontalLayout_5->addWidget(checkNoLog);


        verticalLayout_3->addLayout(horizontalLayout_5);

        widget3 = new QWidget(SettingsWindow);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(20, 240, 172, 80));
        verticalLayout_4 = new QVBoxLayout(widget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(widget3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_10->addWidget(label_10);

        boxStartBunnies = new QSpinBox(widget3);
        boxStartBunnies->setObjectName(QStringLiteral("boxStartBunnies"));
        boxStartBunnies->setMinimum(1);
        boxStartBunnies->setMaximum(2147483647);

        horizontalLayout_10->addWidget(boxStartBunnies);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(widget3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_7->addWidget(label_7);

        boxFoodCount = new QSpinBox(widget3);
        boxFoodCount->setObjectName(QStringLiteral("boxFoodCount"));
        boxFoodCount->setMaximum(2147483647);

        horizontalLayout_7->addWidget(boxFoodCount);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(widget3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        horizontalLayout_12->addWidget(label_12);

        boxFoodDuration = new QSpinBox(widget3);
        boxFoodDuration->setObjectName(QStringLiteral("boxFoodDuration"));
        boxFoodDuration->setMaximum(2147483647);

        horizontalLayout_12->addWidget(boxFoodDuration);


        verticalLayout_4->addLayout(horizontalLayout_12);

        widget4 = new QWidget(SettingsWindow);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(350, 10, 185, 108));
        verticalLayout_5 = new QVBoxLayout(widget4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(widget4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_8->addWidget(label_8);

        boxMaxColonySize = new QSpinBox(widget4);
        boxMaxColonySize->setObjectName(QStringLiteral("boxMaxColonySize"));
        boxMaxColonySize->setMaximum(2147483647);

        horizontalLayout_8->addWidget(boxMaxColonySize);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(widget4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_9->addWidget(label_9);

        boxInfectionProb = new QSpinBox(widget4);
        boxInfectionProb->setObjectName(QStringLiteral("boxInfectionProb"));
        boxInfectionProb->setMaximum(100);

        horizontalLayout_9->addWidget(boxInfectionProb);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(widget4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_11->addWidget(label_11);

        boxSleepTime = new QSpinBox(widget4);
        boxSleepTime->setObjectName(QStringLiteral("boxSleepTime"));
        boxSleepTime->setMinimum(100);
        boxSleepTime->setMaximum(2147483647);

        horizontalLayout_11->addWidget(boxSleepTime);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_13 = new QLabel(widget4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        horizontalLayout_13->addWidget(label_13);

        boxMaxHunger = new QSpinBox(widget4);
        boxMaxHunger->setObjectName(QStringLiteral("boxMaxHunger"));
        boxMaxHunger->setMaximum(2147483647);

        horizontalLayout_13->addWidget(boxMaxHunger);


        verticalLayout_5->addLayout(horizontalLayout_13);

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
        btnExit->setText(QApplication::translate("SettingsWindow", "Exit", nullptr));
        label->setText(QApplication::translate("SettingsWindow", "gridX:", nullptr));
        label_2->setText(QApplication::translate("SettingsWindow", "gridY:", nullptr));
        label_3->setText(QApplication::translate("SettingsWindow", "load", nullptr));
        checkLoad->setText(QString());
#ifndef QT_NO_TOOLTIP
        boxLoad->setToolTip(QApplication::translate("SettingsWindow", "<Return>", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
