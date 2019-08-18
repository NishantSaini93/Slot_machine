/**
*Purpose:
*Practice fundamental OOPs concepts
*Implement an inheritance hierarchy of classes
*Use C++ smart pointers
*/
#ifndef _Rectangle_INCLUDED
#define _Rectangle_INCLUDED
#include "Shape.h"
/**
*This class contains the implementation of shape Rectangle
*It inherit Shape class
*/
class Rectangle:public Shape {
	/**
	*Variable for height of Rectangle
	*/
	int h{};
	/**
	*Variable for width of Rectangle
	*/
	int w{};
public:
	/**
	*Constructor for shape Rectangle
	*@param h Height of Rectangle
	*@param w width of Rectangle
	*@param name Name of Rectangle
	*@param description Description of Rectangle Shape
	*/
	Rectangle(int w,int h,string name="Four-sided", string description="Four right angles");
	/**
	*Method to get Geometric Area of Rectangle
	*@return Geometric Area
	*/
	virtual float geometricArea()const override;
	/**
	*Method to get Geometric Parameter of Rectangle
	*@return Geometric Parameter
	*/
	virtual float geometricParameter()const override;
	/**
	*Method to get Screen Area of Rectangle
	*@return Screen Area
	*/
	virtual int screenArea() const override;
	/**
	*Method to get Screen Parameter of Rectangle
	*@return Screen Parameter
	*/
	virtual int screenParameter()const override;
	/**
	*Method to draw a textual image of Rectangle on a two dimensional grid
	*@param fChar Foreground character
	*@param bChar Background character
	*@return 2 dimentional grid
	*/
	virtual vector<vector<char> > draw(char fChar = '*', char bChar = ' ')const override;
	/**
	*Method to get Bounding height of Rectangle
	*@return bounding height
	*/
	virtual int getBoundingHeight() const override;
	/**
	*Method to get Bounding Width of Rectangle
	*@return bounding width
	*/
	virtual int getBoundingWidth()const override;
};

#endif
