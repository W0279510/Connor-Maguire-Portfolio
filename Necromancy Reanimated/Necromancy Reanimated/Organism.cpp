#include "Organism.h"
#include <iostream>
using namespace std;
/*Essentially an abstract, Organism works through virtual methods to supply the human and zombie classes with their abilities.*/
string Organism::showSymbol() {
	return this->symbol;
}

void Organism::move() {
	
}

void Organism::recruit() {

}

void Organism::perish() {

}