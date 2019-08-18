#include "RightTriangle.h"

/**
*Constructor for Right Triangle
*@param b Base of Right Triangle
*@param name Name of Right Triangle
*@param description Description of Right Triangle
*/
RightTriangle::RightTriangle(int b, string name , string description) :b{ b }, Triangle(name, description){
	h = b;
}

/**
*Method to get Geometric Area of Right Triangle
*@return Geometric Area
*/
float RightTriangle::geometricArea()const {
	float temp{(float)(h*b)};
	float res{temp/2};
	return res;
}

/**
*Method to get Geometric Parameter of Right Triangle
*@return Geometric Parameter
*/
float RightTriangle::geometricParameter()const {
	float temp{(float)sqrt(2)};
	float res{(2+temp)*h};
	return res;
}

/**
*Method to get Screen Area of Right Triangle
*@return Screen Area
*/
int RightTriangle::screenArea()const {
	return ((h * (h+1))/2);
}

/**
*Method to get Screen Parameter of Right Triangle
*@return Screen Parameter
*/
int RightTriangle::screenParameter()const {
	return (3 *( h - 1));
}

/**
*Method to get Bounding height of Right Triangle
*@return bounding height
*/
int RightTriangle::getBoundingHeight()const {
	return h;
}

/**
*Method to get Bounding Width of Right Triangle
*@return bounding width
*/
int RightTriangle::getBoundingWidth() const{
	return b;
}

/**
*Method to draw a textual image of Right Triangle on a two dimensional grid
*@param fChar Foreground character
*@param bChar Background character
*@return 2 dimentional grid
*/
vector<vector<char> > RightTriangle::draw(char fChar, char bChar)const {
	vector<vector<char>> wholeGrid;
	int count{ 1 };
	int horizontalCount{getBoundingWidth()-1};
	for (int i{ 0 }; i < getBoundingHeight(); i++) {
		vector<char> row;
		for (int j{ 0 }; j < count; j++) {
			row.push_back(fChar);
		}
		for (int j{ 0 }; j < horizontalCount; j++) {
			row.push_back(bChar);
		}
		count++;
		horizontalCount--;
		wholeGrid.push_back(row);
	}
	return wholeGrid;
}

