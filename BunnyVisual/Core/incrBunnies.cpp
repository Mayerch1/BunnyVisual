/*
// incrbunnies.c
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

extern int gridX, gridY;

void reproduce(bunny **anchor, int *bunnyCount, Point food[], Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	int maleCount = 0;
	int femaleCount = 0;
	bunny *p;

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		//count males capable of reproduction
		if (p->sex == male && p->age >= 2 && p->radioactive_mutant_vampire_bunny == 0) {
			maleCount++;
			break;
		}
	}
	if (maleCount == 0) return;

	//create new bunny for each female
	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		if (p->sex == female && p->age >= 2 && p->radioactive_mutant_vampire_bunny == 0) {
			bunny_append(*anchor, createBunny(*anchor, rand() % 2, p->color, 0, NULL, -1, bunnyCount, p->coord, food, ui, msgList));
		}
	}
}//end reproduce

void feedBunnies(bunny **anchor, Point food[], int foodCount, int foodDur[], int *bunnyCount, int food_duration, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	bunny *p;
	//go throug all bunnies

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		//go throug all food sources
		for (int i = 0; i < foodCount; i++) {
			//if bunny in range, feed him
			if (abs(food[i].x - p->coord.x) <= FEED_RANGE && abs(food[i].y - p->coord.y) <= FEED_RANGE) {
				p->daySinceFeeded = 0;
				//emptyFood(anchor, p, food, foodDur, foodCount, i, bunnyCount, food_duration, ui, msgList);
				//BETA: leave if food is destroyed
			}
		}
	}
}//end feedBunnies

void emptyFood(bunny **anchor, bunny *p, Point food[], int foodDur[], int foodCount, int foodPos, int *bunnyCount, int food_duration, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	if (p->age < 2)
		foodDur[foodPos] -= p->age * 2 + 1;
	else {
		foodDur[foodPos] -= (int)(p->age*0.7 + p->sex);
	}
	//hungry bunnies eat more
	foodDur[foodPos] -= p->daySinceFeeded * 4;

	if (foodDur[foodPos] <= 0) {
		//create random new food source, in radius 10
		int x, y;
		do {
			x = food[foodPos].x + rand() % 26 - 13;
			y = food[foodPos].y + rand() % 26 - 13;
		} while (!inBounds(x, y));

		food[foodPos].x = x;
		food[foodPos].y = y;
		foodDur[foodPos] = food_duration;

		bunny *p;
		if ((p = matchToGrid(anchor, food[foodPos])) != NULL) {
			killBunny(anchor, p, bunnyCount, ui, msgList, " ate poisonous buds");
		}
	}
}//end emptyFood