/*
// bunny.h
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

#include "ui_BunnyWindow.h"

#pragma once
#define NAME_LEN 128

typedef struct {
	int x, y;
}Point;

enum gender { male, female };
enum paint { black, brown, gray, creme };
enum list { debug, misc, birth, death, infect, speed };

typedef struct bunny {
	enum gender sex;
	enum paint color;
	char age;
	char Name[NAME_LEN];
	char radioactive_mutant_vampire_bunny;
	int daySinceFeeded;
	Point coord;
	struct bunny *next;
}bunny;

/*structures, which contains important values for each thread*/
typedef struct threadData {
	Ui::BunnyWindowClass *ui;
	QListWidgetItem **msgList;

	bunny **anchor;
	int *bunnyCount;

	Point *food;
	int *foodCount;
	int *foodDur;

	unsigned int *cycles;
	char *fileName;

	char *save;
	char *noLog;
	char *log;
	int *max_hunger;
	unsigned int *sleep_time;
	unsigned char *infection_prob;
	unsigned int *max_colony_size;
	int *food_duration;
}threadData, *PthreadData;

typedef struct argList {
	Ui::BunnyWindowClass *ui;
	QListWidgetItem **msgList;

	bunny **anchor;
	Point *food;

	int *bunnyCount;
	unsigned int *cycles;
	int *foodDur;

	int *max_hunger;
	unsigned int *max_colony_size;
	unsigned char *infection_prob;
	char *log, *noLog;
	unsigned int *start_Bunnies;
	unsigned int *sleep_time;
	char *save, *load;
	int *food_duration;
	char *fileName;
	int file_len;
}argList, *PargList;

//file_len = arr_len(fileName)