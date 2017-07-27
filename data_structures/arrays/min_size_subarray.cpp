#include <vector> 
using namespace std; 

int minSubArrayLen(int s, vector<int>& nums) {
        int min_elems = 0; 
        int len = nums.size(); 
        
        if (!len) 
            return 0; 
        
        int start = 0, end = 0; 
        int sum = nums[0];
        
        while (start < len && end < len) {
            /* sum is greater equal to s, then check min_diff 
			   also, move start to next position */ 
			if (sum >= s) { 
                int diff = end-start+1; 
                
                if (!min_elems || (diff < min_elems)) { 
                    min_elems = diff; 
                }
                
                sum -= nums[start];
                ++start;
                
				// edge case where there was a single element in the sub array. 
                if (start > end) 
                    end = start; 
            }
			/* move right end of subarray further out */ 
            else { 
                ++end; 
                sum += nums[end]; 
            }
        }
        
        return min_elems; 
    }
