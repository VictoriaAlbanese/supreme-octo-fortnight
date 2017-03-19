
/****************************************************************/
/* Programmer: Victoria Albanese                                */
/* Program Part 2: Cuddle Puddle Header							*/
/* Program Description: This file contains all the includes     */
/*                      and class definitions to be included in */
/*                      the cuddle puddle class implementation 	*/
/*                      and client files.						*/
/****************************************************************/


/****************************************************************/

// Include Statements

#include <list> // included for list functionality
#include <string> // included for string functionality
#include <climits> // included for limit functionality
#include <iostream> // included for in/output functionality

#include "cuddle_puddle_class.hpp" // included for cluster functionality

/****************************************************************/

// Namespace Declarations

using namespace std;

/****************************************************************/

// Class Declarations

// Cuddle Puddle Class
// Represents an enviornment containing a bunch of clusters which can merge
// Has members 
// and get/set, print, copy control, and ...

	/****************************************************************/

	// Constructor Functions

	CuddlePuddle::CuddlePuddle(int new_min_clusters, list<Cluster> new_cluster_list) {

		min_clusters = new_min_clusters;
		cluster_list = new_cluster_list;

	}

	/****************************************************************/

	// Print Function
	
	void CuddlePuddle::print_cuddle_puddle() {
	
		list<Cluster>::iterator i;
		static int stage_counter = 1;

		cout << endl << "##########################################################" << endl << endl;
		cout << "Stage " << stage_counter << "..." << endl << endl;

		for (i = cluster_list.begin(); i != cluster_list.end(); i++) {
			(*i).print_cluster();
		}
	
		cout << endl << endl;
		cout << "##########################################################" << endl << endl;

		stage_counter++;

	}

	void CuddlePuddle::print_cache() {
	
		vector<vector<double>>::iterator i;
		vector<double>::iterator j;

		cout << endl << "##########################################################" << endl << endl;
		cout << "Cache: " << endl << endl;

		for (i = cache.begin(); i != cache.end(); i++) {
			
			for (j = (*i).begin(); j != (*i).end(); j++) {

				cout << "[ " << (*j) << " ] ";

			}

			cout << endl;
		}

		cout << endl << endl;
		cout << "##########################################################" << endl << endl;
	
	}

	/****************************************************************/
	
	// Get Cluster from Cluster List
	
	Cluster CuddlePuddle::get_cluster(int index) {

		list<Cluster>::iterator i;
		Cluster dummy;

		for (i = cluster_list.begin(); i != cluster_list.end(); i++) {

			if ((*i).get_index() == index) {
				return (*i);
			}

		}

		return dummy;

	}


	// Clump Closest Clusters
	
	void CuddlePuddle::cuddle_closer() {
	
		/****************************************************************/
		
		// Variable declarations

		vector<int> indices;
		list<Cluster>::iterator closest_1, closest_2;

		/****************************************************************/

		// Get the 2 closest points

		if (cache.empty() == 1) {
			this->fill_cache();
		}

		indices = this->search_cache();
	
		closest_1 = cluster_list.begin();
		while ((*closest_1).get_index() != indices.at(0)) {
			closest_1++;
		}

		closest_2 = cluster_list.begin();
		while ((*closest_2).get_index() != indices.at(1)) {
			closest_2++;
		}

		/****************************************************************/

		// Merge the closest 2 into closest 1
		(*closest_1) += (*closest_2);

		// Update cache
		this->update_cache(indices);
			
		// Remove closest from cluster_list
		cluster_list.erase(closest_2);

		/****************************************************************/

	}

	/****************************************************************/

	// Keep clumping until the min number of clusters are left

	void CuddlePuddle::max_cuddling_powers_activate() {
	
		while (cluster_list.size() > min_clusters) {
			this->cuddle_closer();
			this->print_cuddle_puddle();
		}
	
	}

	/****************************************************************/

	// Process Input

	void CuddlePuddle::fill_cuddle_puddle() {

		list<Cluster> filled_cuddle_puddle;
		Point temp_point;
		double temp_double;
		char peekaboo;
		int dimension_counter = 0;
		int num_dimensions = 0;
		int count = 0;

		while (cin >> temp_double) {
		
			peekaboo = cin.peek();

			temp_point.set_coordinate(temp_double);
			dimension_counter++;

			if (peekaboo == '\n' || peekaboo == EOF) {
			
				if (num_dimensions == 0) {
					num_dimensions = dimension_counter;
				}

				else if (dimension_counter != num_dimensions) {
					cout << "Error: not all points have the same number of dimensions." << count << endl;
					exit(1);
				}

				dimension_counter = 0;
				temp_point.set_num_dimensions(num_dimensions);
				Cluster temp_cluster(temp_point, count);
				count++;
				filled_cuddle_puddle.push_back(temp_cluster);
			
				for (int i = 0; i < num_dimensions; i++) {
					temp_point.remove_coordinate();
				}
				

			}

			cin >> ws;
			
			
		}

		cluster_list = filled_cuddle_puddle;

	}

	/****************************************************************/

	// Cache Functions

	void CuddlePuddle::fill_cache() {
	
		list<Cluster>::iterator i, j;
		int row_counter = 0;
		int column_counter = 0;
		vector<double> temp_cache_row;
		double temp_distance;

		for (i = cluster_list.begin(); i != cluster_list.end(); i++) {
		
			for (j = cluster_list.begin(); j != cluster_list.end(); j++) {

				// don't want the first column to be all zeros
				if (column_counter == 0) {
					// do nothing
				}

				// make the bottom left diagonal half zeros
				else if (row_counter >= column_counter) {
					temp_cache_row.push_back(0);
				}

				// push the distance into the cache
				else {
					temp_cache_row.push_back((*i).get_distance(*j));
				}

				column_counter++;

			}

			cache.push_back(temp_cache_row);
			temp_cache_row.clear();
			
			row_counter++;
			column_counter = 0;

		}

		// don't want the last row to be all zeros
		cache.pop_back();

	}

	vector<int> CuddlePuddle::search_cache() {
	
		int i, j;
		double smallest_distance = INT_MAX;
		vector<int> indices;

		for (i = 0; i < cache.size(); i++) {

			for (j = (cache.at(i).size() - 1); j > i - 1; j--) {
				
				if (cache.at(i).at(j) < smallest_distance) {
					smallest_distance = cache.at(i).at(j);
					indices.clear();
					indices.push_back(i);
					indices.push_back(j + 1);
				}

			}

		}

		return indices;
	
	}

	void CuddlePuddle::update_cache(vector<int> indices) {

		// Update the column at the indices(1) - 1 index with int_max
		for (int i = 0; i < (indices.at(1)); i++) {

			cache.at(i).at(indices.at(1) - 1) = INT_MAX;

		}

		// Update the row at the indices(1) index with int_max
		for (int i = (cache.at(1).size() - 1); i > 0; i--) {

			if (indices.at(1) > i) {
				break;
			}

			if (cache.at(indices.at(1)).at(i) == 0) {
				break;
			}

			cache.at(indices.at(1)).at(i) = INT_MAX;
			
		}



		// Update the column at the indices(1) - 1 index with new distances
		for (int i = 0; i < (indices.at(0)); i++) {

			cache.at(i).at(indices.at(0) - 1) = this->get_cluster(indices.at(0)).get_distance(this->get_cluster(i));

		}

		// Update the row at the 0th index with new distances
		for (int i = (cache.at(0).size() - 1); i > 0; i--) {

			if (indices.at(0) > i) {
				break;
			}

			if (cache.at(indices.at(0)).at(i) == 0) { 
				break;
			}

			if (cache.at(indices.at(0)).at(i) != INT_MAX) {
				cache.at(indices.at(0)).at(i) = this->get_cluster(indices.at(0)).get_distance(this->get_cluster(i+1));
			}

		}


		
	}

	/****************************************************************/

/****************************************************************/
