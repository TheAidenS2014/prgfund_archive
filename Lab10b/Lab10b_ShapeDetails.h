//
// Written by TheAidenS2014
// Last modified 10/10/2024
// Header file for Lab10b: "Point, Rectangle, and Cube classes"
//

#pragma once

class Point
{
private:
	int xValue, yValue;
public:
	void setXValue(int user_x_value);
	void setYValue(int user_y_value);
	int getXValue() const;
	int getYValue() const;
	Point();
	Point(int user_x_value, int user_y_value);
	double calculateDistanceFromOrigin();
};

class Rectangle
{
private:
	double length, width;
public:
	void setLength(double user_length);
	void setWidth(double user_width);
	double getLength() const;
	double getWidth() const;
	Rectangle();
	Rectangle(double user_length, double user_width);
	double calculateArea();
	double calculatePerimeter();
};

class Cube
{
private:
	double edgeLength;
public:
	void setEdgeLength(double user_edge_length);
	double getEdgeLength() const;
	Cube();
	Cube(double user_edge_length);
	double calculateSurfaceArea();
	double calculateVolume();
};

// Copyright 2024 TheAidenS2014