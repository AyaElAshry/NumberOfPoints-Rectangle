#pragma once
#include "Rectangle.h"
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>

template <size_t N>
void splitString(long(&arr)[N], string str);

// Driver function to sort the vector of Points with rescpect to x-coordinate
bool sortbyX(Point &a, Point &b);

//function returns true if a file is empty
bool isEmpty(std::ifstream& pFile);

//Driver to read file a put into a map of Rectangles & a vector of Points
void readFile(string filename, map<long, Rectangle> &Rects, vector <Point> &Pts);

// Driver to count the number of points included within a rectangle
void Points_count(string outputfile, map<long, Rectangle> &Rects, vector <Point> &Pts);