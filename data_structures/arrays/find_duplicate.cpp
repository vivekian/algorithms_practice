#include <vector> 

using namespace std; 

/*Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.*/ 

int findDuplicate(vector<int>& nums) {
	int lo = 0;
	int hi = nums.size() - 1; 

	while (lo < hi) { 
		int mid = lo + (hi - lo)/2; 
		
		int cnt = 0; 
		for (const auto& i: nums) { 
			if (i <= mid) { 
				++cnt; 
			} 
		} 
		
		if (cnt <= mid) { 
			lo = mid+1; 
		} 
		else { 
			hi = mid; 
		} 		
	}	

	return lo; 	
}

int main()  
{ 
	return 0; 
} 
