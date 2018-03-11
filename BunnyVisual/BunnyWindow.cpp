#include "Core/imp_header.h"
#include "Core/functions.h"

#include "BunnyWindow.h"
#include "SettingsWindow.h"
#include <limits.h>

#include <QKeyEvent>

CRITICAL_SECTION g_fprint;
CRITICAL_SECTION g_bunny;

typedef struct displayList {
	BunnyWindow *that;
	unsigned int *cycles;
	int *bunnyCount;
	unsigned int *sleep_time;
}displayList, *PdisplayList;

BunnyWindow::BunnyWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowIcon(QIcon("/Resources/Rabbit.ico"));

	settings = new SettingsWindow();

	srand((unsigned int)time(NULL));

	InitializeCriticalSection(&g_fprint);
	InitializeCriticalSection(&g_bunny);

	//give argStruct into settings form
	argStruct = (PargList)malloc(sizeof(argList));
	argStruct->ui = &ui;
	argStruct->fileName = fileName;
	argStruct->save = &save;
	argStruct->load = &load;
	argStruct->log = &log;
	argStruct->noLog = &noLog;
	argStruct->max_hunger = &max_hunger;
	argStruct->sleep_time = &sleep_time;
	argStruct->infection_prob = &infection_prob;
	argStruct->max_colony_size = &max_colony_size;
	argStruct->food_duration = &food_duration;
	argStruct->start_Bunnies = &start_Bunnies;
	argStruct->file_len = arr_len(fileName);

	msgList[debug] = new QListWidgetItem("Debug Message");
	msgList[misc] = new QListWidgetItem("Misc Messages");
	msgList[birth] = new QListWidgetItem("Latest Birth");
	msgList[death] = new QListWidgetItem("Latest Death");
	msgList[infect] = new QListWidgetItem("Latest Infect");
	msgList[speed] = new QListWidgetItem("Current Speed");

	ui.listMsg->addItem(msgList[debug]);
	ui.listMsg->addItem(msgList[misc]);
	ui.listMsg->addItem(msgList[birth]);
	ui.listMsg->addItem(msgList[death]);
	ui.listMsg->addItem(msgList[infect]);
	ui.listMsg->addItem(msgList[speed]);
}

BunnyWindow::~BunnyWindow() {
	//if (food != NULL) free(food);
	//if (foodDur != NULL) free(foodDur);

	DeleteCriticalSection(&g_bunny);
}

DWORD WINAPI displayThread(LPVOID lpParam) {
	PdisplayList displayStruct = (PdisplayList)lpParam;

	int oldCycle = -1, oldBunnyCount = -1;

	while (true) {
		if (oldCycle != *(displayStruct->cycles) || oldBunnyCount != *(displayStruct->bunnyCount)) {
			displayStruct->that->update();
		}
		oldCycle = *(displayStruct->cycles);
		oldBunnyCount = *(displayStruct->bunnyCount);

		Sleep((*displayStruct->sleep_time));
	}
	free(displayStruct);
}

