
/****************************************************************/
/* Programmer: Victoria Albanese                                */
/* Project Part 2: Point Implementation							*/
/* Program Description: This file contains the implementations  */
/*                      of all the member functions of the		*/
/*                      point classes to be	included in the  	*/
/*                      client code file.						*/
/****************************************************************/


/****************************************************************/

// Include Statements

#include <iostream> // included for in/output functionality
#include <cmath> // included for power function functionality

#include "point_class.hpp" // included for point functionality

/****************************************************************/

// Namespace Declarations

using namespace std;

/****************************************************************/

// Class Declarations

// Point Class
// Representative of just a point
// Has members num_dimensions and coordinates
// and get/set, print, and copy control functions

	/****************************************************************/

	// Constructor Functions

	Point::Point(int new_num_dimensions) {
		num_dimensions = new_num_dimensions;
	}

	Point::Point(vector<double> new_coordinates) {
		num_dimensions = new_coordinates.size();
		coordinates = new_coordinates;
	}

	/****************************************************************/

	// Get Distance Between Two Points

	double Point::get_distance(Point rhs) {

		double distance = 0;

		for (int i = 0; i < rhs.get_num_dimensions(); i++) {
			distance += pow(this->get_coordinate(i) - rhs.get_coordinate(i), 2);
		}

		distance = pow(distance, 0.5);

		return distance;

	}

	/****************************************************************/

	// Print Function

	void Point::print_point() {

		cout << "( ";

		for (int i = 0; i < num_dimensions; i++) {

			if (i != num_dimensions - 1) {
				cout << get_coordinate(i) << ", ";
			}

			else {
				cout << get_coordinate(i);
			}

		}

		cout << " )" << endl;

	}

	/****************************************************************/

/****************************************************************/
