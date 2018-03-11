#include "SettingsWindow.h"
#include "BunnyWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

SettingsWindow::~SettingsWindow()
{
}

void SettingsWindow::on_btnExit_clicked() {
	this->close();
}

void SettingsWindow::on_boxGridX_valueChanged(int i) {
	gridX = i;
}
void SettingsWindow::on_boxGridY_valueChanged(int i) {
	gridY = i;
}
void SettingsWindow::on_boxFoodCount_valueChanged(int i) {
	foodCount = i;
}
void SettingsWindow::on_boxMaxColonySize_valueChanged(int i) {
	*setStruct->max_colony_size = i;
}
void SettingsWindow::on_boxInfectionProb_valueChanged(int i) {
	*setStruct->infection_prob = i;
}
void SettingsWindow::on_boxStartBunnies_valueChanged(int i) {
	*setStruct->start_Bunnies = i;
}
void SettingsWindow::on_boxSleepTime_valueChanged(int i) {
	*setStruct->sleep_time = i;
}
void SettingsWindow::on_boxFoodDuration_valueChanged(int i) {
	*setStruct->food_duration = i;
}
void SettingsWindow::on_boxMaxHunger_valueChanged(int i) {
	*setStruct->max_hunger = i;
}

void SettingsWindow::on_checkLoad_stateChanged(int i) {
	if (i == 2) {
		ui.checkSave->setChecked(0);
		*setStruct->load = 1;
	}
	else {
		*setStruct->load = 0;
	}
}
void SettingsWindow::on_checkSave_stateChanged(int i) {
	if (i == 2) {
		ui.checkLoad->setChecked(0);
		*setStruct->save = 1;
	}
	else {
		*setStruct->save = 0;
	}
}
void SettingsWindow::on_checkLog_stateChanged(int i) {
	if (i == 2) {
		ui.checkNoLog->setChecked(0);
		*setStruct->log = 1;
	}
	else {
		*setStruct->log = 0;
	}
}
void SettingsWindow::on_checkNoLog_stateChanged(int i) {
	if (i == 2) {
		ui.checkLog->setChecked(0);
		*setStruct->noLog = 1;
	}
	else {
		*setStruct->noLog = 0;
	}
}

void SettingsWindow::on_boxSave_returnPressed() {
	QString strPath = ui.boxSave->text();
	QByteArray byteArr = strPath.toLatin1();
	char *tmpFile = byteArr.data();

	strcpy(setStruct->fileName, tmpFile);
	ui.boxLoad->setText(strPath);
}

void SettingsWindow::on_boxLoad_returnPressed() {
	QString strPath = ui.boxLoad->text();
	QByteArray byteArr = strPath.toLatin1();
	char *tmpFile = byteArr.data();

	strcpy(setStruct->fileName, tmpFile);
	ui.boxSave->setText(strPath);
}

void SettingsWindow::get_args(PargList argStruct) {
	setStruct = argStruct;

	std::string strPath = argStruct->fileName;

	ui.boxGridX->setValue(gridX);
	ui.boxGridY->setValue(gridY);

	ui.boxSleepTime->setValue(*argStruct->sleep_time);
	ui.boxFoodDuration->setValue(*argStruct->food_duration);
	ui.boxMaxHunger->setValue(*argStruct->max_hunger);

	ui.boxFoodCount->setValue(foodCount);
	ui.boxMaxColonySize->setValue(*argStruct->max_colony_size);
	ui.boxInfectionProb->setValue(*argStruct->infection_prob);
	ui.boxStartBunnies->setValue(*argStruct->start_Bunnies);

	ui.boxLoad->setText(QString::fromStdString(strPath));
	ui.boxSave->setText(QString::fromStdString(strPath));

	ui.checkLoad->setChecked(*argStruct->load);
	ui.checkSave->setChecked(*argStruct->save);

	ui.checkLog->setChecked(*argStruct->log);
	ui.checkNoLog->setChecked(*argStruct->noLog);
}