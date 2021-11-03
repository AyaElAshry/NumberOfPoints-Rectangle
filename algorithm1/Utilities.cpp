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


bool sortbyX(Point &a, Point &b)
{
	return (a.getX() < b.getX());
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


void Points_count(string outputfile, map<long, Rectangle> &Rects, vector <Point> &Pts)
{
	//Declare the output file
	ofstream result;
	result.open(outputfile);

	long count = 0;
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
				for (auto j = 0; j < Pts.size(); j++)
				{
					if (Pts[j].getX() >= i->second.get_Lower_Left_X() && Pts[j].getX() <= i->second.get_Upper_Right_X()
						&& Pts[j].getY() >= i->second.get_Lower_Left_Y() && Pts[j].getY() <= i->second.get_Upper_Right_Y())
					{
						count++;
					}
					if (Pts[j].getX() > i->second.get_Upper_Right_X())
					{
						break;
					}

				}
				result << i->first << "   " << count << endl;
			}


		}
	}
	// Close the output file
	result.close();
}