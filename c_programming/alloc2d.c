// allocate a 2D matrix memory dynamically 'C' style using 
// a double pointer dereference. 

#include <stdio.h> 
#include <stdlib.h> 

int** alloc2d(int rows, int cols) 
{ 
	int** matrix =  malloc (rows * (sizeof(int*))); 
	
	int i = 0; 
 	for(; i < rows; i++) { 
		matrix[i] = malloc (cols * (sizeof(int))); 
	}  

	return matrix; 
} 

int main() 
{
	int** matrix = alloc2d(10, 10); 

	int i = 0; 
	for (; i < 10; i++) 
		free(matrix[i]); 

	free(matrix); 
	return 0; 
} 
