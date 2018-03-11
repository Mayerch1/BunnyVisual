/*
// Source.c
//
// The Bunny.exe is a simulation, which simulates a virtual Bunny-colony
// Several different arguments can be feeded, to customize the experience
// As userinput at runtime, is the massmurder, acceleration and deceleration available (Windows only)

Copyright (C) 2018 Christian Mayer

contact @https://github.com/mayerch1
//
*/

#include "imp_header.h"
#include "functions.h"
#include "../BunnyWindow.h"

FILE *myfile;

int gridX = 116;	//100, 60
int gridY = 83;		//how large is your console?
int foodCount = 5;

void strcpy_safe(char *output, int str_len, const char* input) {
	strncpy(output, input, str_len);
	output[str_len - 1] = '\0';
}

void fprint_name(FILE *fp, char *Name) {
	int i = 0;
	while (Name[i] != '\0') {
		if (Name[i] == '_') {
			fprintf(fp, " ");
			i++;
		}
		else {
			fprintf(fp, "%c", Name[i++]);
		}
	}
}

void get_name(char *input, char *output) {
	int i = 0;

	while (input[i] != '\0') {
		if (input[i] == '_') {
			output[i++] = ' ';
		}
		else {
			output[i] = input[i++];
		}
	}
	//take \0
	output[i] = input[i];
}

int game(PargList argStruct) {
	//-------------------------------------
	srand((unsigned int)time(NULL));

	Ui::BunnyWindowClass *ui = argStruct->ui;
	QListWidgetItem **msgList = argStruct->msgList;

	//#definees, but for arguments, copy out of argStruct
	unsigned int *max_colony_size = (argStruct->max_colony_size);	//arg[1]; >GridX*GridY makes no sense
	unsigned char *infection_prob = (argStruct->infection_prob);	//0-100%
	unsigned int *start_Bunnies = (argStruct->start_Bunnies);		//first created bunnies
	unsigned int *sleep_time = (argStruct->sleep_time);				//sleep between cycles

	//amount of food in one source
	int *food_duration = (argStruct->food_duration);

	//define as variable, for disabled food sources
	int *max_hunger = (argStruct->max_hunger);

	char *noLog = (argStruct->noLog), *log = (argStruct->log);		//arg for logfile
	char *save = (argStruct->save), *load = (argStruct->load);		//save the game, or load it
	char *fileName = argStruct->fileName;//= "game01.save"; fileName[128]
	//end #defines
	//------------------------------------
	//other variables
	//posiiton of food sources, and current amount of food
	Point *food = argStruct->food;
	int *foodDur = argStruct->foodDur;

	//create first n-bunnies
	bunny **anchor = argStruct->anchor;

	int *bunnyCount = (argStruct->bunnyCount);
	unsigned int *cycles = (argStruct->cycles);

	Point initCoord;

	//------------------------------------
	//thread related stuff
	DWORD printId, turnId;
	HANDLE printHandle, turnHandle;

	PthreadData threadStruct = NULL;

	//end create first n

	//end of declarations
	//------------------------------------

	//random position of food, except right and bottom border
	//exec only if no file was loaded

	if (*load == 0) {
		for (int i = 0; i < foodCount; i++) {
			food[i].x = rand() % (gridX - 1);
			food[i].y = rand() % (gridY - 1);
			foodDur[i] = *food_duration;
		}

		//create first bunnys
		if (foodCount <= 0) {
			initCoord.x = rand() % gridX;
			initCoord.y = rand() % gridY;
		}
		else {
			//force first bunny next to food sourve
			initCoord.x = food[0].x + 1;
			initCoord.y = food[0].y + 1;
		}
		//first bunny is female and near to foodsource
		bunny_append(*anchor, createBunny(*anchor, 1, rand() % 4, 0, NULL, -1, bunnyCount, initCoord, food, ui, msgList));

		//next n-1 bunnies
		for (unsigned int i = 0; i < *start_Bunnies - 1; i++) {
			initCoord.x = rand() % gridX;
			initCoord.y = rand() % gridY;
			bunny_append(*anchor, createBunny(*anchor, rand() % 2, rand() % 4, 0, NULL, -1, bunnyCount, initCoord, food, ui, msgList));
		}
		//end create first n bunnies
	}

	//init and start all threats until only one bunny is left
	//-------------------------------------------------------------------------------------------------

	/*struct to pass all variables to threats*/
	threadStruct = (PthreadData)malloc(sizeof(threadData));
	threadStruct->ui = ui;
	//threadStruct->that = argStruct->that;

	threadStruct->anchor = anchor;
	threadStruct->bunnyCount = bunnyCount;

	threadStruct->food = food;
	threadStruct->foodDur = foodDur;
	threadStruct->foodCount = &foodCount;

	threadStruct->cycles = cycles;
	threadStruct->fileName = fileName;

	threadStruct->save = save;
	threadStruct->noLog = noLog;
	threadStruct->log = log;
	threadStruct->max_hunger = max_hunger;
	threadStruct->sleep_time = sleep_time;
	threadStruct->infection_prob = infection_prob;
	threadStruct->max_colony_size = max_colony_size;
	threadStruct->food_duration = food_duration;
	threadStruct->msgList = msgList;

	/*create all threats*/
	printHandle = CreateThread(NULL, 0, printThread, threadStruct, CREATE_SUSPENDED, &printId);
	turnHandle = CreateThread(NULL, 0, turnThread, threadStruct, CREATE_SUSPENDED, &turnId);

	ResumeThread(turnHandle);
	Sleep(2 * (*sleep_time));
	ResumeThread(printHandle);

	msgList[debug]->setText("All threads startet");

	while (WaitForSingleObject(turnHandle, 1000) == WAIT_TIMEOUT) {
		//this keeps main open, until thread exits with 0
		//checks every 1000ms
	}

	//end loop
	//-----------------------------------------------------------------------------------------------

	TerminateThread(printHandle, 0);
	TerminateThread(turnHandle, 0);

	CloseHandle(printHandle);
	CloseHandle(turnHandle);
	msgList[debug]->setText("All handles closed");

	DeleteCriticalSection(&g_fprint);

	//end of game

	msgList[misc]->setText("The last survivor will die soon\n");
	msgList[debug]->setText("Stopped");

	//free dynamic allocated variables

	free(threadStruct);

	if (myfile != NULL) fclose(myfile);
	return 0;
}//end main

