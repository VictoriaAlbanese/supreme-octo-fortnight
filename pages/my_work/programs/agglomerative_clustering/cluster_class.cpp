
/****************************************************************/
/* Programmer: Victoria Albanese                                */
/* Project Part 2: Cluster Implementation			*/
/* Program Description: This file contains the implementations  */
/*                      of all the member functions of the	*/
/*                      cluster classes to be included in the  	*/
/*                      client code file.			*/
/****************************************************************/

// Include Statements
#include <iostream>
#include "point_class.hpp" 
#include "cluster_class.hpp" 

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

	/****************************************************************/

	// Constructor Functions
	
	Cluster::Cluster(Point new_starting_point, int new_index) {
	
		cluster_size = 1; 
		point_list.push_back(new_starting_point);
		index = new_index;

	}

	/****************************************************************/

	// Print Function
	
	void Cluster::print_cluster() {

		cout << endl;
		cout << "# Cluster " << index << " has points..." << endl;
		for (int i = 0; i < cluster_size; i++) {
			cout << "\t\t";
			point_list.at(i).print_point();
		}

	}

	/****************************************************************/

	// Update Functions
	
	void Cluster::update_cluster_size(Cluster new_points) {
	
		cluster_size += new_points.cluster_size;
	
	}

	void Cluster::update_point_list(Cluster new_points) {
	
		for (int i = 0; i < new_points.cluster_size; i++) {
			point_list.push_back(new_points.point_list.at(i));
		}
	
	}

	void Cluster::update_index(int new_index) {
		index = new_index;
	}

	/****************************************************************/
	
	// Get Distance Between Two Points
	
	double Cluster::get_distance(Cluster rhs) {

		double master_distance = 0;

		for (int i = 0; i < cluster_size; i++) {

			for (int j = 0; j < rhs.cluster_size; j++) {

				master_distance += point_list.at(i).get_distance(rhs.point_list.at(j));

			}

		}

		master_distance /= (cluster_size * rhs.cluster_size);

		return master_distance;

	}

	/****************************************************************/

	// Overloaded Assignment Operators

	Cluster& Cluster::operator + (Cluster& rhs) {
	
		this->update_point_list(rhs);
		this->update_cluster_size(rhs);
		rhs.index = -1;

		return *this;
	
	}
	
	Cluster& Cluster::operator+=(Cluster& rhs) {
	
		return *this + rhs;
	
	}
	
	/****************************************************************/

/****************************************************************/
