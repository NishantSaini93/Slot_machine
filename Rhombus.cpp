#include "Rhombus.h"

/**
*Constructor for Rombus class
*@param d Side of Rhombus object
*@param name Name of Rhombus object
*@param description Description of Rhombus object
*/
Rhombus::Rhombus(int d, string name, string description) :d{d}, Shape(name, description){
	if ((this->d) % 2 == 0) {
		this->d = this->d + 1;
	}
	
}

/**
*Method to get Geometric Area of Rhombus
*@return Geometric Area
*/
float Rhombus::geometricArea()const {
	float temp{(float) d * d };
	float res{ temp / 2 };
	return res;
}

/**
*Method to get Geometric Parameter of Rhombus
*@return Geometric Parameter
*/
float Rhombus::geometricParameter()const {
	float temp{(float)sqrt(2)};
	float res{2*temp*d};
	return res;
}

/**
*Method to get Screen Area of Rhombus
*@return Screen Area
*/
int Rhombus::screenArea()const {
	int n{(int)(d/2)};
	return (2*n*(n+1)+1);
}

/**
*Method to get Screen Parameter of Rhombus
*@return Screen Parameter
*/
int Rhombus::screenParameter()const {
	return (2*(d-1));
}

/**
*Method to get Bounding height of Rhombus
*@return bounding height
*/
int Rhombus::getBoundingHeight()const{
	return d;
}

/**
*Method to get Bounding Width of Rhombus
*@return bounding width
*/
int Rhombus::getBoundingWidth()const {
	return d;
}

/**
*Method to draw a textual image of Rhombus on a two dimensional grid
*@param fChar Foreground character
*@param bChar Background character
*@return 2 dimentional grid
*/
vector<vector<char> > Rhombus:: draw(char fChar, char bChar)const {
	vector<vector<char>> wholeGrid;
	int secondChar{(int) getBoundingHeight()/2 };

	for (int i{ 1 }; i <= ((int)(getBoundingHeight()/2)+1); i++) {
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
	secondChar = 1;
	for (int i{ (int)(getBoundingHeight()/2) }; i > 0; i--) {
		vector<char> row;
		int first{2*i-1};
		for(int j{ 0 }; j < secondChar; j++) {
			row.push_back(bChar);
		}
		for (int j{ 0 }; j < first; j++) {
			row.push_back(fChar);
		}
		for (int j{ 0 }; j < secondChar; j++) {
			row.push_back(bChar);
		}
		wholeGrid.push_back(row);
		secondChar++;
	}
	
	return wholeGrid;
}
