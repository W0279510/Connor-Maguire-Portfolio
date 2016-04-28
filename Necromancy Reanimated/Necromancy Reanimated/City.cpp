#include "City.h"
#include <iostream>
#include "Space.h"
#include <Windows.h>
class Space;

using namespace std;
/*Constructor*/
City::City() {
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {

			Space *s = new Space(x,y);
			this->grid[x][y] = s;
		}
	}
}
/*Set Values*/
void City::setGrid(int xValue, int yValue, Organism *p) {
	this->grid[xValue][yValue] = p;
}
/*Finding Values*/
Organism *City::getGrid(int x, int y) {
	return grid[x][y];
}
/*Print the human-readable array, now with color!*/
void City::printGrid() {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			Organism *dis = grid[x][y];
			if (dis->showSymbol() == "X") {
				SetConsoleTextAttribute(hStdout, FOREGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else if (dis->showSymbol() == "O") {
				SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else {
				SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			
			
			cout << dis->showSymbol();

		}
		cout << endl;
	}
}