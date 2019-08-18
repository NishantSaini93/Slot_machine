/**
*Purpose:
*Practice fundamental OOPs concepts
*Implement an inheritance hierarchy of classes
*Use C++ smart pointers
*/
#ifndef _SlotMachine_INCLUDED
#define _SlotMachine_INCLUDED
#include<array>
#include "Shape.h"
#include "Rhombus.h"
#include "Rectangle.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
#include<random>
using std::array;
using std::cout;

/**
*This class contain the implementation of Slot Machine
*/
class SlotMachine
{
	/**
	*Container for three object of shapes
	*/
	array<std::unique_ptr<Shape>, 3> reel{};
	/**
	*Method for starting the creation process of three objects pf shapes
	*/
	void make_shapes();
	/**
	*Mehod where actual shapes object is made
	*/
	void make_shape(int k);
	/**
	*Method to draw the three objects
	*/
	void display();
public:
	/**
	*Defaulted Constructor
	*/
	SlotMachine() = default;
	/**
	*Deleted default copy constructor
	*/
	SlotMachine(const SlotMachine&) = delete;
	/**
	*Deleted move constructor
	*/
	SlotMachine(SlotMachine&&) = delete;
	/**
	*Deleted copy assignment
	*/
	SlotMachine& operator=(const SlotMachine&) = delete;
	/**
	*Deleted move assignment
	*/
	SlotMachine& operator=(SlotMachine&&) = delete;
	/**
	*Defaulted destructor
	*/
	virtual ~SlotMachine()=default;
	/**
	*Method containing running procedure of slot machine
	*/
	void run();
};

#endif
