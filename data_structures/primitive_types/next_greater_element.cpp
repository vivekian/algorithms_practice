#include <vector> 
#include <algorithm> 
#include <iostream> 

using namespace std; 

int find_next(int num, vector<int>& nums) 
{ 
    auto pos = find(nums.begin(), nums.end(), num); 
    
    for (auto i = pos; i != nums.end(); ++i) { 
        if (*i > *pos) { 
            return *i; 
        }
    }
        
    return -1; 
}

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
{
    vector<int> res; 

    for (auto num: findNums) { 
        res.push_back(find_next(num, nums)); 
    }

    return res; 
}

int main() 
{
    vector<int> nums1 = {4,1,2}; 
    vector<int> nums2 = {1,3,4,2}; 

    auto res = nextGreaterElement(nums1, nums2);  

    for (auto r: res) { 
        cout << r << endl; 
    } 

    return 0; 
} 
