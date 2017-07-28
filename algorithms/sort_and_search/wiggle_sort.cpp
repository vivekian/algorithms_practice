#include <vector> 
using namespace std; 

void wiggleSort(vector<int>& nums) {
	int len = nums.size(); 
	
	if (!len) 
		return; 
	
	sort(nums.begin(), nums.end()); 
	
	for (int i=1; i<len-1; i=i+2) { 
		swap(nums[i],nums[i+1]); 
	}
}

int main()
{ 
	return 0; 
} 
