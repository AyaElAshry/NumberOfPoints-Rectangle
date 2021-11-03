#include "Point.h"

Point::Point(long x1, long y1) {
	this->x = x1;
	this->y = y1;
}

void Point::setX(long x1) {
	this->x = x1;
}

void Point::setY(long y1) {
	this->y = y1;
}

long Point::getX() {
	return this->x;
}

long Point::getY() {
	return this->y;
}

void Point::print() {
	cout << "X= " << this->getX() << ", ";
	cout << "Y= " << this->getY() << endl;
}

/**************** Testing Point Class ******************/
void Point_Class()
{
	//create a point with default constructor 
	cout << "/*** Create a point with default constructor***/" << endl;
	Point p1;
	p1.print();

	cout << "/***Change the point x-coordinate value ***/" << endl;
	//change the point x-coordinate value using setX function
	p1.setX(10);
	cout << "the x-coordinate = " << p1.getX() << endl;

	cout << "Print the new  x and y-coordinates of a point" << endl;
	//check the new point values
	p1.print();

	cout << "/***Change the point y-coordinate value ***/" << endl;
	//change the point y-coordinate value
	p1.setY(30);
	cout << "the y-coordinate = " << p1.getY() << endl;

	cout << "Print the new  x and y-coordinates of a point" << endl;
	//check the new point values
	p1.print();
	system("pause");
}