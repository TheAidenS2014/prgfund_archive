//
// Written by TheAidenS2014
// Last modified 10/10/2024
// Functions file for Lab10b: "Point, Rectangle, and Cube classes"
//

#include "Lab10b_ShapeDetails.h"
#include <cmath>
//#include<iostream>


//
// `Point` class
//
void Point::setXValue(int user_x_value) { xValue = user_x_value; };
void Point::setYValue(int user_y_value) { yValue = user_y_value; };
int Point::getXValue() const { return xValue; };
int Point::getYValue() const { return yValue; };
// defaults to (0, 0)
Point::Point()
{
	xValue = 0;
	yValue = 0;
};
Point::Point(int user_x_value, int user_y_value)
{
	xValue = user_x_value;
	yValue = user_y_value;
};
double Point::calculateDistanceFromOrigin()
{
	// [x/y]f = [x/y]Value, [x/y]i = 0
	//
	//   /--------------------------
	// v/ (xf - xi)^2 + (yf - yi)^2
	//
	return (sqrt(pow((xValue - 0.0), 2) + pow((yValue - 0.0), 2)));
};


//
// `Rectangle` class
//
void Rectangle::setLength(double user_length) { length = user_length; };
void Rectangle::setWidth(double user_width) { width = user_width; };
double Rectangle::getLength() const { return length; };
double Rectangle::getWidth() const { return width; };
// defaults `length` and `width` to "0.0";
Rectangle::Rectangle()
{
	length = 0.0;
	width = 0.0;
};
Rectangle::Rectangle(double user_length, double user_width)
{
	length = user_length;
	width = user_width;
};
double Rectangle::calculateArea()
{
	return (length * width);
};
double Rectangle::calculatePerimeter()
{
	return ((2 * length) + (2 * width));
};


//
// `Cube` class
//
void Cube::setEdgeLength(double user_edge_length) { edgeLength = user_edge_length; };
double Cube::getEdgeLength() const { return edgeLength; };
// defaults `edgeLength` to "0.0"
Cube::Cube()
{
	edgeLength = 0;
};
Cube::Cube(double user_edge_length)
{
	edgeLength = user_edge_length;
};
double Cube::calculateSurfaceArea()
{
	// 4 sides per face, 6 sides
	return ((edgeLength * 4) * 6);
};
double Cube::calculateVolume()
{
	//return (edgeLength * edgeLength * edgeLength);
	return (pow(edgeLength, 3));
};

// Copyright 2024 TheAidenS2014