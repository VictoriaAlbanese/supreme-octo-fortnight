
/****************************************************************/
/* Programmer: Victoria Albanese                                */
/* Project Part 2: Point Header									*/
/* Program Description: This file contains all the includes     */
/*                      and class definitions to be included in */
/*                      the point class implementation and		*/
/*                      client files.							*/
/****************************************************************/


/****************************************************************/

// Header Guard

#ifndef POINT_CLASS_HPP
#define POINT_CLASS_HPP

/****************************************************************/

// Include Statements

#include <vector> // included for vector functionality

/****************************************************************/

// Namespace Declarations

using namespace std;

/****************************************************************/

// Class Declarations

// Point Class
// Representative of just a point
// Has members num_dimensions and coordinates
// and get/set, print, and copy control functions

class Point {

	/****************************************************************/

private:

	int num_dimensions;
	vector<double> coordinates;

	/****************************************************************/

public:

	// Constructor Functions
	Point() = default;
	Point(int new_num_dimensions);
	Point(vector<double> new_coordinates);

	// Get/Set Functions
	int get_num_dimensions() { return num_dimensions; }
	void set_num_dimensions(int new_num_dimensions) { num_dimensions = new_num_dimensions; }
	double get_coordinate(int index) { return coordinates.at(index); }
	void set_coordinate(double new_coordinate) { coordinates.push_back(new_coordinate); }

	void remove_coordinate() { coordinates.pop_back(); }

	// Print Function
	void print_point();

	// Get Distance Cluster Function
	double get_distance(Point rhs);

	// Copy Control Functions
	Point(const Point& rhs) = default;
	Point& operator=(const Point& rhs) = default;
	~Point() = default;

	/****************************************************************/

};

/****************************************************************/

#endif

/****************************************************************/
