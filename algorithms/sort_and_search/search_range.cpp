#include <iostream> 
#include <vector> 

using namespace std; 

struct test { 
    vector<int> nums; 
    int k; 
    pair<int,int> range; 
};

namespace { 
    vector<test> tests = { 
        {{1,2,2,2,3,4,5,6}, 2, {1,3}}, 
        {{2,2,2,2,2,2,2,2}, 2, {0,7}}, 
        {{2}, 2, {0,0}}, 
        {{1,2,3,4,5,6,7,8,8}, 8, {7,8}},
        {{1,2,3,4,5,6,7,8,8}, 9, {-1,-1}},
        {{}, 8, {-1,-1}}
    };
}

pair<int,int> search_range(const vector<int>&nums, int k)
{ 
    // search for lower bound
    int lo=0; int hi=nums.size()-1; 
    int start=-1, end=-1; 
    
    while (lo <= hi) {  
        int mid = lo + (hi-lo)/2; 

        if (nums[mid] > k) { 
            hi = mid-1; 
        }
        else if (nums[mid] < k) { 
            lo = mid+1; 
        } 
        else { 
            // to search for start of range, remeber result and keep searching 
            // on the left
            start = mid; 
            hi = mid-1;
        }
    }

    // search for upper bound 
    lo = 0; hi = nums.size()-1; 
    
    while (lo <= hi) { 
        int mid = lo + (hi-lo)/2; 

        if (nums[mid] > k) { 
            hi = mid-1; 
        }
        else if (nums[mid] < k) { 
            lo = mid+1; 
        } 
        else { 
            // to search for end of range, remember result and keep searching
            // on the right.
            end = mid; 
            lo = mid+1;
        }
    }

    return make_pair(start, end); 
}

int main()
{
    for (const auto& t: tests) { 
        auto res = search_range(t.nums, t.k); 

        if ((res.first == t.range.first) && (res.second == t.range.second)) { 
            cout << "test passed\n"; 
        }
        else { 
            cerr << "test failed\n";
        }
    }

}
