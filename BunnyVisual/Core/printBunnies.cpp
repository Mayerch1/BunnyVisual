#include "imp_header.h"
#include "functions.h"

#define COLOR_D_GRAY	"\x1b[90m"
#define COLOR_RED		"\x1b[91m"

#define COLOR_BROWN		"\x1b[38;5;130m"
#define COLOR_WHITE		"\x1b[97"
#define COLOR_GRAY		"\x1b[38;5;244m"
#define COLOR_CREME		"\x1b[38;5;172m"

#define COLOR_GREEN		"\x1b[92m"
#define COLOR_YELLOW	"\x1b[93m"
#define COLOR_BLUE		"\x1b[94m"
#define COLOR_MAGENTA	"\x1b[95m"
#define COLOR_CYAN		"\x1b[96m"

#define COLOR_RESET		"\x1b[0m"

extern int gridX, gridY;

void bornMsg(bunny *born, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	std::string strCol[] = { "black", "brown", "gray", "creme" };

	EnterCriticalSection(&g_fprint);
	if (myfile != NULL) {
		fprint_name(myfile, born->Name);
		fprintf(myfile, " was born ");
		//printf color of bunny
		if (born->color == 0) {
			fprintf(myfile, "with a black fur ");
		}
		else if (born->color == 1) {
			fprintf(myfile, "with a brown fur ");
		}
		else if (born->color == 2) {
			fprintf(myfile, "with a gray fur ");
		}
		else if (born->color == 3) {
			fprintf(myfile, "with a creme-colored fur ");
		}

		if (born->radioactive_mutant_vampire_bunny == 1) fprintf(myfile, " and it is a RADIOACTIVE-MUTANT-VAMPIRE-BUNNY!");
		fprintf(myfile, "\n");
	}

	LeaveCriticalSection(&g_fprint);

	char charName[arr_len(born->Name)];
	get_name(born->Name, charName);

	std::string strName = charName;

	msgList[birth]->setText(QString::fromStdString(strName) + " the " + QString::fromStdString(strCol[born->color]) + " was born");
}

void infectMsg(bunny *victim, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	EnterCriticalSection(&g_fprint);
	if (myfile != NULL) {
		fprint_name(myfile, victim->Name);
		fprintf(myfile, " was INFECTED with the virus\n");
	}
	LeaveCriticalSection(&g_fprint);

	char charName[arr_len(victim->Name)];
	get_name(victim->Name, charName);

	std::string strName = charName;

	msgList[infect]->setText(QString::fromStdString(strName) + " was infected");
}

void eolMsg(bunny *victim, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList, const char *deathMSG) {
	EnterCriticalSection(&g_fprint);
	if (myfile != NULL) {
		fprint_name(myfile, victim->Name);
		fprintf(myfile, " %s", deathMSG);
		fprintf(myfile, "\n");
	}
	LeaveCriticalSection(&g_fprint);

	char charName[arr_len(victim->Name)];
	get_name(victim->Name, charName);

	std::string strName = charName;
	std::string deathString = deathMSG;

	msgList[death]->setText(QString::fromStdString(strName) + QString::fromStdString(deathString));
}

void starveMsg(int start, int *bunnyCount, Ui_BunnyWindowClass *ui) {
	EnterCriticalSection(&g_fprint);
	if (myfile != NULL) {
		fprintf(myfile, "\n\nFood shortage killed %d bunnies\n\n", start - *bunnyCount);
	}
	LeaveCriticalSection(&g_fprint);

	ui->listMsg->addItem("Food shortage killed " + QString::number(start - *bunnyCount));
}

void printInfo(bunny *anchor, int *bunnyCount, int cycles, char log) {
	//for --nolog
	if (myfile != NULL) {
		EnterCriticalSection(&g_fprint);
		//for --log
		if (log == 1) {
			//for displaying all of the shit
			const char *bunnyColors[] = { "white", "brown", "gray", "creme" };
			const char *bunnySex[] = { "male", "female" };

			bunny *p;

			fprintf(myfile, "\n");
			fprintf(myfile, "Current living bunnies: \n");
			fprintf(myfile, "-----------\n");
			for (p = anchor; p != NULL; p = (bunny *)p->next) {
				fprintf(myfile, "Name: ");
				fprint_name(myfile, p->Name);
				fprintf(myfile, "\nSex: %s \nColor: %s \nAge: %d \n", bunnySex[p->sex], bunnyColors[p->color], p->age);
				if (p->radioactive_mutant_vampire_bunny == 1) {
					fprintf(myfile, "He's a radioactive-mutant-vampire-bunny\n");
				}
				fprintf(myfile, "\n");
			}
		}
		//print for texfile
		fprintf(myfile, "\nThere're now %d bunnies alive. Cycle Nr: %d\n", *bunnyCount, cycles);
		fprintf(myfile, "--------------------------------------------------\n");
		LeaveCriticalSection(&g_fprint);
	}
}//end displayInfo

void saveGame(int gridX, int gridY, bunny *anchor, Point food[], int foodDur[], int foodCount, int max_hunger, int bunnyCount, char fileName[]) {
	/*
		{arg1,arg2,arg3};
		{foodx,foody,food2,food3}

		{sex,color,age,...}
		{sex,color,age,...}
		{sex,color,age,...};
	*/
	FILE *savedGame;

	if ((savedGame = fopen(fileName, "wb")) == NULL) {
		fprintf(stderr, "Could not write to savefile\n");
		return;
	}
	fprintf(savedGame, "!!Modify at your own risk, wrong values could lead to pointer access violation. Be careful with hidden nl and blancs!!\n");
	//fundamental args
	fprintf(savedGame, "{");
	fprintf(savedGame, "%d,%d,%d,%d,%d,", gridX, gridY, bunnyCount, foodCount, max_hunger);
	fprintf(savedGame, "};\n");

	//food sources, (x,y)
	for (int i = 0; i < foodCount; i++) {
		fprintf(savedGame, "{");
		fprintf(savedGame, "%d,%d,%d,", food[i].x, food[i].y, foodDur[i]);
		fprintf(savedGame, "}\n");
	}
	fprintf(savedGame, "\n");
	bunny *p;
	//loop all bunnies
	for (p = anchor; p != NULL; p = (bunny*)p->next) {
		fprintf(savedGame, "{");
		fprintf(savedGame, "%d ", p->sex);
		fprintf(savedGame, "%d ", p->color);
		fprintf(savedGame, "%d ", p->age);
		fprintf(savedGame, "%s ", p->Name);
		fprintf(savedGame, "%d ", p->radioactive_mutant_vampire_bunny);
		fprintf(savedGame, "%d ", p->daySinceFeeded);
		fprintf(savedGame, "%d %d ", p->coord.x, p->coord.y);
		fprintf(savedGame, "}\n");
	}
	//push and close stream
	fflush(savedGame);
	fclose(savedGame);
}//end saveGame