#pragma once

#include "Core/bunny.h"
#include <Windows.h>
#include "SettingsWindow.h"

#include <QtWidgets/QMainWindow>
#include "ui_BunnyWindow.h"
#include <QtGui>
#include <QtCore>

class BunnyWindow : public QMainWindow
{
	Q_OBJECT

public:
	BunnyWindow(QWidget *parent = Q_NULLPTR);
	~BunnyWindow();

	PargList argStruct;

	//PdisplayList displayStruct;

	bunny *anchor = NULL;
	Point *food = NULL;
	int *foodDur = NULL;

	QListWidgetItem *msgList[6];

	unsigned int max_colony_size = 1000;
	unsigned char infection_prob = 80; //in %
	char log = 0, noLog = 1;
	unsigned int start_Bunnies = 15;
	unsigned int sleep_time = 750;
	char save = 0, load = 0;
	int food_duration = 4717;
	char fileName[NAME_LEN] = "game01.save";

	int file_len = sizeof(fileName) / sizeof((fileName)[0]);
	//define as variable, for disabled food sources
	int max_hunger = 3;

	int bunnyCount = 0;
	unsigned int cycles = 0;

	private slots:
	void on_btnStart_clicked();
	void on_btnSettings_clicked();
	void on_btnDetails_clicked();
	void on_btnSnapshot_clicked();

protected:
	void BunnyWindow::keyPressEvent(QKeyEvent *);
	void BunnyWindow::paintEvent(QPaintEvent *e);
	void BunnyWindow::resizeEvent(QResizeEvent *e);

private:
	Ui::BunnyWindowClass ui;
	SettingsWindow *settings;

	void BunnyWindow::openFile();
	/*loads the savegame, allocates *food and *foodDur*/
	void BunnyWindow::execLoad(char *load, int *max_hunger, char *fileName, int *bunnyCount, bunny **anchor, Point *food, int *foodDur, int *food_duration);

	void BunnyWindow::setSleep(int time);

	void BunnyWindow::disableButtons();

	//
};
