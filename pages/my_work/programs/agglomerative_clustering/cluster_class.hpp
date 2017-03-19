
/****************************************************************/
/* Programmer: Victoria Albanese                                */
/* Program Part 2: Cluster Header								*/
/* Program Description: This file contains all the includes     */
/*                      and class definitions to be included in */
/*                      the cluster class implementation and	*/
/*                      client files.							*/
/****************************************************************/


/****************************************************************/

// Header Guard

#ifndef CLUSTER_CLASS_HPP
#define CLUSTER_CLASS_HPP

/****************************************************************/

// Include Statements

#include <cmath>
#include "point_class.hpp" // included for point functionality

/****************************************************************/

// Namespace Declarations

using namespace std;

/****************************************************************/

// Class Declarations

// Cluster Class
// Represents a cluster of points
// Has members centroid, running_sum, cluster_size, and point_list
// and get, print, copy control, update, overloaded assignment operators,
// and get distance between clusters function
// Also is friends with the print point member function

class Cluster {

	/****************************************************************/

private:

	int cluster_size;
	vector<Point> point_list;
	int index;

	/****************************************************************/

public:

	// Constructor Functions
	Cluster() = default;
	Cluster(Point new_starting_point, int new_index);

	// Get Functions
	int get_cluster_size() { return cluster_size; }
	vector<Point> get_point_list() { return point_list; }
	int get_index() { return index; }

	// Print Function
	void print_cluster();

	// Copy Control Functions
	Cluster(const Cluster& rhs) = default;
	Cluster& operator=(const Cluster& rhs) = default;
	~Cluster() = default;

	// Update Functions
	void update_cluster_size(Cluster new_points);
	void update_point_list(Cluster new_points);
	void update_index(int new_index);

	// Get Distance Cluster Function
	double get_distance(Cluster rhs);

	// Overloaded Assignment Operators
	Cluster& operator+(Cluster& rhs);
	Cluster& operator+=(Cluster& rhs);

	// Friends
	friend void Point::print_point();

	/****************************************************************/

};

/****************************************************************/

#endif

/****************************************************************/
