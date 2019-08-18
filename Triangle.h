/**
*Purpose:
*Practice fundamental OOPs concepts
*Implement an inheritance hierarchy of classes
*Use C++ smart pointers
*/
#ifndef _Triangle_INCLUDED
#define _Triangle_INCLUDED
#include "Shape.h"
/**
*This class contains the implementation of Triangle class
*It inherit the Shape class
*/
class Triangle:public Shape {
public:
	/**
	*Constructor for Triangle class
	*@param name Name of Triangle
	*@param description Description of Triangle
	*/
	Triangle(string name, string description);
};

#endif
