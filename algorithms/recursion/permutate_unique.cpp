// permutate a list of numbers, duplicates are allowed now. 
// but the list of answers in the result should not be duplicates.

#include <iostream> 
#include <vector> 

using namespace std; 

void solve(vector<int> sofar, vector<int> rest, vector<vector<int>>& res)
{
	if (rest.empty()) {
		res.push_back(sofar);
	} 
	else { 
		int i=0; 
        while (i < rest.size()) { 
            // don't pick up duplicate items 
            if (i == 0 || rest[i] != rest[i-1]) { 
                auto next = sofar; 
                auto remaining = rest;
                next.push_back(rest[i]); 
                remaining.erase(remaining.begin()+i); 
                solve(next, remaining, res); 
            }
            ++i; 
		}
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;  
	vector<int> sofar = {}; 
    
    sort(nums.begin(), nums.end());     
	solve(sofar, nums, res); 
	return res;
}

void print(vector<vector<int>>& result) 
{ 
    for (const auto& row: result) { 
        for (const auto& item: row) { 
            cout << item << ",";
        }
        cout << "\n"; 
    }
}

int main() 
{
	vector<int> nums = {3,3,0,3}; 
	auto result = permute(nums);  
    print(result); 
	return 0; 
}
