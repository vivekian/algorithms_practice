#include <iostream> 
#include <vector> 

using namespace std; 

int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size(); 

	if (!n) { 
		return 0; 
	} 

	if (n == 1) { 	
		return triangle[0][0]; 
	}

	int sum = 0; 

    // start at the 2nd last row and build the min values to the 0th row. 
    // destroy the input vector itself to store the sum of the value on the 
    // ith row and the min of the adjacent items on the i+1th row. 
	for (int i=n-2; i>=0; --i) { 
		for (int j=0 ; j<triangle[i].size(); ++j) { 
			triangle[i][j] = min (triangle[i][j] +triangle[i+1][j], 
								  triangle[i][j] +triangle[i+1][j+1]);
		}
	}        

	return triangle[0][0]; 
}

int main() 
{
	vector<vector<int>> input = {{-10}, {3,2}, {1, 5, 5}}; 
	cout << minimumTotal(input) << endl;  
	return 0; 
}
