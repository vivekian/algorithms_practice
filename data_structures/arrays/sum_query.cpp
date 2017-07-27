#include <vector> 
using namespace std; 

class NumArray {
private:
    // store the sum from (i to len-1)  
    vector<int> sum; 
    int len = 0; 
    
public:
    NumArray(vector<int> nums) {
        len = nums.size(); 
        
        if (!len) 
            return; 
        
        sum.resize(len); 
        sum[len-1] = nums[len-1]; 
        
        for (int i=len-2; i>=0; --i) { 
            sum[i] = nums[i] + sum[i+1];   
        }
    }
    
    int sumRange(int i, int j) {
		// if the end of array is specified, then don't subtract anything. 
        return (j == len-1) ? sum[i]: sum[i] - sum[j+1]; 
    }
};

int main() 
{ 
	return 0; 
} 
