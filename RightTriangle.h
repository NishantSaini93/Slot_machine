/**
*Purpose:
*Practice fundamental OOPs concepts
*Implement an inheritance hierarchy of classes
*Use C++ smart pointers
*/
#ifndef _RightTriangle_INCLUDED
#define _RightTriangle_INCLUDED
#include "Triangle.h"
/**
*This class contains implementation Right Triangle
*It inherit Triangle Class
*/
class RightTriangle:public Triangle{
	/**
	*Variable for base of Right Triangle
	*/
	int b{};
	/**
	*Variable for height of Right Triangle
	*/
	int h{};
public:
	/**
	*Constructor for Right Triangle
	*@param b Base of Right Triangle
	*@param name Name of Right Triangle
	*@param description Description of Right Triangle
	*/
	RightTriangle(int b, string name = "Right Triangle", string description = "One right and two acute angles");
	/**
	*Method to get Geometric Area of Right Triangle
	*@return Geometric Area
	*/
	virtual float geometricArea()const override;
	/**
	*Method to get Geometric Parameter of Right Triangle
	*@return Geometric Parameter
	*/
	virtual float geometricParameter()const override;
	/**
	*Method to get Screen Area of Right Triangle
	*@return Screen Area
	*/
	virtual int screenArea()const override;
	/**
	*Method to get Screen Parameter of Right Triangle
	*@return Screen Parameter
	*/
	virtual int screenParameter()const override;
	/**
	*Method to draw a textual image of Right Triangle on a two dimensional grid
	*@param fChar Foreground character
	*@param bChar Background character
	*@return 2 dimentional grid
	*/
	virtual vector<vector<char> > draw(char fChar = '*', char bChar = ' ')const override;
	/**
	*Method to get Bounding height of Right Triangle
	*@return bounding height
	*/
	virtual int getBoundingHeight()const override;
	/**
	*Method to get Bounding Width of Right Triangle
	*@return bounding width
	*/
	virtual int getBoundingWidth()const override;
};
#endif
