#include "Space.h"

using namespace std;
/*Space is used to represent empty sectors in the city, preventing
null pointer problems.*/

/*Constructor*/
Space::Space(int xValue, int yValue) {
	this->symbol = "_";
	this->x = xValue;
	this->y = yValue;
}