/*
// createBunnies.c
//
// The Bunny.exe is a simulation, which simulates a virtual Bunny-colony
// Several different arguments can be feeded, to customize the experience
// As userinput at runtime, is the massmurder, acceleration and deceleration available (Windows only)

Copyright (C) 2018 Christian Mayer

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

contact @https://github.com/mayerch1
//
*/

#include "imp_header.h"
#include "functions.h"

int loadHead(int *gridX, int *gridY, int *foodCount, int *max_hunger, char fileName[]) {
	FILE *loadGame;
	int oldBunnyCount;

	//open filestream, check for !=NULL
	if ((loadGame = fopen(fileName, "r")) == NULL) {
		fprintf(stderr, "Coult not read savegame\n");
		return 0;
	}

	//skip notes
	fscanf(loadGame, "%*[^\n]\n");

	//scan args, ignore last 3 %*c
	fscanf(loadGame, "{%d,%d,%d,%d,%d,%*c%*c%*c", gridX, gridY, &oldBunnyCount, foodCount, max_hunger);

	fclose(loadGame);
	return oldBunnyCount;
}//end loadHead

void loadFood(int foodCount, Point food[], int foodDur[], char fileName[], int food_duration) {
	FILE *loadGame;
	//open filestream, check for !=NULL
	if ((loadGame = fopen(fileName, "r")) == NULL) {
		fprintf(stderr, "Coult not read savegame\n");
		return;
	}
	//skip args, notes
	fscanf(loadGame, "%*[^\n]\n");
	fscanf(loadGame, "%*[^\n]\n");

	//loop throug all foodCounts
	for (int i = 0; i < foodCount; i++) {
		int tmpFood;
		//scan x and y, ignore last to %*c
		fscanf(loadGame, "{%d,%d,%*c%*c", &food[i].x, &food[i].y);
		//BETA: load foodDur
		foodDur[i] = food_duration;
	}
	fclose(loadGame);
}//end loadFood

void loadBunnies(int tmpFood, int oldBunnycount, int *bunnyCount, bunny *anchor, Point food[], char fileName[], Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	FILE *loadGame;

	//open filestream, check for !=NULL
	if ((loadGame = fopen(fileName, "r")) == NULL) {
		fprintf(stderr, "Coult not read savegame\n");
		return;
	}

	//attributes of bunny
	int sex, color;
	int age, isMutant;
	char Name[NAME_LEN];
	int daySinceEaten;
	int x, y;

	//skip args, notes
	fscanf(loadGame, "%*[^\n]\n");
	fscanf(loadGame, "%*[^\n]\n");

	//skip food saves, +1 for additional \n
	for (int i = 0; i < tmpFood; i++) {
		fscanf(loadGame, "%*[^\n]\n");
	}

	//scanf all bunny attributes, ignore last 2 %*c
	for (int i = 0; i < oldBunnycount; i++) {
		fscanf(loadGame, "{%d %d %d %s %d %d %d %d %*c%*c", &sex, &color, &age, Name, &isMutant, &daySinceEaten, &x, &y);
		Point coords = { x, y };
		Point food[1];
		//create loaded bunny, food[] is not used but need to be passed
		bunny_append(anchor, createBunny(anchor, sex, color, (char)age, Name, isMutant, bunnyCount, coords, food, ui, msgList));
	}

	//close
	fclose(loadGame);
}//end loadBunnies

//---------------------------------------------------------------------------------------------------------------------------------------------

bunny *createBunny(bunny *anchor, int sex, int col, int age, char Name[], int isMutant, int *bunnyCount, Point coords, Point food[], Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	bunny *p;
	Point offset = { 0, 0 };
	int xOff = 0, yOff = 0;

	p = (bunny*)malloc(sizeof(bunny));
	if (p == NULL) {
		fprintf(stderr, "No memory available\n");
		return NULL;
	}

	//set age as given in function
	p->age = age;
	p->sex = (gender)sex;

	//choose one Grid beneath mother
	if (anchor == NULL) {
		p->coord.x = coords.x;
		p->coord.y = coords.y;
	}
	else {
		offset = findField(&anchor, 0, coords, food); //emtpy fields

		//if no free field, delete born bunny
		if (offset.x == 0 && offset.y == 0) {
			free(p);
			return NULL;
		}

		//add offsets to mother's coords
		p->coord.x = (coords.x + offset.x);
		p->coord.y = (coords.y + offset.y);
	}

	p->next = NULL;

	initBunny(p, col);

	//if name is given by function call
	if (Name == NULL)
		chooseName(p);
	else
		strcpy(p->Name, Name);

	//if mutantState is set from function call, -1 will call rand()
	if (isMutant == 1) {
		p->radioactive_mutant_vampire_bunny = 1;
	}
	else if (isMutant == 0) {
		p->radioactive_mutant_vampire_bunny = 0;
	}

	bornMsg(p, ui, msgList);

	(*bunnyCount)++;
	return p;
}//end createBunny

void bunny_append(bunny *anchor, bunny *e) {
	bunny *p;

	//if bunny cannot get created
	if (e == NULL) return;

	if (anchor == NULL) {
		anchor = e;
		return;
	}

	for (p = anchor; p->next != NULL; p = (bunny*)p->next);
	p->next = (bunny*)e;
}//end bunny_append

void initBunny(bunny *myBunny, int col) {
	int xOff = 0, yOff = 0;

	//get color of mother
	myBunny->color = (paint)col;

	//mother's milk is extra nutritious
	myBunny->daySinceFeeded = -1;

	//mutant or not
	if (rand() % 100 + 1 <= 1) {
		myBunny->radioactive_mutant_vampire_bunny = 1;
	}
	else {
		myBunny->radioactive_mutant_vampire_bunny = 0;
	}

	//place it random
}//end initBunny

void chooseName(bunny *myBunny) {
	/*DISCLAIMER: all names are unrelated to any real person, and are not chosen by possible associations with real people or groups*/

	const char mNames[][NAME_LEN] = { "Rudi_Rammler", "Kevin", "The_Hoff", "Pringle", "Fat_Boy", "Simon", "Lord", "Sir_Lancelot", "Can",
									"Sir_Oppenheimer", "Werner_von_Braun", "Heisenberg", "Alexander_der_Grosse", "Lamarck", "Herr_Reck",
									"Graf_von_Zeppelin", "Bugs_Bunny", "Rambo", "Pietro_Lombardi", "Tebartz_van_Elst", "Roooobert_Geiss",
									"El_Chapo", "Brad_Pitt", "Bill_Gates", "Gauland", "Roche_Gonzales", "Keoki",
		"Kar-Theodor_Maria_Nikolaus_Johann_Jacob_Philipp_Franz_Joseph_Sylvester_Buhl-Freiherr_von_und_zu_Guttenberg" };

	const char fNames[][NAME_LEN] = { "Jacqueline", "Chantal", "Crystal", "Kimberly", "Ebony", "Tiffany", "Amber",
									"Britney", "Becky", "Jessica", "Madison", "Katie", "Heather", "Amanda", "Lauren",
									"Caitlyn", "Rachel", "Allison", "Lacey", "Abby", "Claire", "Barbie", "Olivia",
									"Madeline", "Skylerr", "Milli" };

	//disting. betw. male/female
	if (myBunny->sex == male) {
		int random = rand() % (sizeof(mNames) / NAME_LEN);
		strcpy(myBunny->Name, mNames[random]);
		//strcpy(myBunny->Name, "Walter");
	}
	else {
		int random = rand() % (sizeof(fNames) / NAME_LEN);
		strcpy(myBunny->Name, fNames[random]);
	}
}//end chooseName