#include <vector> 
using namespace std; 
 
int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int lo = 0, hi = len-1; 

		// binary search         
        while (lo < hi) { 
            int mid = lo + (hi  - lo)/2; 
            
			// can't compare against left element when mid=0 
			// neighboring element is greater, then search for peak in that half 
            if ((mid != 0) && nums[mid-1] > nums[mid]) { 
                hi = mid-1; 
            }
			// can't compare against right element mid = len-1
            else if ((mid != len-1) && nums[mid+1] > nums[mid]) { 
                lo = mid+1; 
            }
			// this means that mid is the peak element. 
            else { 
                return mid; 
            }
        }
        
        return lo; 
}

int main()
{ 
	return 0; 
} 