int inBounds(int x, int y) {
	if (x < 0 || x > gridX || y < 0 || y > gridY) {
		return 0;
	}
	return 1;
}

void moveBunny(bunny **anchor, Point food[]) {
	Point offset;
	bunny *p;

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		//get random free Field next to p->coord
		//returns (0,0) if every field is taken
		offset = findField(anchor, 0, p->coord, food); //gets empty fields

		//if there's a free field
		if (offset.x != 0 || offset.y != 0) {
			//add offset to coord
			p->coord.x += offset.x;
			p->coord.y += offset.y;
		}
		//else don't move it
	}
}//end moveBunny

Point findField(bunny **anchor, int state, Point coords, Point food[]) {
	Point tmpPt;
	Point offset;

	offset.x = 0;
	offset.y = 0;
	//if state is != 0, 1; ret 0
	if (state != 0 && state != 1) return offset;

	//set whole array to 0
	int targetField[9][2] = { {0,0} };

	//free Fields around bunny
	//-1 means every field is taken
	int freeFields = -1;
	tmpPt = coords;

	//start on the left, top
	tmpPt.x--;
	tmpPt.y--;

	//gets amount of free fields around bunny, and coords of it
	//move from left to right
	for (int i = 0; i < 3; i++) {
		//move from top to bottom
		for (int j = 0; j < 3; j++) {
			//check if field is taken
			int isFree = testEmpty(anchor, tmpPt, food);

			//if field is free
			if (isFree == state) {
				//set the field to the coordinate
				freeFields++;
				targetField[freeFields][0] = tmpPt.x;
				targetField[freeFields][1] = tmpPt.y;
			}
			tmpPt.y++;
		}
		tmpPt.y = coords.y - 1;
		tmpPt.x++;
	}

	//if no field is empty
	if (freeFields == -1) {
		offset.x = 0;
		offset.y = 0;

		return offset;
	}

	//rand Nr, amount of free Field = highest Number
	//from field nr 0 to 'emptyFields'-1
	int randNr = rand() % (freeFields + 1);

	//choose the corresponding field/coordinate to randNr
	offset.x = targetField[randNr][0] - coords.x;
	offset.y = targetField[randNr][1] - coords.y;

	return offset;
}//end findField

int testEmpty(bunny **anchor, Point coords, Point food[]) {
	bunny *p;
	int isTaken = 0;

	//test for food source
	for (int i = 0; i < foodCount; i++) {
		if (food[i].x == coords.x && food[i].y == coords.y) {
			isTaken = 1;
			return isTaken;
		}
	}

	//if coords are out of range/Grid
	if (coords.x >= gridX || coords.x < 0 || coords.y >= gridY || coords.y < 0) {
		//handle as field would be taken
		return 1;
	}

	//go through list, break if grid is taken

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		if (coords.x == p->coord.x && coords.y == p->coord.y) {
			isTaken = 1;
			break;
		}
	}

	//field is taken=1, field is emtpy=0
	return isTaken;
}//testEmtpy

bunny *matchToGrid(bunny **anchor, Point coords) {
	bunny *p;
	//go through, until coords of both match

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		if (p->coord.x == coords.x && p->coord.y == coords.y) {
			return p;
		}
	}

	//return NULL if no bunny at coords
	return NULL;
}//end matchToGrid

void toLowerCase(int argc, char *argv[]) {
	//go throug all args
	for (int i = 1; i < argc; i++) {
		int j = 0;
		while (argv[i][j] != '\0') {
			//if capital, convert to non-capital
			if (argv[i][j] >= 0x41 && argv[i][j] <= 0x5A) {
				argv[i][j] += 0x20;
			}
			j++;
		}
	}
}//end toLowerCase