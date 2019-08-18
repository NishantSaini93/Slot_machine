/**
*Purpose:
*Practice fundamental OOPs concepts
*Implement an inheritance hierarchy of classes
*Use C++ smart pointers
*/
#ifndef _Rhombus_INCLUDED
#define _Rhombus_INCLUDED
#include "Shape.h"
/**
*Implementation of Class Rhombus
*It inherit the Shape class
*/
class Rhombus:public Shape {
	/**
	*Variable for side of Rhombus
	*/
	int d;
public:
	/**
	*Constructor for Rombus class
	*@param d Side of Rhombus object
	*@param name Name of Rhombus object
	*@param description Description of Rhombus object
	*/
	Rhombus(int d,string name="Diamond", string description="A parallelogram with equal sides");
	/**
	*Method to get Geometric Area of Rhombus
	*@return Geometric Area
	*/
	virtual float geometricArea()const override;
	/**
	*Method to get Geometric Parameter of Rhombus
	*@return Geometric Parameter
	*/
	virtual float geometricParameter()const override;
	/**
	*Method to get Screen Area of Rhombus
	*@return Screen Area
	*/
	virtual int screenArea()const override;
	/**
	*Method to get Screen Parameter of Rhombus
	*@return Screen Parameter
	*/
	virtual int screenParameter()const override;
	/**
	*Method to draw a textual image of Rhombus on a two dimensional grid
	*@param fChar Foreground character
	*@param bChar Background character
	*@return 2 dimentional grid
	*/
	virtual vector<vector<char> > draw(char fChar = '*', char bChar = ' ')const override;
	/**
	*Method to get Bounding height of Rhombus
	*@return bounding height
	*/
	virtual int getBoundingHeight() const override;
	/**
	*Method to get Bounding Width of Rhombus
	*@return bounding width
	*/
	virtual int getBoundingWidth()const override;
};

#endif
