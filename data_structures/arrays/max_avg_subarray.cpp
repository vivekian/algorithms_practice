#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

double findMaxAverage(vector<int>& nums, int k) { 
	long sum = 0; 

	for (int i=0; i<k; ++i) { 
		sum += nums[i]; 
	} 

	double maxavg = static_cast<double>(sum) / k; 
	const auto len = nums.size(); 

	for (int i=k; i<len; ++i) { 
		sum += nums[i]; 
		sum -= nums[i-k];
		maxavg = max(static_cast<double>(sum)/k, maxavg); 
	}
	
	return maxavg; 
}

int main()
{
    return 0;  
}
