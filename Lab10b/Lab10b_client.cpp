//
// Written by TheAidenS2014
// Last modified 10/14/2024
// 
// Lab10b: "Point, Rectangle, and Cube classes"
// Creates six objects using three classes,
// does some simple calculations, and then
// displays that data to the terminal
//

#include "Lab10b_ShapeDetails.h"
#include <iostream>
#include <iomanip>
#include <random>
using std::cout;
using std::endl;

// as toad would say
// "yahoo!"
int getRandInt()
	{ return (rand() % 50); }
double getRandDouble()
	{ return (rand() % 50); }

int main()
{
	srand(time(0));

	// create and define `Point` objects
	Point theSpecialPosition{ getRandInt(), getRandInt() };
	Point theUncoolPosition;
	theUncoolPosition.setXValue(getRandInt());
	theUncoolPosition.setYValue(getRandInt());

	// create and define `Rectangle` objects
	Rectangle thePremiumRectangle{ getRandDouble(), getRandDouble() };
	Rectangle theWonderfulRectangle;
	theWonderfulRectangle.setLength(getRandDouble());
	theWonderfulRectangle.setWidth(getRandDouble());

	// create `Cube` objects
	Cube theMightyCube{ getRandDouble() };
	Cube theTerrificCube;
	theTerrificCube.setEdgeLength(getRandDouble());

	// show all member data
	cout << "Position #1 is at (" << theSpecialPosition.getXValue() << ", " << theSpecialPosition.getYValue() << ")\n"
		 << "Position #2 is at (" << theUncoolPosition.getXValue() << ", " << theUncoolPosition.getYValue() << ")\n"
		 << endl;
	cout << "Rectangle #1 has a length of " << thePremiumRectangle.getLength() << " and a width of " << thePremiumRectangle.getWidth() << "\n"
		 << "Rectangle #2 has a length of " << theWonderfulRectangle.getLength() << " and a width of " << theWonderfulRectangle.getWidth() << "\n"
		 << endl;
	cout << "Cube #1 have edge lengths of " << theMightyCube.getEdgeLength() << "\n"
		 << "Cube #2 have edge lengths of " << theTerrificCube.getEdgeLength() << "\n"
		 << endl;

	// show distance from origin for both points
	cout << "Distance from origin:"
		 << std::fixed << std::setprecision(2)
		 << "\n- Position #1 is " << theSpecialPosition.calculateDistanceFromOrigin() << " units away"
		 << "\n- Position #2 is " << theUncoolPosition.calculateDistanceFromOrigin() << " units away"
		 << endl;

	// show area and peri. for both rects
	cout << "\nAreas"
		 << std::fixed << std::setprecision(0)
		 << "\n- Rectangle #1: " << thePremiumRectangle.calculateArea() << " units"
		 << "\n- Rectangle #2: " << theWonderfulRectangle.calculateArea() << " units"
		 << endl;
	cout << "Perimeters"
		 << std::fixed << std::setprecision(0)
		 << "\n- Rectangle #1: " << thePremiumRectangle.calculatePerimeter() << " units"
		 << "\n- Rectangle #2: " << theWonderfulRectangle.calculatePerimeter() << " units"
		 << endl;

	// show surf. area and volume for both cubes
	cout << "\nSurface Areas"
		 << std::fixed << std::setprecision(0)
		 << "\n- Cube #1: " << theMightyCube.calculateSurfaceArea() << " units"
		 << "\n- Cube #2: " << theTerrificCube.calculateSurfaceArea() << " units"
		 << endl;
	cout << "Volumes"
		<< std::fixed << std::setprecision(0)
		<< "\n- Cube #1: " << theMightyCube.calculateVolume() << " units"
		<< "\n- Cube #2: " << theTerrificCube.calculateVolume() << " units"
		<< endl;
}

// Copyright 2024 TheAidenS2014