void BunnyWindow::paintEvent(QPaintEvent *e) {
	//get dimension of drawing field
	QRect area = ui.RenderArea->geometry();

	int xStep = area.width() / gridX;
	int yStep = area.height() / gridY;

	int xMax = area.x() + gridX * xStep;
	int yMax = area.y() + gridY * yStep;

	int xMin = area.x();
	int yMin = area.y();

	int fontSize;

	bunny *p;
	char bSex;

	QColor cBlack(1, 1, 1, 255);
	QColor cBrown(139, 69, 19, 255);
	QColor cGray(160, 160, 164, 255);
	QColor cCreme(218, 165, 32, 255);

	QColor *furCol[] = { &cBlack, &cBrown, &cGray, &cCreme };

	QPainter painter(this);
	QPen linePen(Qt::gray);
	linePen.setWidth(0);

	QPen bunnyPen(Qt::black);

	if (xStep < yStep) {
		fontSize = xStep;
	}
	else {
		fontSize = yStep;
	}
	painter.setFont(QFont("Arial", fontSize));

	//draw Grid
	QPoint p1, p2, bunnyPt, foodPt;
	painter.setPen(linePen);

	p1.setX(xMin);
	p1.setY(yMin);
	p2.setX(xMin);
	p2.setY(yMax);

	int help;
	for (int i = 0; i <= gridX; i++) {
		painter.drawLine(p1, p2);
		p1.setX(p1.x() + xStep);
		p2.setX(p2.x() + xStep);
	}

	p1.setX(xMin);
	p1.setY(yMin);
	p2.setX(xMax);
	p2.setY(yMin);

	for (int i = 0; i <= gridY; i++) {
		painter.drawLine(p1, p2);
		p1.setY(p1.y() + yStep);
		p2.setY(p2.y() + yStep);
	}

	EnterCriticalSection(&g_bunny);
	for (p = anchor; p != NULL; p = (bunny*)p->next) {
		bunnyPt.setX(xMin + p->coord.x*xStep + 1);
		bunnyPt.setY(yMin + p->coord.y*yStep + yStep + 1);

		bunnyPen.setColor(*furCol[p->color]);
		//differ between sex, age, and mutant-state
		if (p->radioactive_mutant_vampire_bunny == 1) {
			bSex = 'X';
			bunnyPen.setColor(Qt::red);
		}
		else if (p->sex == male) {
			if (p->age >= 2) {
				bSex = 'M';
			}
			else {
				bSex = 'm';
			}
		}
		else {
			if (p->age >= 2) {
				bSex = 'F';
			}
			else {
				bSex = 'f';
			}
		}
		painter.setPen(bunnyPen);
		painter.drawText(bunnyPt, QString(bSex));
	}

	if (food != NULL) {
		bunnyPen.setColor(Qt::darkGreen);
		painter.setPen(bunnyPen);
		for (int i = 0; i < foodCount; i++) {
			foodPt.setX(xMin + food[i].x * xStep + 1);
			foodPt.setY(yMin + food[i].y * yStep + yStep + 1);
			painter.drawText(foodPt, QString("O"));
		}
	}
	LeaveCriticalSection(&g_bunny);
}

void BunnyWindow::keyPressEvent(QKeyEvent *e) {
	if (e->key() == Qt::Key_W) {
		if (sleep_time <= 250) {
			sleep_time = 100;	//fastest possible
			msgList[speed]->setText("reached fastest speed of " + QString::number(sleep_time) + " ms");
		}
		else {
			sleep_time -= 250;
			msgList[speed]->setText("speeded up to " + QString::number(sleep_time) + " ms");
		}
	}
	else if (e->key() == Qt::Key_S) {
		sleep_time += 250;
		msgList[speed]->setText("slowed down to " + QString::number(sleep_time) + " ms");
	}
	else if (e->key() == Qt::Key_K) {
		famineBunnies(&anchor, &bunnyCount, &ui, msgList);
		msgList[speed]->setText("You murdered half of the bunnies");
	}
}

void BunnyWindow::on_btnDetails_clicked() {
	if (ui.listMsg->currentItem() == msgList[speed]) {
		settings->show();
	}
	else if (ui.listMsg->currentItem() == msgList[birth]) {
		//BETA: show attributes
	}
	else if (ui.listMsg->currentItem() == msgList[infect]) {
	}
}

void BunnyWindow::on_btnSettings_clicked() {
	settings->get_args(argStruct);
	settings->show();
	settings->raise();
}

void BunnyWindow::setSleep(int time) {
	sleep_time = time;
}

void BunnyWindow::disableButtons() {
	settings->ui.boxGridX->setEnabled(false);
	settings->ui.boxGridY->setEnabled(false);

	settings->ui.boxFoodCount->setEnabled(false);
	settings->ui.boxStartBunnies->setEnabled(false);

	settings->ui.boxLoad->setEnabled(false);
	settings->ui.checkLoad->setEnabled(false);

	if (load == 1) {
		//BETA: make save after load possible
		settings->ui.boxSave->setEnabled(false);
		settings->ui.checkSave->setEnabled(false);
	}

	settings->ui.checkNoLog->setEnabled(false);

	if (noLog == 1)
		settings->ui.checkLog->setEnabled(false);
}

