#include <iostream> 
#include <vector> 
#include <stack> 
#include <string> 

using namespace std; 

namespace { 

} 

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    vector<vector<int>> res; 
    auto numsr = nums.size(); 
    auto numsc = nums[0].size(); 

    if ((r * c) != (numsr * numsc)) { 
        return nums; 
    }

	res.resize(r);
	for (int i=0; i<r; ++i) { 
		res[i].resize(c); 
	} 

	int i=0, j=0;
 
	for (const auto row: nums) { 
		for (const auto item: row) { 
			res[i][j] = item;
			++j; 
			
			if (j==c) { 
				j=0; 
				++i; 
			} 
		}
	} 

    return res;     
}

void print (ostream& out, vector<vector<int>> matrix)
{
    for (const auto r: matrix) {
        for (const auto c: r) {
            out << c << ",";
        }
        out << endl;
    }
}

int main() 
{ 
    vector<vector<int>> input = { {1,2}, {3,4}}; 
    auto res = matrixReshape(input, 1, 4); 
	print(cout, res); 

    vector<vector<int>> input2 = { {1,2,3}, {4,5,6}}; 
    auto res2 = matrixReshape(input2, 6,1);	
	print(cout, res2);  

    return 0; 
} 
