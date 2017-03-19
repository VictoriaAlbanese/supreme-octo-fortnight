
/****************************************************************/
/* Programmer: Victoria Albanese                                */
/* Program Part 2: Cuddle Puddle Header							*/
/* Program Description: This file contains all the includes     */
/*                      and class definitions to be included in */
/*                      the cuddle puddle class implementation 	*/
/*                      and client files.						*/
/****************************************************************/


/****************************************************************/

// Header Guard

#ifndef CUDDLE_PUDDLE_CLASS_HPP
#define CUDDLE_PUDDLE_CLASS_HPP

/****************************************************************/

// Include Statements

#include <list> // included for list functionality
#include <vector> // included for vector functionality

#include "cluster_class.hpp" // included for cluster functionality

/****************************************************************/

// Namespace Declarations

using namespace std;

/****************************************************************/

// Class Declarations

// Cuddle Puddle Class
// Represents an enviornment containing a bunch of clusters which can merge
// Has members 
// and get/set, print, copy control, and ...

class CuddlePuddle {

	/****************************************************************/

private:

	int min_clusters;
	list<Cluster> cluster_list;
	vector<vector<double>> cache;

	/****************************************************************/

public:

	// Constructor Functions
	CuddlePuddle() = default;
	CuddlePuddle(int new_min_clusters, list<Cluster> new_cluster_list);

	// Get/Set Functions
	int get_min_clusters() { return min_clusters; }
	void set_min_clusters(int new_min_clusters) { min_clusters = new_min_clusters; }
	list<Cluster> get_cluster_list() { return cluster_list; }
	void set_cluster_list(list<Cluster> new_cluster_list) { cluster_list = new_cluster_list; }

	// Print Function
	void print_cuddle_puddle();
	void print_cache();
	
	// Copy Control Functions
	CuddlePuddle(const CuddlePuddle& rhs) = default;
	CuddlePuddle& operator=(const CuddlePuddle& rhs) = default;
	~CuddlePuddle() = default;

	// Get Cluster from Cluster List
	Cluster get_cluster(int index);

	// Clump Closest Clusters
	void cuddle_closer();

	// Keep Clumping until the Minimum Number of Clusters are Left
	void max_cuddling_powers_activate();

	// Process Input
	void fill_cuddle_puddle();

	// Cache Functions
	void fill_cache();
	vector<int> search_cache();
	void update_cache(vector<int> indices);


	// Friends
	friend void Cluster::print_cluster();

	/****************************************************************/

};

/****************************************************************/

#endif

/****************************************************************/
