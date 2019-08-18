#include "AcuteTriangle.h"

/**
*Constructor for shape Acute Triangle
*@param b Base of acute triangle
*@param name Name of Acute Triangle
*@param description Description of Acute Triangle
*/
AcuteTriangle::AcuteTriangle(int b, string name, string description) :b{ b }, Triangle(name, description){
	if (b % 2 == 0) {
		this->b = this->b + 1;
	}
	h = (this->b + 1) / 2;
}

/**
*Method to get Geometric Area of Acute Triangle
*@return Geometric Area
*/
float AcuteTriangle::geometricArea()const {
	float temp{ (float)(h * b) };
	float res{(float)(temp/2)};
	return res;
}

/**
*Method to get Geometric Parameter of Acute Triangle
*@return Geometric Parameter
*/
float AcuteTriangle::geometricParameter()const {
	float tempH{(float)(h)};
	float temp{(float)((0.25*b*b)+(tempH*tempH))};
	float temp2{ (float)(sqrt(temp)) };
	float res{b+(2*temp2)};
	return res;
}

/**
*Method to get Screen Area of Acute Triangle
*@return Screen Area
*/
int AcuteTriangle::screenArea()const {
	return (h * h);
}

/**
*Method to get Screen Parameter of Acute Triangle
*@return Screen Parameter
*/
int AcuteTriangle::screenParameter()const {
	return (4*(h-1));
}

/**
*Method to get Bounding height of Acute Triangle
*@return bounding height
*/
int AcuteTriangle::getBoundingHeight() const {
	return h;
}

/**
*Method to get Bounding Width of Acute Triangle
*@return bounding width
*/
int AcuteTriangle::getBoundingWidth()const {
	return b;
}

/**
*Method to draw a textual image of Acute Triangle on a two dimensional grid
*@param fChar Foreground character
*@param bChar Background character
*@return 2 dimentional grid
*/
vector<vector<char> > AcuteTriangle::draw(char fChar, char bChar)const {
	
	vector<vector<char>> wholeGrid;
	int secondChar{getBoundingHeight()-1};
	
	for (int i{ 1 }; i <= getBoundingHeight(); i++) {
		int firstChar{ 2 * i - 1 };
		vector<char> row;
		for (int j{ 0 }; j < secondChar; j++) {
			row.push_back(bChar);
		}
		for (int j{ 0 }; j < firstChar; j++) {
			row.push_back(fChar);
		}
		for (int j{ 0 }; j < secondChar; j++) {
			row.push_back(bChar);
		}
		secondChar--;
		wholeGrid.push_back(row);
	}
	return wholeGrid;
}

