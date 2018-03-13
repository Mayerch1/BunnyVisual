#pragma once

#include <QWidget>
#include "ui_SettingsWindow.h"
#include "Core/imp_header.h"

class SettingsWindow : public QWidget
{
	Q_OBJECT

public:
	SettingsWindow(QWidget *parent = Q_NULLPTR);
	~SettingsWindow();

	Ui::SettingsWindow ui;
	PargList setStruct;

	void get_args(PargList argStruct);

	private slots:
	void on_btnExit_clicked();
	void on_boxGridX_valueChanged(int i);
	void on_boxGridY_valueChanged(int i);

	void on_boxFoodCount_valueChanged(int i);
	void on_boxMaxColonySize_valueChanged(int i);
	void on_boxInfectionProb_valueChanged(int i);
	void on_boxStartBunnies_valueChanged(int i);
	void on_boxSleepTime_valueChanged(int i);
	void on_boxFoodDuration_valueChanged(int i);
	void on_boxMaxHunger_valueChanged(int i);

	void on_checkLoad_stateChanged(int i);
	void on_checkSave_stateChanged(int i);
	void on_checkLog_stateChanged(int i);
	void on_checkNoLog_stateChanged(int i);
	void on_checkCsv_stateChanged(int i);

	void on_boxSave_returnPressed();
	void on_boxLoad_returnPressed();
	void on_boxCsv_returnPressed();

private:
};
