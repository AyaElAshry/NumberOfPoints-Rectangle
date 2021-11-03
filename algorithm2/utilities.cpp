#include "utilities.h"
#include <fstream>
#include <string>
#include <sstream>

template <size_t N>
void splitString(long(&arr)[N], string str)
{
	int n = 0;
	istringstream iss(str);
	for (auto it = istream_iterator<long>(iss); it != istream_iterator<long>() && n < N; ++it, ++n)
		arr[n] = *it;
}

bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void readFile(string filename, map<long, Rectangle> &Rects, vector <Point> &Pts)
{
	// Create a text string, which is used to output the text file
	string myText;

	string type = "";

	long Rectangle_dimensions[5] = { 0,0,0,0,0 };
	long Point_coordinates[3] = { 0,0,0 };

	ifstream infile(filename);
	// Read the File and input data into a map of Rectangles & a vector of Points
	// Use a while loop together with the getline() function to read the file line by line
	while (getline(infile, myText)) {
		// Output the text from the file
		if (myText == "RECTANGLES")
		{
			type = "RECTANGLES";
		}
		else if (myText == "POINTS")
		{
			type = "POINTS";

		}
		else
		{
			if (type == "RECTANGLES")
			{
				splitString(Rectangle_dimensions, myText);
				Rects.insert({ Rectangle_dimensions[0],{Rectangle_dimensions[1],
					Rectangle_dimensions[2],Rectangle_dimensions[3],Rectangle_dimensions[4]} });
			}
			else if (type == "POINTS")
			{
				splitString(Point_coordinates, myText);
				Pts.push_back({ Point_coordinates[1],Point_coordinates[2] });
			}
		}
	}
}

bool sortbyX(Point &a, Point &b)
{
	return (a.getX() < b.getX());
}

bool sortbyY(Point &a, Point &b)
{
	return (a.getY() < b.getY());
}

long BinarySearch_Point_xLowerBound(vector <Point> &vect, long low, long high, long key)
{
	// low ==> lower bound of the vector searched
	// high ==> upper bound of the vector searched
	// key ==> lower x-coordinate in the Rectangle

	if (low > high)
		return low;
	long mid = low + ((high - low) / 2);
	if (mid < vect.size())
	{
		//go left for lower bound 
		if (vect[mid].getX() >= key)
			return BinarySearch_Point_xLowerBound(vect, low, mid - 1, key);
		else
			return BinarySearch_Point_xLowerBound(vect, mid + 1, high, key);
	}


}

long BinarySearch_Point_xUpperBound(vector <Point> &vect, long low, long high, long key) {
	// low ==> lower bound of the vector searched
	// high ==> upper bound of the vector searched
	// key ==> Upper x-coordinate in the Rectangle
	if (low > high)
		return low;
	long mid = low + ((high - low) / 2);
	if (mid < vect.size())
	{
		//go left for lower bound 
		if (vect[mid].getX() > key)
			return BinarySearch_Point_xUpperBound(vect, low, mid - 1, key);
		else
			return BinarySearch_Point_xUpperBound(vect, mid + 1, high, key);
	}
}

long BinarySearch_Point_yLowerBound(vector <Point> &vect, long low, long high, long key) {
	// low ==> lower bound of the vector searched
	// high ==> upper bound of the vector searched
	// key ==> lower y-coordinate in the Rectangle

	if (low > high)
		return low;
	long mid = low + ((high - low) / 2);

	//go left for lower bound 
	if (mid < vect.size())
	{
		if (vect[mid].getY() >= key)
			return BinarySearch_Point_yLowerBound(vect, low, mid - 1, key);
		else
			return BinarySearch_Point_yLowerBound(vect, mid + 1, high, key);
	}
}

long BinarySearch_Point_yUpperBound(vector <Point> &vect, long low, long high, long key) {
	// low ==> lower bound of the vector searched
	// high ==> upper bound of the vector searched
	// key ==> Upper y-coordinate in the Rectangle
	if (low > high)
		return low;
	long mid = low + ((high - low) / 2);
	if (mid < vect.size())
	{
		//go left for lower bound 
		if (vect[mid].getY() > key)
			return BinarySearch_Point_yUpperBound(vect, low, mid - 1, key);
		else
			return BinarySearch_Point_yUpperBound(vect, mid + 1, high, key);
	}
}

void Points_count(string outputfile, map<long, Rectangle> &Rects, vector <Point> &Pts)
{
	//Declare the output file
	ofstream result;
	result.open(outputfile);

	long count = 0;

	long xLower = 0, xUpper = 0, yLower = 0, yUpper = 0;

	vector <Point> temp;

	if (Rects.size() == 0)
	{
		cout << "There is no rectangles inserted!" << endl;
	}
	else
	{
		for (auto i = Rects.begin(); i != Rects.end(); i++)
		{
			//Initialze the count for every rectangle search
			count = 0;
			if (Pts.size() == 0)
			{
				cout << "There is no points to be included!" << endl;
			}
			else
			{
				//Binary Search on vector of sorted POINTS (w.r.t x-coordinates) to get points included in the x-range 
				xLower = BinarySearch_Point_xLowerBound(Pts, 0, Pts.size(), i->second.get_Lower_Left_X());
				xUpper = BinarySearch_Point_xUpperBound(Pts, xLower, Pts.size(), i->second.get_Upper_Right_X());

				//if there is no points that satisfy the x-range of a rectangle 
				if (xLower == Pts.size() && xUpper == Pts.size())
				{
					count = 0;
				}
				else
				{
					//copy the points included in the range in a new temp vector 
					for (int j = xLower; j <= xUpper - 1; j++)
					{
						temp.push_back(Pts[j]);
					}

					//sort the vector of rectangles with respect to y-coordinates
					sort(temp.begin(), temp.end(), sortbyY);

					//Binary Search on vector of sorted POINTS (w.r.t y-coordinates) to get points included in the x-range 
					yLower = BinarySearch_Point_yLowerBound(temp, 0, temp.size(), i->second.get_Lower_Left_Y());
					yUpper = BinarySearch_Point_yUpperBound(temp, 0, temp.size(), i->second.get_Upper_Right_Y());

					if (yLower >= yUpper)
						count = 0;
					else
						count = ((yUpper - 1) - yLower) + 1;

					//Clear the temp vector to be used for another rectangle
					temp.clear();
				}
				result << i->first << "   " << count << endl;

			}
		}

	}
	// Close the output file
	result.close();

}