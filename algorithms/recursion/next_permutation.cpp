// solution to problem 31 of leetcode 
/* 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/ 

#include <iostream> 
#include <vector>
using namespace std; 

void nextPermutation(vector<int>& nums) {
    
    if (!nums.size()) { 
        return; 
    }

    int len = nums.size(); 
    int i = len-1; 

    // start from last element and keep going if they are reverse sorted.
    while (i && nums[i-1] >= nums[i]) { 
        --i; 
    }

    // if reached the beginning of the array, then no greater list exists
    // reverse and return the list.
    if (i == 0) { 
        reverse(nums.begin(), nums.end()); 
    }
    else { 
        int val = nums[i-1]; 
        int j = len-1; 

        // find the element from the end of the list to the ith element
        // which is greater than the nums[i-1] and swap it. 
        while (j >= i && val >= nums[j]) { 
            --j; 
        }

        swap(nums[i-1], nums[j]); 

        // now reverse the remaining elements. 
        reverse(nums.begin()+i, nums.end()); 
    }
}

namespace { 
    struct test{ 
        vector<int> in; 
        vector<int> out; 
    }; 

    vector<test> tests = { 
        {{1,2,3}, {1,3,2}},
        {{1,3,2}, {2,1,3}},
        {{3,2,1}, {1,2,3}}, 
        {{1,1,5}, {1,5,1}},
        {{0}, {0}},
        {{9,8}, {8,9}},
        {{6,8,7}, {7,6,8}},
        {{}, {}},
        {{1,4,3,2}, {2,1,3,4}},
        {{1,5,1}, {5,1,1}},
    }; 
}

int main()
{ 
    for (auto& t: tests) { 
        nextPermutation(t.in); 
        if (t.in == t.out) { 
            cout << "Pass\n"; 
        } 
        else { 
            cout << "Fail\n"; 
        }
    }

    return 0; 
}
