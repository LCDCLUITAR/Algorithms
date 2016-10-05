#include "sorting.h" 
// Introsort Algorithm
void Sorting::introsort(vector<int>&arr){
    int depthLimit = 2 * log(arr.size());
 
    // Recursive Introsort
    introsort_Quick(arr, 0, arr.size(), depthLimit);
    return;
}
// Introspective Sort / Quicksort as default
void Sorting::introsort_Quick(vector<int>&arr, int left, int right, int depthLimit){
    // Get vector size
    int size = (right - left);
	
    // If partition size is lower than 16 do insertion sort
    if(size < 16){
		insertionSort(arr);
        return;
    }
	
	if(DEBUG)
		cout << "Size: " << size << " Depth: " << depthLimit << endl;
	
    // If the depth is zero do heapsort
    if (depthLimit == 0){
        make_heap(arr.begin(), arr.end());
        sort_heap(arr.begin(), arr.end());
        return;
    }
    // As default use median of three for quicksort
    int pivot = medianOfThree(arr.front(), (size/2)-1, arr.back());
	
	if(DEBUG)
		cout << "Pivot: " << pivot << endl;
	
    // Swaps values
    swapValue(pivot, arr.size()-1);
 
	// Quick Sort main algorithm
	int partitionPoint = partition(arr, 0, arr.size()-1);
	introsort_Quick(arr, 0, partitionPoint-1, depthLimit - 1);
	introsort_Quick(arr, partitionPoint + 1, arr.size()-1, depthLimit - 1);
 
    return;
}
// Insertion Sort algorithm
void Sorting::insertionSort(vector<int>&arr){
    // Left and right iterators
    int left = 0; // Sorted elements will be pushed to the left
    int right = arr.size()-1;
	
	for (int i = 0; i < arr.size()-1; i++){
		int j = i+1;
		
		while (j > 0 && arr[j] < arr[j-1]){
			  int temp = arr[j];
			  arr[j] = arr[j-1];
			  arr[j-1] = temp;
			  j--;
		}
	}
	if(DEBUG)
		cout << "Checkpoint Insertion Sort" << endl;
 
	return;
}
 
// Partitions the array and returns partition index
int Sorting::partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];    // pivot
    int i = (low-1);  		  // Index of smaller element -1
 
    for (int j = low; j <= high; j++){
        // Compares if current value is <= to pivot
        if (arr[j] <= pivot){
            // Increment index of smaller element
            i++;
 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (arr.front() + i + 1);
} 
 
// Median of three function to find the middle element
int Sorting::medianOfThree(int a, int b, int c){
	const int mid = max(min(a,b),min(max(a,b),c));
	if(DEBUG)
		cout << "a: " << a << " b: " << b << " c: " << c << " mid: " << mid << endl;
	return mid;
	
	return -1;
}

#pragma region generalFunctions

// Get input from File
void getFileInput(vector<int>&arr){
	string fileName;
	
	cout << "Enter file name with extension\n>> ";
	cin >> fileName;
	
	ifstream file(fileName.c_str(), ifstream::in);
	while(!file.eof()){
		string line;
		int value;
		stringstream ss;
		
		getline(file, line);
		ss << line;
		ss >> value;
		arr.push_back(value);
		//cout << value << endl;
    }
}
// Swap int values 
void swapValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    return;
}
// Print sorted array
void printArray(vector<int>arr, int n, string caseName){
	ofstream file2(caseName.c_str(), ofstream::out);
	
	file2 << "++++++++++ " << caseName << " ++++++++++\n\n";
	for (int i=0; i <= n; i++)
		file2 << "1.  " << arr[i] << endl;
}

#pragma endregion