#include "Zombie.h"
#include "Space.h"
#include <time.h>
#include "Human.h"
#include <iostream>
using namespace std;
/*Constructor*/
Zombie::Zombie(City * p, int xValue, int yValue)
{
	this->ptrCity = p;
	this->x = xValue;
	this->y = yValue;
	this->symbol = "X";
}
/*Zombies use a portion of the human movement code, but are ultimately more complicated due to their ability to 
overwrite humans (ie. eating them) and their ability to move diagnally when eating.*/
void Zombie::move() {
	bool nV = false;
	bool neV = false;
	bool eV = false;
	bool seV = false;
	bool sV = false;
	bool swV = false;
	bool wV = false;
	bool nwV = false;
	bool someoneToEat = false;
	viralStrength++;
	stepsToStarve--;

	//BRAIN SEEKING:
	//North?
	if (this->x != 0) {
		if (ptrCity->getGrid(this->x - 1, this->y)->showSymbol() == "O") {
			nV = true;
			someoneToEat = true;
		}
	}
	//North East?
	if (this->x != 0 && this->y != 19) {
		if (ptrCity->getGrid(this->x - 1, this->y + 1)->showSymbol() == "O") {
			neV = true;
			someoneToEat = true;
		}
	}
	//East?
	if (this->y != 19) {
		if (ptrCity->getGrid(this->x, this->y + 1)->showSymbol() == "O") {
			eV = true;
			someoneToEat = true;
		}
	}
	//South East?
	if (this->y != 19 && this->x != 19) {
		if (ptrCity->getGrid(this->x + 1, this->y + 1)->showSymbol() == "O") {
			seV = true;
			someoneToEat = true;
		}
	}
	//South?
	if (this->x != 19) {
		if (ptrCity->getGrid(this->x + 1, this->y)->showSymbol() == "O") {
			sV = true;
			someoneToEat = true;
		}
	}
	//South West?
	if (this->x != 19 && this->y != 0) {
		if (ptrCity->getGrid(this->x + 1, this->y - 1)->showSymbol() == "O") {
			swV = true;
			someoneToEat = true;
		}
	}
	//West?
	if (this->y != 0) {
		if (ptrCity->getGrid(this->x, this->y - 1)->showSymbol() == "O") {
			wV = true;
			someoneToEat = true;
		}
	}
	//North West?
	if (this->x != 0 && this->y != 0) {
		if (ptrCity->getGrid(this->x - 1, this->y - 1)->showSymbol() == "O") {
			nwV = true;
			someoneToEat = true;
		}
	}

	//EAT HAS PRIORITY
	if (someoneToEat) {
		while (true) {
			stepsToStarve = 3;
			int target = rand() % 8;
			if (target == 0 && nV) {
				Space *empt = new Space(this->x, this->y);
				ptrCity->setGrid(this->x - 1, this->y, this);
				ptrCity->setGrid(this->x, this->y, empt);
				
				this->lastTurnMoved = ptrCity->turn;
				this->x--;
				break;
			}
			if (target == 1 && neV) {

				Space *empt = new Space(this->x, this->y);
				ptrCity->setGrid(this->x - 1, this->y + 1, this);
				ptrCity->setGrid(this->x, this->y, empt);
				this->lastTurnMoved = ptrCity->turn;
				this->x--;
				this->y++;
				break;
			}
			if (target == 2 && eV) {

				Space *empt = new Space(this->x, this->y);
				ptrCity->setGrid(this->x, this->y + 1, this);
				ptrCity->setGrid(this->x, this->y, empt);
				this->lastTurnMoved = ptrCity->turn;
				this->y++;
				break;
			}
			if (target == 3 && seV) {
				
				Space *empt = new Space(this->x, this->y);
				ptrCity->setGrid(this->x + 1, this->y + 1, this);
				ptrCity->setGrid(this->x, this->y, empt);
				this->lastTurnMoved = ptrCity->turn;
				this->x++;
				this->y++;
				break;
			}
			if (target == 4 && sV) {
				
				Space *empt = new Space(this->x, this->y);
				ptrCity->setGrid(this->x + 1, this->y, this);
				ptrCity->setGrid(this->x, this->y, empt);
				this->lastTurnMoved = ptrCity->turn;
				this->x++;
				break;
			}
			if (target == 5 && swV) {

				Space *empt = new Space(this->x, this->y);
				ptrCity->setGrid(this->x + 1, this->y - 1, this);
				ptrCity->setGrid(this->x, this->y, empt);
				this->lastTurnMoved = ptrCity->turn;
				this->x++;
				this->y--;
				break;
			}
			if (target == 6 && wV) {
				
				Space *empt = new Space(this->x, this->y);
				ptrCity->setGrid(this->x, this->y - 1, this);
				ptrCity->setGrid(this->x, this->y, empt);
				this->lastTurnMoved = ptrCity->turn;
				this->y--;
				break;
			}
			if (target == 7 && nwV) {
				
				Space *empt = new Space(this->x, this->y);
				ptrCity->setGrid(this->x - 1, this->y - 1, this);
				ptrCity->setGrid(this->x, this->y, empt);
				this->lastTurnMoved = ptrCity->turn;
				this->x--;
				this->y--;
				break;
			}
		}

	}
	/*Nobody to eat, so use human movement.*/
	else {
		bool northViable = false;
		bool eastViable = false;
		bool southViable = false;
		bool westViable = false;


		if (this->x != 0) {
			if (ptrCity->getGrid(this->x - 1, this->y)->showSymbol() == "_") {
				northViable = true;
			}
		}
		if (this->y != 19) {
			if (ptrCity->getGrid(this->x, this->y + 1)->showSymbol() == "_") {
				eastViable = true;
			}
		}
		if (this->x != 19) {
			if (ptrCity->getGrid(this->x + 1, this->y)->showSymbol() == "_") {
				southViable = true;
			}
		}
		if (this->y != 0) {
			if (ptrCity->getGrid(this->x, this->y - 1)->showSymbol() == "_") {
				westViable = true;
			}
		}

		while (true) {
			int n = rand() % 4;
			if (!northViable && !eastViable && !southViable && !westViable) {
				break;
			}
			else if (n == 0 && northViable) {
				Space *cleanup = new Space(this->x, this->y);
				ptrCity->setGrid(this->x - 1, this->y, this);
				ptrCity->setGrid(this->x, this->y, cleanup);
				x--;
				lastTurnMoved = ptrCity->turn;
				break;
			}
			else if (n == 1 && eastViable) {
				Space *cleanup = new Space(this->x, this->y);
				ptrCity->setGrid(this->x, this->y + 1, this);
				ptrCity->setGrid(this->x, this->y, cleanup);
				y++;
				lastTurnMoved = ptrCity->turn;
				break;
			}
			else if (n == 2 && southViable) {
				Space *cleanup = new Space(this->x, this->y);
				ptrCity->setGrid(this->x + 1, this->y, this);
				ptrCity->setGrid(this->x, this->y, cleanup);
				x++;
				lastTurnMoved = ptrCity->turn;
				break;
			}
			else if (n == 3 && westViable) {
				Space *cleanup = new Space(this->x, this->y);
				ptrCity->setGrid(this->x, this->y - 1, this);
				ptrCity->setGrid(this->x, this->y, cleanup);
				y--;
				lastTurnMoved = ptrCity->turn;
				break;
			}
		}
	}
	
}
/*Once the zombie's virus as a chance to grow over time, it spreads the virus as soon as it can to adjacent humans, retaining
the "charge" until it can be discharged into some hapless mortal.*/
void Zombie::recruit() {
	
	if (viralStrength > 7) {
		bool nV = false;
		bool neV = false;
		bool eV = false;
		bool seV = false;
		bool sV = false;
		bool swV = false;
		bool wV = false;
		bool nwV = false;
		bool viralSpread = false;

		//North?
		if (this->x != 0) {
			if (ptrCity->getGrid(this->x - 1, this->y)->showSymbol() == "O") {
				nV = true;
				viralSpread = true;
			}
		}
		//North East?
		if (this->x != 0 && this->y != 19) {
			if (ptrCity->getGrid(this->x - 1, this->y + 1)->showSymbol() == "O") {
				neV = true;
				viralSpread = true;
			}
		}
		//East?
		if (this->y != 19) {
			if (ptrCity->getGrid(this->x, this->y + 1)->showSymbol() == "O") {
				eV = true;
				viralSpread = true;
			}
		}
		//South East?
		if (this->y != 19 && this->x != 19) {
			if (ptrCity->getGrid(this->x + 1, this->y + 1)->showSymbol() == "O") {
				seV = true;
				viralSpread = true;
			}
		}
		//South?
		if (this->x != 19) {
			if (ptrCity->getGrid(this->x + 1, this->y)->showSymbol() == "O") {
				sV = true;
				viralSpread = true;
			}
		}
		//South West?
		if (this->x != 19 && this->y != 0) {
			if (ptrCity->getGrid(this->x + 1, this->y - 1)->showSymbol() == "O") {
				swV = true;
				viralSpread = true;
			}
		}
		//West?
		if (this->y != 0) {
			if (ptrCity->getGrid(this->x, this->y - 1)->showSymbol() == "O") {
				wV = true;
				viralSpread = true;
			}
		}
		//North West?
		if (this->x != 0 && this->y != 0) {
			if (ptrCity->getGrid(this->x - 1, this->y - 1)->showSymbol() == "O") {
				nwV = true;
				viralSpread = true;
			}
		}

		if (viralSpread) {
			while (true) {
				int unluckyVictim = rand() % 8;
				//Convert North
				if (unluckyVictim = 0 && nV) {
					viralStrength = 0;
					Zombie *arisen = new Zombie(ptrCity, this->x - 1, this->y);
					ptrCity->setGrid(this->x - 1, this->y, arisen);
					break;
				}
				if (unluckyVictim = 1 && neV) {
					viralStrength = 0;
					Zombie *arisen = new Zombie(ptrCity, this->x - 1, this->y+1);
					ptrCity->setGrid(this->x - 1, this->y+1, arisen);
					break;
				}
				if (unluckyVictim = 2 && eV) {
					viralStrength = 0;
					Zombie *arisen = new Zombie(ptrCity, this->x, this->y + 1);
					ptrCity->setGrid(this->x, this->y + 1, arisen);
					break;
				}
				if (unluckyVictim = 3 && seV) {
					viralStrength = 0;
					Zombie *arisen = new Zombie(ptrCity, this->x + 1, this->y + 1);
					ptrCity->setGrid(this->x + 1, this->y + 1, arisen);
					break;
				}
				if (unluckyVictim = 4 && sV) {
					viralStrength = 0;
					Zombie *arisen = new Zombie(ptrCity, this->x + 1, this->y);
					ptrCity->setGrid(this->x + 1, this->y, arisen);
					break;
				}
				if (unluckyVictim = 5 && swV) {
					viralStrength = 0;
					Zombie *arisen = new Zombie(ptrCity, this->x + 1, this->y - 1);
					ptrCity->setGrid(this->x + 1, this->y - 1, arisen);
					break;
				}
				if (unluckyVictim = 6 && wV) {
					viralStrength = 0;
					Zombie *arisen = new Zombie(ptrCity, this->x, this->y - 1);
					ptrCity->setGrid(this->x - 1, this->y + 1, arisen);
					break;
				}
				if (unluckyVictim = 7 && nwV) {
					viralStrength = 0;
					Zombie *arisen = new Zombie(ptrCity, this->x - 1, this->y - 1);
					ptrCity->setGrid(this->x - 1, this->y - 1, arisen);
					break;
				}
			}

		}




	}

}
/*The zombie needs to eat humans. If it doesn't, it reverts back to a human. Eating a human
resets their timer, saving them from this not-so-grissly fate.*/
void Zombie::perish() {
	if (stepsToStarve < 1) {
		Human *reborn = new Human(ptrCity, this->x, this->y);
		ptrCity->setGrid(this->x, this->y, reborn);
	}
}