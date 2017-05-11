#include <iterator> 
#include <algorithm> 
#include <iostream> 
#include <vector> 

using namespace std; 

struct test { 
    vector<int> nums; 
    int k; 
    int idx;  
};

namespace { 
    vector<test> tests = { 
        {{4,5,6,7,1,2,3}, 2, 5},
        {{2,3,4,5,6,7,1}, 2, 0},
        {{3,1,2}, 2, 2},
        {{7,1,2,3,4,5,6}, 7, 0},
        {{7,1,2,3,4,5,6}, 6, 6},
        {{1,2}, 1, 0},
        {{1,2}, 3, -1},
        {{}, 3, -1},
        {{3,5,1}, 5, 1},
        {{3,1}, 3, 0} 
   };
}

int search_rotated(vector<int>&nums, int k)
{ 
    int lo=0; int hi=nums.size()-1; 
    int min_item = -1;
    int mid; 

    // search for the min index 
    while (lo <= hi) { 
       
        if (nums[lo] <= nums[hi]) { 
           min_item = lo; 
           break; 
        }

        mid = lo + (hi-lo)/2; 
        
        if (nums[mid] > nums[hi]) { 
            lo = mid+1; 
        } 
        else { 
            hi = mid; 
        }

        min_item = mid; 
    }

    // if min item is not found for some reason, return. 
    if (min_item == -1) { 
        return -1; 
    } 

    // decide the half in which to binary search. 
    if (k >= nums[min_item] && k <= nums[nums.size()-1]) { 
        lo = min_item; 
        hi = nums.size() -1; 
    }
    else { 
        lo = 0; 
        hi = min_item-1; 
    }

    while (lo <= hi) { 
        mid = lo + (hi - lo)/2; 
        if (nums[mid] == k) { 
            return mid; 
        } 
        else if (nums[mid] > k) { 
            hi = mid-1; 
        } 
        else { 
            lo = mid+1; 
        }
    }    

    // search for k in the array.  
    return -1;  
}

int main()
{
    for (auto& t: tests) { 
        auto res = search_rotated(t.nums, t.k); 

        if (res == t.idx) { 
            cout << "test passed\n"; 
        }
        else { 
            cerr << "test failed\n";
        }
    }

}
