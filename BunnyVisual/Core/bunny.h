#include "ui_BunnyWindow.h"
#include "Windows.h"

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
	char *csvName;

	char *save, *csv;
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

	HANDLE *turnHandle, *printHandle;

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
	char *save, *load, *csv;
	int *food_duration;
	char *fileName;
	char *csvName;
	int file_len;
}argList, *PargList;

//file_len = arr_len(fileName)