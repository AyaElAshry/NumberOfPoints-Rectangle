#pragma once
#include "Point.h"


class Rectangle {
private:
	Point Upper_Right;
	Point Lower_Left;

public:
	//construct a rectangle with a value of 2 points
	Rectangle(Point P1, Point P2);

	//construct a rectangle with a value of xLower, yLower, xUpper, yUpper
	Rectangle(long x1, long y1, long x2, long y2);
	
	//set the value of the lower left point
	void set_Lower_Left(long x1, long y1);
	
	//set the value of the upper right point
	void set_Upper_Right(long x2, long y2);
	
	//Get the value of the x-coordinate of the upper right point
	long get_Upper_Right_X();
	
	//Get the value of the x-coordinate of the lower left point
	long get_Lower_Left_X();

	//Get the value of the y-coordinate of the upper right point
	long get_Upper_Right_Y();

	//Get the value of the y-coordinate of the lower left point
	long get_Lower_Left_Y();

};
