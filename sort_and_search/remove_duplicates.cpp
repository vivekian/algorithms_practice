
/* Write a function which takes the input of a sorted array 
   and removes all the duplicate entries and moves them to 
   the left. Return the number of valid entries which are 
   remaining */ 

#include <iostream> 
using namespace std; 

int RemoveDuplicates(int X[], int Size) 
{ 
	if (Size == 0) 
		return 0; 

	int reader = 1;
	int writer = 0; 

	while (reader < Size) 
	{ 
		if (X[reader] != X[reader-1]) 
			++writer; 
	
		X[writer] = X[reader];
		++reader; 
	} 	

	return writer+1; 
} 

int main()
{ 
	int x [] = {1,2,3,3,4,4,5,6,7};
	int numElements = RemoveDuplicates(x, sizeof(x)/sizeof(x[0])); 
	
	cout << numElements << endl; 
	
	for (int i = 0; i < numElements; ++i) 
		cout << x[i] << " "; 
	
	return 0; 
} 
