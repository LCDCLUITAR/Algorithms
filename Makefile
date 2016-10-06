All:
	g++ introSort.cpp sorting.cpp -std=c++0x -oSort -O1
run:
	clear
	./Sort
clean:
	clear
	rm Sort *-OUTPUT.txt
review:
	pico Case3-OUTPUT.txt
