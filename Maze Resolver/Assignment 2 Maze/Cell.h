#ifndef CELL_H
#define CELL_H

/*The Cell is an object that has x and y coordinates, a symbol (which should be either a blank character, +, - or |, as well as
boolean values to determine whether they are the start or end position. Get/Set methods are employed for most values, although
since an object can only be vistied and not unvisited, the setVisited method only goes one way.

setPathDisplay converts the Cell's symbol into a '#' value for purposes of displaying the final path. This method is invoked
once the path from start to end is determined to make the path visible to humans.*/

class Cell {
private:
	bool visited;
	bool isStart;
	bool isEnd;
	int xPosition;
	int yPosition;
	char symbol;

public:
	Cell();
	Cell(int x, int y, char sym, bool start, bool end);
	bool isVisited();
	bool endCheck();
	int getXPosition();
	int getYPosition();
	char getSymbol();
	void setIsStart(bool is);
	void setIsEnd(bool is);
	bool getIsStart();
	bool getIsEnd();
	void setVisited();
	void setPathDisplay();

	
};


#endif