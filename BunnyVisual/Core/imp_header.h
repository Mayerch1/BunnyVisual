#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>

#include "bunny.h"

//#include "../BunnyWindow.h"

#ifdef _WIN32
#include <Windows.h>
#include <conio.h>

#define clrcsl() system("cls");
#define slp(t) Sleep(t)
#endif

#ifdef linux
#include <unistd.h>

#define clrcsl() printf("\033[H\033[J")
#define slp(t) sleep((float)(t/1000))
#endif

#define arr_len(x) sizeof(x) / sizeof((x)[0])

extern int gridX, gridY;
extern int foodCount;

extern FILE *myfile;
extern CRITICAL_SECTION g_fprint;
extern CRITICAL_SECTION g_bunny;
