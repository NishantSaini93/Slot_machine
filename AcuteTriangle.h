/**
*Purpose:
*Practice fundamental OOPs concepts
*Implement an inheritance hierarchy of classes
*Use C++ smart pointers
*/
#ifndef _AcuteTriangle_INCLUDED
#define _AcuteTriangle_INCLUDED
#include "Triangle.h"
using std::vector;
using std::string;
/**
*This class contain the imlplementation of Acute Triangle shape
*It inherit Triangle class
*/
class AcuteTriangle:public Triangle {
	/**
	*Variable for base of Acute Triangle
	*/
	int b{};
	/**
	*Variable for height of Acute Triangle
	*/
	int h{};
public:
	/**
	*Constructor for shape Acute Triangle
	*@param b Base of acute triangle
	*@param name Name of Acute Triangle
	*@param description Description of Acute Triangle
	*/
	AcuteTriangle(int b, string name = "Acute triangle", string description = "All acute angles");
	/**
	*Method to get Geometric Area of Acute Triangle
	*@return Geometric Area
	*/
	virtual float geometricArea() const override;
	/**
	*Method to get Geometric Parameter of Acute Triangle
	*@return Geometric Parameter
	*/
	virtual float geometricParameter() const override;
	/**
	*Method to get Screen Area of Acute Triangle
	*@return Screen Area
	*/
	virtual int screenArea() const override;
	/**
	*Method to get Screen Parameter of Acute Triangle
	*@return Screen Parameter
	*/
	virtual int screenParameter()const override;
	/**
	*Method to draw a textual image of Acute Triangle on a two dimensional grid
	*@param fChar Foreground character 
	*@param bChar Background character
	*@return 2 dimentional grid
	*/
	virtual vector<vector<char> > draw(char fChar = '*', char bChar = ' ')const override;
	/**
	*Method to get Bounding height of Acute Triangle
	*@return bounding height
	*/
	virtual int getBoundingHeight() const override;
	/**
	*Method to get Bounding Width of Acute Triangle
	*@return bounding width
	*/
	virtual int getBoundingWidth()const override;
};

#endif
