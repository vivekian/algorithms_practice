#include <iostream> 
using namespace std; 

int binsearch(int* a, const int size, int item) 
{ 
	int lo = 0, hi = size-1; 
	int mid; 

	// what this condition really means is that you have gone beyond 
	// array boundaries to search for a not present element 
	while(hi > lo) 
	{ 
		mid = lo + ((hi - lo)/2); 
		if (a[mid] == item) 
			return mid; 
		else if (item > a[mid]) 
			lo = mid + 1; 
		else 
			hi = mid - 1; 
	} 

	return -1; 
} 
	

int main() 
{ 
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
	cout << binsearch(a, sizeof(a)/sizeof(int), 4) << endl; 
	cout << binsearch(a, sizeof(a)/sizeof(int), 2) << endl; 
	cout << binsearch(a, sizeof(a)/sizeof(int), 11) << endl; 
	cout << binsearch(a, sizeof(a)/sizeof(int), -1) << endl; 
	return 0; 
} 
