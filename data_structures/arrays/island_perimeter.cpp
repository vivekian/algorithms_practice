#include <iostream> 
#include <vector> 

using namespace std; 

/* assumptions 
	- how big can the grid be? 
	- there are no lakes 
	- can the complete grid be an island? 
	- can there be no island at all? 
	- each cell is 1 unit long 
*/ 

int islandPerimeter(vector<vector<int>>& grid) {
	int r = grid.size(); 	

	if (!r) 
		return 0; 

	int c = grid[0].size(); 
	int p = 0; 

	for (int i=0; i<r; ++i) { 
		for (int j=0; j<c; ++j) { 
			if (grid[i][j] == 1) {
				// check up neighbor  
				if (i == 0 || grid[i-1][j] == 0)
					++p; 

				// check left neighbor 
 				if (j == 0 || grid[i][j-1] == 0) 
					++p; 

				// check down neighbor 
 				if (i == r-1 || grid[i+1][j] == 0) 
					++p;
		
				// check right neighbor
				if (j == c-1 || grid[i][j+1] == 0) 
					++p;
			}
		}
	}
		
	return p; 		
}

int main()
{ 
	vector<vector<int>> g = {{1, 0}, {1,0}}; 
	vector<vector<int>> g2 = {{1}}; 
	cout << islandPerimeter(g) << endl; 
	cout << islandPerimeter(g2) << endl; 
	return 0; 
} 
