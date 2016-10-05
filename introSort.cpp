//++++++++++++++++++++++++++++++++++++++++++++++++++++
// Author:   Luis D. Chaparro
// Program:  1
// Due Date: 10/06/2016
// Description: Introspective algorithm implementation
// Usage: 
//++++++++++++++++++++++++++++++++++++++++++++++++++++
/* Stil to implement, 
--- Command line file input
--- Menu to pick a case
--- Clock cycles for algorithm
--- File extension manager function
*/
 
#include "sorting.h"  
// Main Function
int main( int argc, char *argv[] ){
	vector<int>arr;		// Vector to hold the input file information
	Sorting sort;		// Object to call sorting functions
	
	getFileInput(arr);	// Function to get file input 
	
	sort.introsort(arr);// Calls introSort functions from the object 
	
    printArray(arr, arr.size()-1, "Case 1"); // Print vector values to an output file
 
    return 0;
}