// example of how upper_bound and lower_bound work. 

#include <algorithm> 
#include <iostream> 
#include <vector> 

using namespace std; 

void test_upper_bound() 
{ 
    const vector<uint32_t> nums = {1, 3, 5, 7, 9, 11, 23, 55, 66, 89}; 
    
    auto item = upper_bound(nums.begin(), nums.end(), 23);
    cout << "item greater than 23 is:" << *item << endl; 
    
    item = lower_bound(nums.begin(), nums.end(), 24); 
    cout << "lower_bound for 24 is:" << *item << endl;
} 

int main() 
{ 
    test_upper_bound(); 
} 
