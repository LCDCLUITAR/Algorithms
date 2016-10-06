#include "sorting.h" 
#ifdef __linux
Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier def(Color::FG_DEFAULT);
#elif _WIN32
#define red ""
#define green  ""
#define blue  ""
#define def  ""
#endif

// Introsort Algorithm
void Sorting::introsort(vector<int>&arr){
    int depthLimit = 2 * log(arr.size());
    // Recursive Introsort
    introsort_Quick(arr, 0, arr.size()-1, depthLimit);
    return;
}
// Introspective Sort / Quicksort as default
void Sorting::introsort_Quick(vector<int>&arr, int left, int right, int depthLimit){
	static int iterations = -1;
	iterations++;
	if(DEBUG)
		cout <<red<< "Left: " << left << " Right: " << right << " Depth: " << depthLimit <<def<< endl;
    // Get vector size
    int size = (right - left);
	
    // If partition size is lower than 16 do insertion sort
    if(size < 16){
		insertionSort(arr);
        return;
    }
	
	if(DEBUG)
		cout <<blue<< "Size: " << size << " Depth: " << depthLimit <<def<< endl;
	
    // If the depth is zero do heapsort
    if (depthLimit == 0){
        make_heap(arr.begin(), arr.end());
        sort_heap(arr.begin(), arr.end());
        return;
    }
    // As default use median of three for quicksort
    int pivotVal = medianOfThree(arr.front(), arr[(size/2)-1], arr.back());
	int pivotIndex = find(arr.begin(), arr.end(), pivotVal) - arr.begin();
	if(DEBUG)
		cout <<green<< "PivotIndex: " << pivotIndex << " Last Val: " << arr[arr.size()-1] <<def<< endl;
	
    // Swaps values
    swapValue(arr, pivotIndex, arr.size()-1);
 
	// Quick Sort main algorithm
	unsigned int partitionPoint = partition(arr, left, right);
	if(DEBUG)
		cout << "partitionPoint: "<< partitionPoint << endl;
	if(DEBUG && CHECKPOINT)
		SLEEP;
	introsort_Quick(arr, left, partitionPoint-1, depthLimit - 1);
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
		if(DEBUG)
			cout << red << "arr["<<j<<"]: "<<arr[j] << " Pivot: "<<pivot << endl;
        // Compares if current value is <= to pivot
        if (arr[j] <= pivot){
            // Increment index of smaller element
            i++;
 
            swapValue(arr, i, j);
			if(DEBUG)
				cout <<blue<< "Swap: " << i << " with: " << j << " arr.front: " << arr.front() <<def<< endl;
        }
    }
    swapValue(arr, (i+1), high);
    return (0 + i + 1);
} 
 
// Median of three function to find the middle element
int Sorting::medianOfThree(int a, int b, int c){
	// Gets the mid value
	const int mid = max(min(a,b),min(max(a,b),c));
	if(DEBUG)
		cout << "a: " << a << " b: " << b << " c: " << c << " mid: " << mid << endl;	
	return mid;
}

#pragma region generalFunctions
// Get input from File
string getFileInput(vector<int>&arr){
	string fileName;
	char limitArray;
	int limit = -1;
	int i = 0;
	size_t pos1 = -1, pos2;
	
	cout <<green<< "Enter file name with extension\n>> " << def;
	cin >> fileName;
	
	cout << green << "Would you like to limit the array size? (Y/N)\n>> " << def;
	cin >> limitArray;
	if(toupper(limitArray) == 'Y'){
		cout << blue << "Enter desired array size\n>> " << def;
		cin >> limit;
	}		
	
	ifstream file(fileName.c_str(), ifstream::in);
	while(!file.eof()){
		if(i == limit)
			break;
		
		string line;
		int value;
		stringstream ss;
		
		getline(file, line);
		if(line.empty()){
			break;
		}
		ss << line;
		ss >> value;
		arr.push_back(value);
		i++;
		//cout << value << endl;
    }
	// Removes the extension from the string
	if(fileName.find("/") != string::npos)
		pos1 = fileName.find("/");
	
	pos2 = fileName.find(".");
	fileName = fileName.substr(pos1+1, pos2);
	
	if(DEBUG)
		cout << "Filename: " << fileName << endl;
	
	return fileName;
}
// Swap int values 
void swapValue(vector<int>&arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}
// Print sorted array
void printArray(vector<int>arr, int n, string caseName){
	string newFileName = caseName + "-OUTPUT.txt";
	ofstream file2(newFileName.c_str(), ofstream::out);
	
	file2 << "++++++++++ " << caseName << " ++++++++++\n\n";
	for (int i=0; i <= n; i++)
		file2 << i+1 << ".  " << arr[i] << endl;
	
	cout <<red<< "Output file '" << newFileName << "' created..." <<def<< endl;
}

#pragma endregion