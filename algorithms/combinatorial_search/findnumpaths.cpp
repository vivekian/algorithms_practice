/* Imagine a robot sitting on the upper left hand corner of an NxN grid.
   The robot can only move in two directions: right and down 
   How many possible paths are there for the robot? */ 

#include <iomanip> 
#include <iostream> 
using namespace std; 

static int SIZE = 5; 
static int grid[5][5] = {-1};  

unsigned FindNumPaths
(
	const int Row, 
	const int Col, 
	const int N
) 
{ 
	unsigned Paths = 0; 

	if ((Row == N-1) && (Col == N-1))
		 return 1; 

 	if ((grid[Row][Col] != -1))
		return grid[Row][Col];  
 
	if (Row < N-1) 
		Paths += FindNumPaths(Row + 1, Col, N); 

	if (Col < N-1)  
		Paths += FindNumPaths(Row, Col + 1, N); 

	grid[Row][Col] = Paths; 
	return Paths; 
} 

int main() 
{
	for (int r = 0; r < SIZE; r++) { 
		for (int c = 0; c < SIZE; c++) { 
			grid[r][c] = -1 ; 
		} 
	} 
 
	cout << FindNumPaths(0, 0, SIZE) << endl;
	
 	for (int r = 0; r < SIZE; r++) { 
		for (int c = 0; c < SIZE; c++) { 
			cout << setw(9) << grid[r][c] << " " ; 
		} 
		cout << endl; 
	} 
 
	return 0;  
} 	

