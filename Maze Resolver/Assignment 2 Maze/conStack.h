#ifndef CONSTACK_H
#define CONSTACK_H

#include "Cell.h"

/*
s: The stack containing all cells pushed to it.
Push: Adds a cell object to the stack.
Retrieve: Returns the top value and removes it from the stack.
Top: Returns the top value but does not remove it from the stack.
Get Size: Obtains how many objects are assigned to the stack.
IsEmpty: Detects whether the stack has any cells assigned to it.
Destroy: Deallocates the stack from memory.*/

class conStack {
private:
	int size;
	Cell *s;
public:
	conStack(int capacity);
	void push(Cell c);
	Cell retieve();
	Cell top();
	void destroy();
	bool isEmpty();
	void pop();
	int getSize();

};


#endif