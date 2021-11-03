#include "Rectangle.h"

Rectangle::Rectangle(Point P1, Point P2) {
	this->Lower_Left = P1;
	this->Upper_Right = P2;
}

Rectangle::Rectangle(long x1, long y1, long x2, long y2)
{
	Lower_Left.setX(x1);
	Lower_Left.setY(y1);
	Upper_Right.setX(x2);
	Upper_Right.setY(y2);
}
void Rectangle::set_Lower_Left(long x1, long y1) {
	this->Lower_Left.setX(x1);
	this->Lower_Left.setY(y1);
}

void Rectangle::set_Upper_Right(long x2, long y2) {
	this->Upper_Right.setX(x2);
	this->Upper_Right.setY(y2);
}

long Rectangle::get_Upper_Right_X() {
	return Upper_Right.getX();
}

long Rectangle::get_Lower_Left_X() {
	return Lower_Left.getX();
}

long Rectangle::get_Upper_Right_Y() {
	return Upper_Right.getY();
}

long Rectangle::get_Lower_Left_Y() {
	return Lower_Left.getY();
}

