// find the smallest element in a cyclic sorted array
// Problem 12.4 of EPI. 

#include <iostream> 
#include <vector> 

using namespace std; 

int findSmallestCyclic(const vector<int> &A) 
{ 
    int lo = 0; 
    int hi = A.size() - 1; 
    int mid; 

    while (lo <= hi) { 
        
        mid = lo + (hi - lo)/2;
        
        // this case establishes that the start of the cycle is on the right.  
        if (A[mid] > A[hi]) {
            lo = mid+1; 
        } 
        // this case establishes that the start of the cycle is on the left
        // but could include the midpoint itself.
        else if (A[mid] < A[lo]) { 
            hi = mid;
        }
        // if the midpoint is greater than lo, then hi can be moved to 
        // one position to the left of mid. 
        else { 
            hi = mid -1; 
        }
    }

    return mid; 
}

struct test { 
    vector<int> arr; 
    int res; 
}; 

int main() 
{ 
    vector<test> testcases = { 
        { {0, 1, 2, 3, 4, 5}, 0},
        { {10, 11, 2, 3, 4, 5}, 2},
        { {10, 0, 2, 3, 4, 5}, 1}, 
        { {1, 2, 3, 4, 5, 6, 7, 8, 0}, 8}
    }; 

    for (auto& test: testcases) { 
        if (findSmallestCyclic(test.arr) != test.res) { 
            cout << "test failed" << endl; 
        }
    }

    return 0; 
}