void BunnyWindow::on_btnStart_clicked() {
	DWORD gameId, displayId;
	HANDLE gameHandle, displayHandle;

	PdisplayList displayStruct;

	//	settings.ui->boxGridX->setEnabled(false);

	if ("Stop" == ui.btnStart->text().toStdString()) {
		ui.btnStart->setText("you really thougt you could controll this...");
		ui.btnStart->setEnabled(false);
	}
	else {
		ui.btnStart->setText("Stop");

		BunnyWindow::disableButtons();

		//ui.btnStart->setEnabled(false);

		openFile();

		execLoad(&load, &max_hunger, fileName, &bunnyCount, &anchor, food, foodDur, &food_duration);

		//disable food sources
		if (foodCount == -1) {
			//no bunny will starve to death
			foodCount = 0;
			max_hunger = 51;
		}
		else if (foodCount > 0) {
			//equal to Point food[foodCount];
			food = (Point*)malloc(sizeof(Point) * foodCount);
			foodDur = (int *)malloc(sizeof(int) * foodCount);
		}

#ifdef _DEBUG
		//set arg-values for debug, analysis, balancing, etc
		//noLog = 1;
		//log = 0;
		//*max_hunger = 1;
		//infection_prob = 80;
#endif

		//load food
		if (load == 1) loadFood(foodCount, food, foodDur, fileName, food_duration);

		// collision of - log and -noLog
		if (log == 1 && noLog == 1) noLog = 0;
		//collision of save and load
		if (save == 1 && load == 1) save = 0;

		//save all arguments to structs

		displayStruct = (PdisplayList)malloc(sizeof(displayList));

		displayStruct->that = this;
		displayStruct->sleep_time = &sleep_time;
		displayStruct->bunnyCount = &bunnyCount;
		displayStruct->cycles = &cycles;

		argStruct->anchor = &anchor;
		argStruct->bunnyCount = &bunnyCount;
		argStruct->food = food;
		argStruct->foodDur = foodDur;
		argStruct->cycles = &cycles;

		argStruct->msgList = msgList;

		gameHandle = CreateThread(NULL, 0, gameThread, argStruct, CREATE_SUSPENDED, &gameId);
		displayHandle = CreateThread(NULL, 0, displayThread, displayStruct, CREATE_SUSPENDED, &displayId);

		ResumeThread(gameHandle);
		ResumeThread(displayHandle);
	}
}

void BunnyWindow::openFile() {
	//time for log-file
	time_t rawtime;
	struct tm * timeinfo;
	//for log_name, with enough space, 15 for string, 25 for time
	char buff[40];

	//get the time
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	//combine name with time
	//yyy_mm_dd_hh.mm.ss
	snprintf(buff, 40, "Log_Bunny-%d_%d_%d__%d.%d.%d.txt", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1,
		timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

	//for -nolog
	if (noLog == 1) {
		myfile = NULL;
	}
	else {
		//fstream init for data log
		if ((myfile = fopen(buff, "w")) == NULL) fprintf(stderr, "Could not open Logfile\n");
	}
}

void BunnyWindow::execLoad(char *load, int *max_hunger, char *fileName, int *bunnyCount, bunny **anchor, Point *food, int *foodDur, int *food_duration) {
	int oldBunnyCount;
	Point initCoord;
	//load the game, if wanted
	//-----------------------------------------------------------------
	//food count is  set to 0, to prevent checking for collision with food source
	//tmpFood stores real foodCount-val, to use it in loadBunnies
	//after every bunny is loaded, the food will be initialised
	//----------------------------------------------------------------

	//create bunny which is going to die, as workaround
	//----
	//can't move
	initCoord.x = -10;
	initCoord.y = -10;
	*anchor = createBunny(*anchor, 1, 0, 51, "Dummy", 0, bunnyCount, initCoord, food, &ui, msgList);
	//----

	if (*load == 1) {
		oldBunnyCount = loadHead(&gridX, &gridY, &foodCount, max_hunger, fileName);

		int tmpFood = foodCount;
		foodCount = 0;
		loadBunnies(tmpFood, oldBunnyCount, bunnyCount, *anchor, food, fileName, &ui, msgList);
		//reset foodCount
		foodCount = tmpFood;
	}
}