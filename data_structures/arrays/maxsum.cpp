#include <algorithm> 
#include <iostream> 
#include <vector> 

using namespace std;

int maximumProduct(vector<int> nums) {
    auto len = nums.size(); 

    sort(nums.begin(), nums.end());  

    // all numbers are non-negative - pick the three largest. 
    // all numbers are negative - pick the three largest. 
    // largest number is positive and smallest two numbers are negative 
    //          compare product of smallest 2 nos and 2nd largest and 3rd largest nos. 
    //          pick the product which is greater. 


    if (nums[0] < 0 && nums[1] < 0 && nums[len-1] > 0) { 
        int sum1 = nums[0] * nums[1]; 
        int sum2 = nums[len-2] * nums[len-3]; 

        return nums[len-1] * max(sum1, sum2); 
    } 

    return nums[len-1] * nums[len-2] * nums[len-3]; 
}

int main() 
{ 
	cout << maximumProduct({1,2,3,4}) << endl; 
	cout << maximumProduct({-4,-3,-2,-1}) << endl; 
	cout << maximumProduct({-4,-3,-2,0}) << endl; 
	cout << maximumProduct({-4,-3,-2,2,3}) << endl; 
	return 0; 
} 


