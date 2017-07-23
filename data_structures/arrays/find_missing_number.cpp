#include <vector>  
using namespace std; 

vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(); 
        // sort the numbers 
        sort(nums.begin(), nums.end()); 
        
        vector<int> res(2);
        
        // iterate through all the numbers 
		for (int i=0; i<n-1; ++i) { 
			
			// adjacent numbers should have a diff of 1
            if (nums[i+1] != nums[i]+1) { 
				// duplicate numbers 
                if (nums[i+1] == nums[i]) { 
                    res[0] = nums[i];
                }
				// missing number. 
                else { 
                    res[1] = nums[i]+1; 
                }
            }
        }
        
		// if the first number is missing 
        if (nums[0] != 1) { 
            res[1] = 1; 
        }
		// if last number is missing. 
        else if (nums[n-1] != n) { 
            res[1] = n; 
        }
        
        return res; 
}

int main() 
{ 
	return 0; 
} 
