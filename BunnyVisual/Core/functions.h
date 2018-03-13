#include "imp_header.h"

#ifndef MAINFCT
#define MAINFCT

#define FEED_RANGE 5
#define NAME_LEN 128

int game(PargList argStruct);

/*copys a string to another, with guaranted null termination*/
void strcpy_safe(char *output, int str_len, const char* input);

/*removes _ from names for output*/
void fprint_name(FILE *fp, char *Name);

/*returns name without '_'*/
void get_name(char *input, char *output);

/*returns 1, if coordinates are in grid*/
int inBounds(int x, int y);

/*moves the bunny to a random free field*/
void moveBunny(bunny **anchor, Point food[], Ui_BunnyWindowClass *ui);

/*find a free field and return offset towards it
state==0	return a free field
state==1	returm a taken field*/
Point findField(bunny **anchor, int state, Point coords, Point food[]);

/*check if the requested field is already taken
return 0 if field is free, otherwise 1*/
int testEmpty(bunny **anchor, Point coords, Point food[]);

/*find the bunny to requested coordinates,
returns pointer to bunny or NULL-pointer*/
bunny *matchToGrid(bunny **anchor, Point coords);

/*converts the string to lower case*/
void toLowerCase(int argc, char *argv[]);

#endif

#ifndef THREADS
#define THREADS
/*handle print to console and savegame*/
DWORD WINAPI printThread(LPVOID lpParam);

/*all functions related to the population*/
DWORD WINAPI turnThread(LPVOID lpParam);

DWORD WINAPI gameThread(LPVOID lpParam);

DWORD WINAPI displayThread(LPVOID lpParam);
#endif

#ifndef CREATEBUNNY
#define CREATEBUNNY
/*returns the important arguments of the saved game
returns number of Bunnies, when game was saved*/
int loadHead(int *gridX, int *gridY, int *foodCount, int *max_hunger, char fileName[]);

/*load all food sources*/
void loadFood(int foodCount, Point food[], int foodDur[], char fileName[], int food_duration);

/*load all bunnys, with attributes*/
void loadBunnies(int tmpFood, int oldBunnyCount, int *bunnyCount, bunny *anchor, Point food[], char fileName[], Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*create a Bunny and return pointer to it
sex, age, col must be given, mutant can be set to -1, Name set to NULL for random generation*/
bunny *createBunny(bunny *anchor, int sex, int col, int age, char Name[], int isMutant, int *bunnyCount, Point coords, Point food[], Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*append a pointer on bunny to the linked list, p->next*/
void bunny_append(bunny *anchor, bunny *e);

/*called from createBunny, sets color and mutant state*/
void initBunny(bunny *myBunny, int col);

/*called from createBunny, sets Name*/
void chooseName(bunny *myBunny);

#endif

#ifndef REDUCEBUNNY
#define REDUCEBUNNY

/*age all bunnies, if neccessary call killBunny*/
void ageBunnies(bunny **anchor, int *bunnyCount, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*kills the *victim and returns pointer to bunny infront of victim in list */
bunny *killBunny(bunny **anchor, bunny *victim, int *bunnyCount, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList, const char *deathMSG);

/*starve 1/2 of all bunnies to death*/
void famineBunnies(bunny **anchor, int *bunnyCount, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*mutant bunnies infects random bunny next to them with infection_prob*/
void infectBunnies(bunny **anchor, int *bunnyCount, unsigned char infection_prob, Point food[], Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*incr daySinceFeeded, if neccessary call killBunny*/
void starveBunnies(bunny **anchor, int *bunnyCount, int max_hunger, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

#endif

#ifndef INCRBUNNY
#define INCRBUNNY

/*check for available males, females, generate new bunny-babies*/
void reproduce(bunny **anchor, int *bunnyCount, Point food[], Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*feed a bunny, if in range of a food source*/
void feedBunnies(bunny **anchor, Point food[], int foodCount, int foodDur[], int *bunnyCount, int food_duration, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*checks if foodsource has resources, if not generate a new one in radius 10, returns true, if bunny was killed due to moved food source*/
bool emptyFood(bunny **anchor, bunny *p, Point food[], int foodDur[], int foodCount, int foodPos, int *bunnyCount, int food_duration, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

#endif

#ifndef PRINTS
#define PRINTS

/*print amount of living bunnies, if --log print all information about any bunny to file*/
void printInfo(bunny *anchor, int *bunnyCount, int cycles, char log);

/*prints the bornMsg in file*/
void bornMsg(bunny *born, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*prints infectMsg*/
void infectMsg(bunny *victim, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*prints death Msg*/
void eolMsg(bunny *victim, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList, const char *deathMSG);

/*prints starve message (and reason)*/
void starveMsg(int start, int *bunnyCount, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList);

/*if --save, print all bunnies with attributes to file for later --load*/
void saveGame(FILE *savedGame, int gridX, int gridY, bunny *anchor, Point food[], int foodDur[], int foodCount, int max_hunger, int bunnyCount, char fileName[]);

/*logs all important stats to a csv file, for later visualisation in 3rd party programms*/
void logGame(FILE *csvName, Ui_BunnyWindowClass *ui);

#endif
