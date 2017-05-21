// solution to problem 594 of Leetcode (longest harmonious subsequence) 

#include <iostream> 
#include <unordered_map> 
#include <vector> 

using namespace std; 

int findLHS(vector<int>& nums) {
    int res = 0; 
    unordered_map<int, int> harmonymap; 

    for (int i=0; i<nums.size(); ++i) { 
        harmonymap[nums[i]]++; 
    }
    
    for (int i=0; i<nums.size(); ++i) { 
        if (harmonymap.find(nums[i]) == harmonymap.end()) { 
                continue; 
        }

        if (harmonymap.find(nums[i]+1) == harmonymap.end()) { 
                continue;
        } 

        res = max(res, harmonymap[nums[i]] + harmonymap[nums[i]+1]); 
    }

    return res; 
}

int main()
{ 
    vector<int> nums = {1,3,2,2,5,2,3,7}; 
    cout << findLHS(nums) << endl; 
    nums = {1,1,1,1}; 
    cout << findLHS(nums) << endl; 
    return 0; 
} 
