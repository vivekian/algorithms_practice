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
        {{1,2,3,5,6,7}, 4, 3},
        {{1,2,3,5,6,7}, 3, 2},
        {{1,2,3,5,6,7}, 8, 6},
        {{1,2,3,5,6,7}, 0, 0},
        {{}, 1, 0},
        {{1}, 2, 1},
        {{1}, 0, 0},
  };
}

int search_insert(vector<int>&nums, int k)
{
    int lo=0, hi=nums.size()-1; 

    while (lo <= hi) { 
        int mid = lo + (hi - lo)/2; 

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

    return lo; 
}

int main()
{
    for (auto& t: tests) { 
        auto res = search_insert(t.nums, t.k); 

        if (res == t.idx) { 
            cout << "test passed\n"; 
        }
        else { 
            cerr << "test failed\n";
        }
    }

}
