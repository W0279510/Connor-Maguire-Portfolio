#ifndef Organism_H
#define Organism_H
#include <string>
#include "City.h"
using namespace std;

class City;

class Organism {
protected:
	string symbol;
	
	City *ptrCity;
public:
	string showSymbol();
	virtual void move();
	virtual void recruit();
	virtual void perish();
	int x;
	int y;
	int lastTurnMoved = 0;

};

#endif