#pragma once
#include "Rectangle.h"
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>

template <size_t N>
// function to cut string into an array of datatype long 
void splitString(long(&arr)[N], string str);

//Driver to read file a put into a map of Rectangles & a vector of Points
void readFile(string filename, map<long, Rectangle> &Rects, vector <Point> &Pts);

//function returns true if a file is empty
bool isEmpty(std::ifstream& pFile);

// Driver function to sort the vector of Points with rescpect to x-coordinate
bool sortbyX(Point &a, Point &b);

// Driver function to sort the vector of Points with rescpect to y-coordinate
bool sortbyY(Point &a, Point &b);

// Function to Binary Search for the Lower Bound x-coordinate that can be included within a rectangle 
long BinarySearch_Point_xLowerBound(vector <Point> &vect, long low, long high, long key);

// Function to Binary Search for the Upper Bound x-coordinate that can be included within a rectangle 
long BinarySearch_Point_xUpperBound(vector <Point> &vect, long low, long high, long key);

// Function to Binary Search for the Lower Bound y-coordinate that can be included within a rectangle 
long BinarySearch_Point_yLowerBound(vector <Point> &vect, long low, long high, long key);

// Function to Binary Search for the Upper Bound y-coordinate that can be included within a rectangle 
long BinarySearch_Point_yUpperBound(vector <Point> &vect, long low, long high, long key);

// Driver to count the number of points included within a rectangle
void Points_count(string outputfile, map<long, Rectangle> &Rects, vector <Point> &Pts);