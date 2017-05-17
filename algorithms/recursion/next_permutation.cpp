// solution to problem 31 of leetcode 
/* 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/ 

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

void nextPermutation(vector<int>& nums) {
	vector<vector<int>> res;  
	vector<int> sofar = {}; 
  
    auto sorted_nums = nums; 
    sort(sorted_nums.begin(), sorted_nums.end());     
	solve(sofar, sorted_nums, res); 

    int idx = find(res.begin(), res.end(), nums) - res.begin(); 
    
    if (idx == res.size()-1) { 
        reverse(nums.begin(), nums.end()); 
    }
    else { 
        nums = res[idx+1]; 
    }
}

namespace { 
    struct test{ 
        vector<int> in; 
        vector<int> out; 
    }; 

    vector<test> tests = { 
        {{1,2,3}, {1,3,2}},
        {{1,3,2}, {2,1,3}},
        {{3,2,1}, {1,2,3}}, 
        {{1,1,5}, {1,5,1}},
        {{0}, {0}},
        {{9,8}, {8,9}},
        {{6,8,7}, {7,6,8}},
        {{}, {}},
        {{1,4,3,2}, {2,1,3,4}},
        {{1,5,1}, {5,1,1}},
    }; 
}

int main()
{ 
    for (auto& t: tests) { 
        nextPermutation(t.in); 
        if (t.in == t.out) { 
            cout << "Pass\n"; 
        } 
        else { 
            cout << "Fail\n"; 
        }
    }

    return 0; 
}
