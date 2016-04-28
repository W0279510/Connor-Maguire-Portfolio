#include "conStack.h"
#include "Cell.h"
#include <iostream>

using namespace std;

conStack::conStack(int capacity) {
	size = 0;
	this->s = new Cell[capacity];
}

void conStack::push(Cell c) {
	this->s[size] = c;
	this->size++;
	
}

int conStack::getSize() {
	return this->size;
}

Cell conStack::top() {
	return this->s[this->size - 1];
}

bool conStack::isEmpty() {
	if (this->size == 0) {
		return true;
	}
	else {
		return false;
	}
}

Cell conStack::retieve() {
	this->size--;
	Cell toRet = this->s[size];

	return toRet;
}

void conStack::destroy() {
	delete[] s;
}

void conStack::pop() {
	if (this->size > 0) {
		this->size--;
		this->s[size];
	}

}