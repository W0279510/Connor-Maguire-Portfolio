#include "Cell.h"
#include <iostream>

using namespace std;
Cell::Cell() {

}

Cell::Cell(int x, int y, char sym, bool start, bool end) {
	this->visited = false;
	this->xPosition = x;
	this->yPosition = y;
	this->isStart = start;
	this->isEnd = end;
	this->symbol = sym;
}

bool Cell::endCheck() {
	return this->isEnd;
}

void Cell::setIsStart(bool is) {
	this->isStart = is;
}

void Cell::setIsEnd(bool is) {
	this->isEnd = is;
}

void Cell::setPathDisplay() {
	this->symbol = '#';
}

bool Cell::getIsStart() {
	return this->isStart;
}

bool Cell::getIsEnd() {
	return this->isEnd;
}

int Cell::getXPosition() {
	return this->xPosition;
}

int Cell::getYPosition() {
	return this->yPosition;
}

bool Cell::isVisited() {
	return this->visited;
}

char Cell::getSymbol() {
	return this->symbol;
}

void Cell::setVisited() {
	this->visited = true;
}