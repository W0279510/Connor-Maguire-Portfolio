#ifndef Human_H
#define Human_H
#include "Organism.h"

using namespace std;

class City;
class Organism;

class Human : public Organism {
protected:
	int recruitSteps = 0;
public:
	Human::Human(City *p, int x, int y);
	void move();
	void recruit();
};

#endif


