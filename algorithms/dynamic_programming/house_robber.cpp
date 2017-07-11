#include <vector> 
using namespace std; 

class Solution {
private: 
    inline int rob_helper(vector<int>&nums, int start, vector<int>& maxrob) { 
        int len = nums.size();
        
        if (start >= len) 
            return 0; 
        
		// if value is recorded, then just use that value
        if (maxrob[start] != -1) 
            return maxrob[start]; 
        
		// initilize value with the house value 
        maxrob[start] = nums[start];
    
		// as long as the item is not the last 2 houses in the row. 
        if (start != len-1 && start != len-2)
        { 
			// explore 2 options - the house after the adjacent house and 
			// the house 2 houses away. 
            maxrob[start] += max(rob_helper(nums, start+2, maxrob), 
                                 rob_helper(nums, start+3, maxrob)); 
            
        }

        return maxrob[start]; 
    }
    
public:
    int rob(vector<int>& nums) {
        auto len = nums.size();
        vector<int> maxrob(len, -1); 
        
        if (!len) { 
            return 0; 
        }
        
        return max(rob_helper(nums, 0, maxrob), 
                   rob_helper(nums, 1, maxrob));
    }
};

int main()
{ 
	Solution sol;
	return 0; 
} 
