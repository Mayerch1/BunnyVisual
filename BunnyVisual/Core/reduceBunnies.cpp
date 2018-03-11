#include "imp_header.h"
#include "functions.h"

void ageBunnies(bunny **anchor, int *bunnyCount, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	bunny *p;

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		//kill normal bunnies
		if ((p->age++) >= 10 && p->radioactive_mutant_vampire_bunny == 0) {
			p = killBunny(anchor, p, bunnyCount, ui, msgList, " is EOL :'(");
		}
		//kill radiation_vampire bunnies
		else if (p->age >= 50) {
			p = killBunny(anchor, p, bunnyCount, ui, msgList, " is finally EOL :-)");
		}
	}
}

//kill designatet target
bunny *killBunny(bunny **anchor, bunny *victim, int *bunnyCount, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList, const char *deathMSG) {
	eolMsg(victim, ui, msgList, deathMSG);

	//if anchor dies
	if (victim == *anchor) {
		//if victim is last survivor
		//game will end with next cycle, so he stays alive
		//prevent collapse of further functions
		if (victim->next == NULL) {
			(*anchor)->next = NULL;
			(*bunnyCount)--;
			return *anchor;
		}
		*anchor = (bunny*)victim->next;

		//correct counters, kill it
		free(victim);
		(*bunnyCount)--;
		return *anchor;
	}
	else {
		bunny *searchP, *lastP;

		//find bunny infront of victim
		lastP = (bunny*)anchor;
		for (searchP = *anchor; searchP != victim; searchP = (bunny*)searchP->next) {
			lastP = searchP;
		}

		//append to bunny before vicitm
		lastP->next = victim->next;

		//delete victim
		free(victim);
		(*bunnyCount)--;
		return lastP;
	}
}

void famineBunnies(bunny **anchor, int *bunnyCount, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	int start = *bunnyCount;
	int famineRate = 0;

	if (*anchor == NULL) return;
	//repeat until 1/2 are dead
	while (*bunnyCount > (start / 2)) {
		//choose one bunny
		bunny *victim;
		int vicNr = rand() & *bunnyCount;

		//move *victim to victim

		for (victim = *anchor; vicNr > 1; vicNr--) {
			victim = (bunny*)victim->next;
		}

		//kill him
		killBunny(anchor, victim, bunnyCount, ui, msgList, " starved to death");
		famineRate++;
	}

	starveMsg(start, bunnyCount, ui);
	ui->lblFamineRate->setText(QString::number(famineRate));
}//end starveBunnies

void infectBunnies(bunny **anchor, int *bunnyCount, unsigned char infection_prob, Point food[], Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	bunny *p;
	int mutantCount = 0;
	int xOff = 0, yOff = 0;
	int currInfects = 0;

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		if (p->radioactive_mutant_vampire_bunny == 1) {
			//coords of infection victim
			Point coords;
			Point offset;

			//find taken fields
			offset = findField(anchor, 1, p->coord, food);

			if (offset.x == 0 && offset.y == 0) {
				//go to next mutant
				continue;
			}

			//assign absolute coords of victim
			coords.x = p->coord.x + offset.x;
			coords.y = p->coord.y + offset.y;

			//find *bunny to Gridslot
			bunny *victim;
			victim = matchToGrid(anchor, coords);

			//infect da bunny
			int chance = rand() % 100 + 1;

			//50% infection chance
			if (chance <= infection_prob) {
				if (victim != NULL && victim->radioactive_mutant_vampire_bunny == 0) {
					victim->radioactive_mutant_vampire_bunny = 1;
					infectMsg(victim, ui, msgList);
					currInfects++;
				}
			}
		}
	}
	ui->lblInfectRate->setText(QString::number(currInfects));
}//end infectBunnies

void starveBunnies(bunny **anchor, int *bunnyCount, int max_hunger, Ui_BunnyWindowClass *ui, QListWidgetItem **msgList) {
	bunny *p;
	int starveRate = 0;

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		p->daySinceFeeded++;
	}

	for (p = *anchor; p != NULL; p = (bunny*)p->next) {
		if (p->daySinceFeeded >= max_hunger) {
			p = killBunny(anchor, p, bunnyCount, ui, msgList, " was to dump to eat");
			starveRate++;
		}
	}

	ui->lblStarveRate->setText(QString::number(starveRate));
}//end starveBunnies