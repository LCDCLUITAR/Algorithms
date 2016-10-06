//++++++++++++++++++++++++++++++++++++++++++++++++++++
// Author:   Luis D. Chaparro
// Program:  1
// Due Date: 10/06/2016
// Description: Introspective algorithm implementation
// Score: 10 Well Doc, 
//++++++++++++++++++++++++++++++++++++++++++++++++++++
 
#include "sorting.h"
 
// Main Function
int main( int argc, char *argv[] ){
	vector<int>arr;					// Vector to hold the input file information
	Sorting sort;					// Object to call sorting functions
	string caseName;				// Gets Case file names
	char proceed;					// Char bool to indicate additional file
	static int caseCount = 0;		// If there are two or more files then it is Case 3
	clock_t begin, end;				// Measures elapsed time
	
	do{
		caseName = getFileInput(arr);	// Function to get file input
		
		begin = clock();
		sort.introsort(arr);			// Calls introSort functions from the object 
		end = clock();
		
		cout << "\e[92mWould you like to add another file? (Y/N)\n>> \e[39m";
		cin >> proceed;
		if(caseCount == 1)
			caseName = "Case3";
		caseCount++;
	}while(toupper(proceed) == 'Y');
	printArray(arr, arr.size()-1, caseName); // Print vector values to an output file
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "\e[31mElapsed time: " << elapsed_secs << " Secs.\e[39m" << endl;
 
    return 0;
}