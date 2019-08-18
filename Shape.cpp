#include "Shape.h"

/**
*Shape constructor
*@param name Name of shape
*@param description Description of shape
*/
Shape::Shape(string name, string description) :optionalName{ name }, optionalDescription{description} {
	static int count;
	count++;
	id = count;
}

/**
*Method to get the Id of shape
*@return id of shape
*/
int Shape::getId()const {
	return id;
}

/**
*Method to get the name of shape
*@return name of shape
*/
string Shape::getName()const {
	return optionalName;
}

/**
*Method to get the description of shape
*@return description of shape
*/
string Shape::getDescription()const {
	return optionalDescription;
}

/**
*Method to set name of shape
*@param name Name to be set
*/
void Shape::setName(string name) {
	optionalName = name;
}

/**
*Method to set description of shape
*@param description Description to be set
*/
void Shape::setDescription(string description) {
	optionalDescription = description;
}

/**
*Method to collect the information of shape in string
*@return string which contain information regarding shape
*/
string Shape::toString() const{
	std::ostringstream os;
	os << std::fixed << setprecision(2) << geometricArea();
	std::ostringstream os1;
	os1<< std::fixed << setprecision(2) << geometricParameter();
	string st{ "Shape Information \n-------------------------\nid:			" + to_string(getId()) + "\nShape name:		" + getName() + "\nDescription:		" + getDescription() + "\nB. box width:		" + to_string(getBoundingWidth()) + "\nB. box height:		" + to_string(getBoundingHeight()) + "\nScr area:		" + to_string(screenArea()) + "\nGeo area:		" + os.str()+ "\nScr perimeter:		" + to_string(screenParameter()) + "\nGeo perimeter:		" + os1.str() + "\nStatic type:		" + typeid(this).name() + "\nDynamic Type:		" + typeid(*this).name()+"\n" };
	return st;
}

/**
*Method to overload << operator
*@param os Ostream object
*@param sp Shape object
*@return ostream reference
*/
std::ostream& operator<<(std::ostream& os,Shape& sp) {
	os << sp.toString();
	return os;
}