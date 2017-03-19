

# About Agglomerative Clustering

In this project, I implemented an agglomerative clustering algorithm for real-valued vectors in 
multidimensional space. In short, when given a list of points of dimension n, and k clusters as the 
end result, it assigns points which are closest together into clusters until there are only k 
clusters total.  

The distance computation between objects is the standard Euclidean calculation, and the distance 
between clusters will be computed as the average of all pairwise distances between the elements of 
the two clusters.  A major goal of this assignemnt was to make the algorithm efficient, and so I 
created a chaching mechanism which significantly redices the need to recompute the distances between 
clusters that was already previously calculated.

For example, if you are computing the distance between two clusters A = (a1, a2) and B = (b1, b2, b3), 
the distance between A and B should be computed as follows:

d(A, B) = ( d(a1,b1) + d(a1,b2) + d(a1,b3) + d(a2,b1) + d(a2,b2) + d(a2,b3) ) / 6


# How to Run

This program was designed to be run from the terminal on Linux.  Here is how to compile and run 
the executable:

	(1) Download all files in this directory

	(2) Navigate to the directory containing this project on your computer

	(2) Type "make" and hit enter to compile the program; the resulting executable is called main

	(3) To test the program, use the format:
	
			$ cat input.txt | main [number of clusters] > output.txt 

	(4) Output of the program is in the output file

To change the input to the program, simply change the data in the input.txt file.  There is test data 
currently in there, but it should work with any other data too, as long as all of the points are the same
dimension.

