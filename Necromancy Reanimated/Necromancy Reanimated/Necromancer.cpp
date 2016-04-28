#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "City.h"
#include <time.h>
#include "Human.h"
#include "Zombie.h"
using namespace std;

int main() {
	
	City c;
	/*Initial Zombie Creation
	Allows for user to directly control insertion*/
	Zombie zom = Zombie(&c, 10, 10);
	Zombie zomTwo = Zombie(&c, 15, 15);
	Zombie zomThree = Zombie(&c, 8, 8);
	Zombie zomFour = Zombie(&c, 2, 13);
	Zombie zomFive = Zombie(&c, 0, 11);
	c.setGrid(zom.x, zom.y, &zom);
	c.setGrid(zomTwo.x, zomTwo.y, &zomTwo);
	c.setGrid(zomThree.x, zomThree.y, &zomThree);
	c.setGrid(zomFour.x, zomFour.y, &zomFour);
	c.setGrid(zomFive.x, zomFive.y, &zomFive);

	/*Initial Human Creation*/
	for (int hPop = 0; hPop < 100; hPop++) {
		srand(time(NULL));
		while (true) {
			int xval = rand() % 20;
			int yval = rand() % 20;
			if (c.getGrid(xval,yval)->showSymbol() == "_") {
				Human *h = new Human(&c, xval, yval);
				c.setGrid(h->x, h->y, h);
				break;
			}
		}
	}
	c.printGrid();
	cout << endl;


	//ITERATION
	for (int run = 0; run < 100; run++) {
		//Zombie Move/Eat
		for (int scanx = 0; scanx < 20; scanx++) {
			for (int scany = 0; scany < 20; scany++) {
				
				if (c.getGrid(scanx, scany)->showSymbol() == "X") {
					if (c.getGrid(scanx, scany)->lastTurnMoved != c.turn) {
						c.getGrid(scanx, scany)->move();
					}
				}
			}
		}
		//Human Move
		for (int scanx = 0; scanx < 20; scanx++) {
			for (int scany = 0; scany < 20; scany++) {
				if (c.getGrid(scanx, scany)->showSymbol() == "O") {
					if (c.getGrid(scanx, scany)->lastTurnMoved != c.turn) {
						c.getGrid(scanx, scany)->move();
					}
				}
			}
		}
		
		//Zombie Convert
		for (int scanx = 0; scanx < 20; scanx++) {
			for (int scany = 0; scany < 20; scany++) {
				if (c.getGrid(scanx, scany)->showSymbol() == "X") {
					c.getGrid(scanx, scany)->recruit();
				}
			}
		}
		
		//Human Recruit
		for (int scanx = 0; scanx < 20; scanx++){
			for (int scany = 0; scany < 20; scany++){
				if (c.getGrid(scanx, scany)->showSymbol() == "O") {
					c.getGrid(scanx, scany)->recruit();
				}
			}
		}

		//Zombie Starve (if they've gone too long without eating)
		for (int scanx = 0; scanx < 20; scanx++) {
			for (int scany = 0; scany < 20; scany++) {
				if (c.getGrid(scanx, scany)->showSymbol() == "X") {
					c.getGrid(scanx, scany)->perish();
				}
			}
		}
		//Extinction Check
		int numOfHumans = 0;
		int numOfZombies = 0;
		for (int scanx = 0; scanx < 20; scanx++) {
			for (int scany = 0; scany < 20; scany++) {
				if (c.getGrid(scanx, scany)->showSymbol() == "X") {
					numOfZombies++;
				}
				else if (c.getGrid(scanx, scany)->showSymbol() == "O") {
					numOfHumans++;
				}
			}
		}
		if (numOfHumans == 0 || numOfZombies == 0) {
			c.printGrid();
			cout << "Extinction Detected, terminating simulation" << endl;
			
			break;
		}
		
		c.turn++;
		c.printGrid();
		cout << endl;
		//Timer delay
		Sleep(100);
	}

	_getch();
	return 0;
}