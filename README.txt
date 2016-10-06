Usage:
Use Makefile 
<make> Compiles
<make><run> Runs the program
<make><clean> Cleans all output files
<make><review> Used to review Case 3

-------------
Explanation for choosing introspective algorithm:

We decided to choose the introspective algorithm because it combines the best sorting algorithms to create an algorithm 
that eliminates the worst case being worst than O(n log n).
 
The default algorithm being used is quicksort, however before performing quicksort our algorithm checks if the 
array size is less than 16 and if it is then the algorithm uses insertion sort since it is the best to use for 
small size arrays. If the array is bigger than 16 but its depth (2*log(n)) == 0 then the algorithm switches to heapsort.

If the array size is not less than 16 and the depth is not equal to 0 then the algorithm performs quicksort recursevely.

------------
Time Complexity:

Best Case – O(N log N)
Average Case- O(N log N)
Worse Case- O(N log N)
where, N = Array size 
