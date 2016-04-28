
#include <iostream>
#include <conio.h>
#include <fstream>
#include "Cell.h"
#include "conStack.h"

using namespace std;


bool isValid(char direction, int x, int y, Cell **m) {
	bool retValue = false;
	if (direction == 'e') {
		if (m[x][y + 1].getSymbol() == ' ' && m[x][y + 1].isVisited() == false) {
			retValue = true;		
		}
	}
	else if (direction == 's') {
		if (m[x + 1][y].getSymbol() == ' ' && m[x + 1][y].isVisited() == false) {
			retValue = true;
		}
	}
	else if (direction == 'w') {
		if (m[x][y - 1].getSymbol() == ' ' && m[x][y - 1].isVisited() == false) {
			retValue = true;
		}
	}
	else if (direction == 'n') {
		if (m[x - 1][y].getSymbol() == ' ' && m[x - 1][y].isVisited() == false) {
			retValue = true;
		}
	}
	return retValue;
}

void printSolution(Cell **maze, int rows, int cols) {
	//PRINT
	for (int px = 0; px < rows; px++) {
		for (int py = 0; py < cols; py++) {
			bool inPath = false;
			cout << maze[px][py].getSymbol();
		}
		cout << endl;
	}
}

int main() {
	/*Initial Setup
		Rows: Number of rows in maze.
		Cols: Number of columns in maze.
		currentX: Used to track current position while scanning maze.
		currentY: Used to track current position while scaning maze.
		o: Char buffer used to read in maze from file. Fed by stream 'i'.
		i: Stream from file containing maze.
		currentPath: The stack that is used to maintain the path through the maze.*/
	const string PATH = "..\\maze3.txt";
	ifstream i;
	i.open(PATH);
	char o[256];
	int rows = 0;
	int cols = 0;
	int currentX = 1;
	int currentY = 0;
	conStack currentPath = NULL;

	/*Size Confirmation: Figures out how many columns and rows are in the maze.*/
	while (o[0] != '\0') {
		i.getline(o, 256);
		for (int i = 0; i > -1; i++) {
			if (o[i] == '\0') {
				break;
			}
			else {
				cols = i;
			}
		}

		rows++;
	}
	rows--;
	cols++;
	/*Uses size to fully initialize the stack such that it will not be too small.*/
	conStack cs = conStack(rows*cols);

	/*Instantiates the data representation of the maze in memory*/
	Cell **maze = new Cell *[rows];
	for (int index = 0; index < rows; index++) {
		maze[index] = new Cell[cols];
	}
	i.close();

	i.open(PATH);
	char values[256];
	/*Fills the data representation of the maze in memory with cells containing the appropriate symbols or empty space.*/
	for (int x = 0; x < rows; x++) {
		i.getline(values,256);
		for (int y = 0; y < cols; y++) {
			maze[x][y] = Cell(x, y, values[y], false, false);
		}
	}

	i.close();

	/*Final instantiations needed to complete the maze.
		Start is always the top left corner
		End is always the bottom right corner*/
	maze[1][0].setIsStart(true);
	maze[rows - 2][cols - 1].setIsEnd(true);
	currentPath = conStack(rows*cols);
	maze[currentX][currentY].setVisited();
	currentPath.push(maze[currentX][currentY]);


	/*The primary search function. Checks if current position is the end. If not, scans all adjacent cells for an unvisited position,
	prioritizing right, down, left, up in that order. Upon finding one, the current position moves to that cell, and the cell is added
	to the stack. If no adjacent cell is unvisted or available, the stack is popped and the current value moves backwards according
	to the stack's record until a cell with unvisited adjacent values is detected. This process will eventually find the path
	to the exit, providing a path exists.*/
	while (maze[currentX][currentY].getIsEnd() != true) {
		maze[currentX][currentY].setVisited();
		if (isValid('e', currentX, currentY, maze)) {
			currentY++;
			currentPath.push(maze[currentX][currentY]);
		}
		else if (isValid('s', currentX, currentY, maze)) {
			currentX++;
			currentPath.push(maze[currentX][currentY]);
		}
		else if (isValid('w', currentX, currentY, maze)) {
			currentY--;
			currentPath.push(maze[currentX][currentY]);
		}
		else if (isValid('n', currentX, currentY, maze)) {
			currentX--;
			currentPath.push(maze[currentX][currentY]);
		}
		else {
			currentPath.pop();
			currentX = currentPath.top().getXPosition();
			currentY = currentPath.top().getYPosition();
		}
	}

	/*For human readability, the value of the cells on the calculated path are changed to special character '#'.*/
	int replace = currentPath.getSize();
	for (int r = 0; r < replace; r++) {
		Cell rCell = currentPath.retieve();
		maze[rCell.getXPosition()][rCell.getYPosition()].setPathDisplay();
	}

	/*Printout function is called to display results.*/
	printSolution(maze, rows, cols);
	
	/*Maze and stack are deallocated and the program is halted to allow users to view results.*/
	delete [] maze;
	currentPath.destroy();
	_getch();
	return 0;
}
