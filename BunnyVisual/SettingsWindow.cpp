#include "SettingsWindow.h"
#include "BunnyWindow.h"

#include <QFileDialog>

SettingsWindow::SettingsWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.btnDonate->setIcon(QIcon("Resources/paypal.ico"));
	ui.btnDonate->setIconSize(ui.btnDonate->size());

	//QPixmap pixmap("Resource/Paypal.png");
	//QIcon ButtonIcon(pixmap);
	//btnDonate.setIcon(ButtonIcon);
	////button->setIconSize(pixmap.rect().size());
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

void SettingsWindow::on_checkCsv_stateChanged(int i) {
	if (i == 2) {
		*setStruct->csv = 1;
	}
	else {
		*setStruct->csv = 0;
	}
}

void SettingsWindow::on_boxSave_returnPressed() {
	QString strPath = ui.boxSave->text();
	QByteArray byteArr = strPath.toLatin1();
	char *tmpFile = byteArr.data();

	strncpy(setStruct->fileName, tmpFile, NAME_LEN - 1);
	setStruct->fileName[NAME_LEN - 1] = '\0';
	ui.boxLoad->setText(strPath);

	ui.checkSave->setChecked(1);
}

void SettingsWindow::on_boxLoad_returnPressed() {
	QString strPath = ui.boxLoad->text();
	QByteArray byteArr = strPath.toLatin1();
	char *tmpFile = byteArr.data();

	strncpy(setStruct->fileName, tmpFile, NAME_LEN - 1);
	setStruct->fileName[NAME_LEN - 1] = '\0';
	ui.boxSave->setText(strPath);

	ui.checkLoad->setChecked(1);
}

void SettingsWindow::on_boxCsv_returnPressed() {
	QString strPath = ui.boxCsv->text();
	QByteArray byteArr = strPath.toLatin1();
	char *tmpFile = byteArr.data();
	strncpy(setStruct->csvName, tmpFile, NAME_LEN - 1);
	setStruct->fileName[NAME_LEN - 1] = '\0';

	ui.checkCsv->setChecked(1);
}

void SettingsWindow::on_btnChooseLoad_clicked() {
	QString strPath = QFileDialog::getOpenFileName(this,
		tr("Locate your savegame"), QDir::currentPath(), tr("Saved games (*.save);;All Files (*.*)"));
	ui.boxLoad->setText(strPath);
	ui.boxLoad->returnPressed();
}

//void SettingsWindow::on_btnChooseSave_clicked() {
//	QString strPath = QFileDialog::getOpenFileName(this,
//		tr("Choose/Create a File"), "C://", tr("Saved games (*.game);;All Files (*.*)"));
//	ui.boxSave->setText(strPath);
//	ui.boxSave->returnPressed();
//}
//
//void SettingsWindow::on_btnChooseCsv_clicked() {
//	QString strPath = QFileDialog::getOpenFileName(this,
//		tr("Choose/Create a File"), "C://", tr("Textfiles (*.txt *.csv);;All Files (*.*)"));
//	ui.boxCsv->setText(strPath);
//	ui.boxCsv->returnPressed();
//}

void SettingsWindow::on_btnDonate_clicked() {
	ShellExecute(0, 0, L"https://www.paypal.me/CJMayer/1,20", 0, 0, SW_SHOW);
}

void SettingsWindow::get_args(PargList argStruct) {
	setStruct = argStruct;

	std::string strPath = argStruct->fileName;
	std::string csvPath = argStruct->csvName;

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
	ui.boxCsv->setText(QString::fromStdString(csvPath));

	ui.checkLoad->setChecked(*argStruct->load);
	ui.checkSave->setChecked(*argStruct->save);
	ui.checkCsv->setChecked(*argStruct->csv);

	ui.checkLog->setChecked(*argStruct->log);
	ui.checkNoLog->setChecked(*argStruct->noLog);
}