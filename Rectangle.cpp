#include "Rectangle.h"

/**
*Constructor for shape Rectangle
*@param h Height of Rectangle
*@param w width of Rectangle
*@param name Name of Rectangle
*@param description Description of Rectangle Shape
*/
Rectangle::Rectangle(int w, int h, string name, string description) :w{ w }, h{h}, Shape(name, description) {
}

/**
*Method to get Geometric Area of Rectangle
*@return Geometric Area
*/
float Rectangle::geometricArea()const {
	return(h*w);
}

/**
*Method to get Geometric Parameter of Rectangle
*@return Geometric Parameter
*/
float Rectangle::geometricParameter()const {
	return (2 * (h+w));
}

/**
*Method to get Screen Area of Rectangle
*@return Screen Area
*/
int Rectangle::screenArea()const {
	return (h*w);
}

/**
*Method to get Screen Parameter of Rectangle
*@return Screen Parameter
*/
int Rectangle::screenParameter()const {
	return ((2 * (h + w))-4);
}

/**
*Method to get Bounding height of Rectangle
*@return bounding height
*/
int Rectangle::getBoundingHeight()const {
	return h;
}

/**
*Method to get Bounding Width of Rectangle
*@return bounding width
*/
int Rectangle::getBoundingWidth()const {
	return w;
}

/**
*Method to draw a textual image of Rectangle on a two dimensional grid
*@param fChar Foreground character
*@param bChar Background character
*@return 2 dimentional grid
*/
vector<vector<char> > Rectangle::draw(char fChar, char bChar)const {
	vector<vector<char>> wholeGrid;
	for (int i{ 0 }; i < getBoundingHeight(); i++) {
		vector<char> row;
		for (int j{ 0 }; j < getBoundingWidth(); j++) {
			row.push_back(fChar);
		}
		wholeGrid.push_back(row);
	}
	return wholeGrid;
}
