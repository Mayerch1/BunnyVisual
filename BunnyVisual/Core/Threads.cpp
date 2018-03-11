#include "imp_header.h"
#include "functions.h"
#include "../BunnyWindow.h"

DWORD WINAPI gameThread(LPVOID lpParam) {
	PargList argStruct = (PargList)lpParam;

	game(argStruct);

	DeleteCriticalSection(&g_fprint);

	free(argStruct);
	return 0;
}

DWORD WINAPI printThread(LPVOID lpParam) {
	PthreadData threadStruct = (PthreadData)lpParam;

	while (true) {
		//display Cylce and Bunny-count
		threadStruct->ui->lblCycles->setText(QString::number(*(threadStruct->cycles)));
		threadStruct->ui->blbBunnyCount->setText(QString::number(*threadStruct->bunnyCount));

		EnterCriticalSection(&g_bunny);

		printInfo(*(threadStruct->anchor), threadStruct->bunnyCount, *(threadStruct->cycles), *(threadStruct->log));
		//save the game
		if (*(threadStruct->save) == 1) saveGame(gridX, gridY, *(threadStruct->anchor), threadStruct->food, threadStruct->foodDur, *(threadStruct->foodCount), *(threadStruct->max_hunger), *(threadStruct->bunnyCount), threadStruct->fileName);

		LeaveCriticalSection(&g_bunny);

		//in case of program termination
		if (*(threadStruct->noLog) != 1) fflush(myfile);

		Sleep(*(threadStruct->sleep_time));
	}
	return 0;
}

DWORD WINAPI turnThread(LPVOID lpParam) {
	PthreadData threadStruct = (PthreadData)lpParam;
	int i = 0;

	bunny *tmpAnchor;
	bunny *tmpNext;
	QListWidgetItem *infect = NULL, *death = NULL;
	QListWidgetItem **msgList;

	do {
		//while (anchor->next != NULL) {
		(*(threadStruct->cycles))++;

		//execute next cycle

		EnterCriticalSection(&g_bunny);

		infectBunnies(threadStruct->anchor, threadStruct->bunnyCount, *(threadStruct->infection_prob), threadStruct->food, threadStruct->ui, threadStruct->msgList);

		moveBunny(threadStruct->anchor, threadStruct->food, threadStruct->ui);

		ageBunnies(threadStruct->anchor, threadStruct->bunnyCount, threadStruct->ui, threadStruct->msgList);

		reproduce(threadStruct->anchor, threadStruct->bunnyCount, threadStruct->food, threadStruct->ui, threadStruct->msgList);

		feedBunnies(threadStruct->anchor, threadStruct->food, *(threadStruct->foodCount), threadStruct->foodDur, threadStruct->bunnyCount, *(threadStruct->food_duration), threadStruct->ui, threadStruct->msgList);

		starveBunnies(threadStruct->anchor, threadStruct->bunnyCount, *(threadStruct->max_hunger), threadStruct->ui, threadStruct->msgList);

		//food shortage
		if ((unsigned int)*(threadStruct->bunnyCount) > *(threadStruct->max_colony_size)) {
			famineBunnies(threadStruct->anchor, threadStruct->bunnyCount, threadStruct->ui, threadStruct->msgList);
		}

		LeaveCriticalSection(&g_bunny);

		//wait
		slp(*(threadStruct->sleep_time));

		//check every cycle for anchor->next, form stack of main (got throug threadStruct)
		tmpAnchor = *(threadStruct->anchor);
		tmpNext = tmpAnchor->next;
	} while (tmpNext != NULL);

	return 0;
}