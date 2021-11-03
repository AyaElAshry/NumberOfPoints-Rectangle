#include "utilities.h"
#include <iostream>
#include <fstream>
#include <string>

#include <time.h>
using namespace std;


int main() {

	//Declare the filename to be read
	string input_file;
	cout << "Enter the name of the input file" << endl;
	cin >> input_file;
	// Read from the text file
	ifstream MyReadFile(input_file);

	//Create a Map of key ==> (ID) and value ==> Rectangle.
	map<long, Rectangle> Rectangles;
	//Create a Vcetor of Points
	vector<Point> Points;

	//No such a file exists 
	if (!MyReadFile)
	{
		cout << "ERROR: no such a file " << endl;

	}
	else
	{
		if (isEmpty(MyReadFile))
		{
			cout << "ERROR: File is Empty!!" << endl;
		}
		else
		{
			//get the output file name
			string output_file;
			cout << "Enter the name for the output file" << endl;
			cin >> output_file;

			// Read the File and input data into a map of Rectangles & a vector of Points
			readFile(input_file, Rectangles, Points);

			//sort the vector of Points with respect to x-coordinates
			sort(Points.begin(), Points.end(), sortbyX);

			Points_count(output_file, Rectangles, Points);

			// Close the input file
			MyReadFile.close();
		}

	}
	return 0;
}