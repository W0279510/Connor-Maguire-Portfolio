#ifndef Zombie_H
#define Zombie_H
#include "Organism.h"

using namespace std;

class Zombie : public Organism {
public:
	Zombie::Zombie(City *p, int x, int y);
	void move();
	void recruit();
	void perish();
	//Used to convert other units through "recruitment"
	int viralStrength = 0;
	int stepsToStarve = 3;
};

#endif