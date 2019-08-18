/**
*Purpose:
*Practice fundamental OOPs concepts
*Implement an inheritance hierarchy of classes
*Use C++ smart pointers
*/
#ifndef _Shape_INCLUDED
#define _Shape_INCLUDED
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include<typeinfo>
#include <sstream>
#include <memory>
using std::ostream;
using std::setprecision;
using std::to_string;
using std::vector;
using std::string;
using Grid=vector<vector<char>>;
/**
*This class is abstract class containing common properties of different shapes,hence is base class of other classes
*/
class Shape {
	/**
	*This variable contain unique id of every object created
	*/
	int id{};
	/**
	*Variable to contain option name for shapes
	*/
	string optionalName{};
	/**
	*Variable to contain optional description of shape
	*/
	string optionalDescription{};
public:
	/**
	*Shape constructor
	*@param name Name of shape
	*@param description Description of shape
	*/
	Shape(string name, string description);
	/**
	*Method to get the Id of shape
	*@return id of shape
	*/
	int getId()const;
	/**
	*Method to get the name of shape
	*@return name of shape
	*/
	string getName()const;
	/**
	*Method to get the description of shape
	*@return description of shape
	*/
	string getDescription()const;
	/**
	*Method to set name of shape
	*@param name Name to be set
	*/
	void setName(string name);
	/**
	*Method to set description of shape
	*@param description Description to be set
	*/
	void setDescription(string description);
	/**
	*Method to collect the information of shape in string
	*@return string which contain information regarding shape
	*/
	string toString() const;
	/**
	*Method to get Geometric Area of shape
	*@return Geometric Area
	*/
	virtual float geometricArea()const=0;
	/**
	*Method to get Geometric Parameter of shape
	*@return Geometric Parameter
	*/
	virtual float geometricParameter()const=0;
	/**
	*Method to get Screen Area of shape
	*@return Screen Area
	*/
	virtual int screenArea()const=0;
	/**
	*Method to get Screen Parameter of shape
	*@return Screen Parameter
	*/
	virtual int screenParameter()const=0;
	/**
	*Method to draw a textual image of shape on a two dimensional grid
	*@param fChar Foreground character
	*@param bChar Background character
	*@return 2 dimentional grid
	*/
	virtual vector<vector<char> > draw(char fChar = '*', char bChar = ' ')const = 0;
	/**
	*Method to get Bounding height of shape
	*@return bounding height
	*/
	virtual int getBoundingHeight() const=0;
	/**
	*Method to get Bounding Width of shape
	*@return bounding width
	*/
	virtual int getBoundingWidth()const =0;
	
};
/**
*Method to overload << operator
*@param os Ostream object
*@param sp Shape object
*@return ostream reference
*/
std::ostream& operator<<(std::ostream& os, Shape& sp);

#endif
