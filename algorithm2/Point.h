#pragma once
#include <iostream> 

using namespace std;
/*
 Class of Point
 parameter x ==> the value of x-coordinate of the point
 parameter y ==> the value of y-coordinate of the point
*/
class Point {
private:
	long x;
	long y;
public:
	//construct a point with a value or default x-coordinate & y-coordinate
	Point(long x1 = 0, long y1 = 0);

	//Set the value of x-coordinate
	void setX(long x1);

	//Set the value of y-coordinate
	void setY(long y1);

	//Get the value of x-coordinate
	long getX();

	//Get the value of y-coordinate
	long getY();

	//Print the value for x and y-coordinates
	void print();

};
