
/****************************************************************/
/* Programmer: Victoria Albanese                                */
/* Project01 Part 2: Cluster Client				*/
/* Program Description: This file contains the client code for  */
/*                      the cluster class, and tests the	*/
/*                      functionality of all the member		*/
/*                      functions in this class.		*/
/****************************************************************/


/****************************************************************/

// Include Statements

#include <iostream>
#include <ctime>

#include "point_class.hpp" // included for point functionality
#include "cluster_class.hpp" // included for cluster functionality
#include "cuddle_puddle_class.hpp" // included for cuddle puddle functionality

/****************************************************************/

// Namespace Declarations

using namespace std;

/****************************************************************/

// Main

int main(int argc, char * argv[]) {

	/****************************************************************/

	CuddlePuddle puddle;
	clock_t start, end;
	//cout << argv[1] << endl;
	// Get size of final environment

	if (atoi(argv[1]) == 0) {
		cout << "Error: you did not input an integer number for min_cluster." << endl;
		exit(1);
	}

	else {
		puddle.set_min_clusters(atoi(argv[1]));
	}

	// Fill cuddle puddle
	
	puddle.fill_cuddle_puddle();
	
	if (puddle.get_min_clusters() > puddle.get_cluster_list().size()) {
		cout << "Error: you don't have enough clusters to cuddle together. :(" << endl;
		exit(1);
	}

	// Print precuddled clusters 
	puddle.print_cuddle_puddle();

	// Cuddle up and print postcuddled clusters

	start = clock();
	puddle.max_cuddling_powers_activate();
	end = clock();

	cout << endl << endl << "Seconds elapsed: " << (double)(end - start) / CLOCKS_PER_SEC << endl << endl;

	/****************************************************************/

	return 0;

}

// End of Main

/****************************************************************/
