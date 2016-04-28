#include "Human.h"
#include <iostream>
#include "Space.h"
#include <time.h>
using namespace std;
//Constructor
Human::Human(City *p, int xValue, int yValue) {
	this->ptrCity = p;
	this->x = xValue;
	this->y = yValue;
	this->symbol = "O";

}
/*Move. Checks for possible places to shift to on the grid, then randomly chooses one to go to.*/
void Human::move() {
	bool northViable = false;
	bool eastViable = false;
	bool southViable = false;
	bool westViable = false;
	recruitSteps++;
	


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
		if (ptrCity->getGrid(this->x+1,this->y)->showSymbol() == "_") {
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
			ptrCity->setGrid(this->x, this->y+1, this);
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
/*Every three steps, if they are able, the humans generate new recruits
(presumably through some dark sorcery designed to counter the zombies own)*/
void Human::recruit() {

	if (recruitSteps > 2) {
		bool northViable = false;
		bool eastViable = false;
		bool southViable = false;
		bool westViable = false;
		recruitSteps = 0;


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
				Human *privateNewbie = new Human(this->ptrCity, this->x - 1, this->y);
				ptrCity->setGrid(privateNewbie->x, privateNewbie->y, privateNewbie);
				break;
			}
			else if (n == 1 && eastViable) {
				Human *privateNewbie = new Human(this->ptrCity, this->x, this->y + 1);
				ptrCity->setGrid(privateNewbie->x, privateNewbie->y, privateNewbie);
				break;
			}
			else if (n == 2 && southViable) {
				Human *privateNewbie = new Human(this->ptrCity, this->x + 1, this->y);
				ptrCity->setGrid(privateNewbie->x, privateNewbie->y, privateNewbie);
				break;
			}
			else if (n == 3 && westViable) {
				Human *privateNewbie = new Human(this->ptrCity, this->x, this->y - 1);
				ptrCity->setGrid(privateNewbie->x, privateNewbie->y, privateNewbie);
				break;
			}
		}
	}
}