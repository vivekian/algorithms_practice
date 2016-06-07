// find the element which is greater than a given key k 
// return -1 if all elements are smaller or equal to k 
// problem 12.2 from EPI 

#include <iostream> 
#include <vector> 

using namespace std; 

int upper_bound(const vector<int>& a, const int k) 
{ 
    int lo = 0; 
    int hi = a.size()-1; 
    int mid = -1; 

    while (lo <= hi) { 
        mid = lo + (hi - lo)/2; 
        
        // this is the key - even if the element is found, keep going as we have
        // to look for the next greater element. 
        if (a[mid] <= k) 
            lo = mid+1; 
        else 
            hi = mid-1; 
    }

    // if there is no upper bound, then for sure lo will keep moving to the right
    // till it goes out of bound and then no upper_bound exists. 
    if (lo == a.size()) 
        return -1; 
    
    return lo; 
}

struct test { 
    vector<int> arr; 
    int k; 
    int res; 
};

int main() 
{
   vector<test> testcases = { 
       { {1,2,5,5,6,8,9,10}, 5, 4}, 
       { {1,2,5,5,6,8,9,10}, 11, -1},
       { {1,2,5,5,6,8,9,10}, 2, 2},
       { {1,2,5,5,6,8,9,10}, 0, 0},
       { {1,2,5,5,6,8,9,10}, 7, 5}
   };

   for (auto &test: testcases) { 
       if (test.res != upper_bound(test.arr, test.k)) { 
           cout << "test failed\n" << endl; 
       }
   }

   return 0; 
}
        
