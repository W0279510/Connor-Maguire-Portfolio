#ifndef City_H
#define City_H
#include "Organism.h"
#include <vector>
using namespace std;

class Organism;

class City {
protected:
	Organism *grid[20][20];

public:
	City();
	void setGrid(int x, int y, Organism *o);
	Organism *getGrid(int x, int y);
	void printGrid();
	int turn = 0;

};

#endif