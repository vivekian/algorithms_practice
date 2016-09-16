// find the first occurance of an item being searched for in an array of 
// elements which may have repeated elements. 

// problem 12.1 from EPI

#include <iostream> 
#include <vector> 

using namespace std; 

int bsearch(const vector<int>& a, const int T) 
{
    int lo = 0; 
    int hi = a.size() - 1;
    int res = -1; 

    while (lo <= hi) { 
       int mid = lo + ((hi - lo)/2); 

       if (a[mid] == T) { 
           res = mid;       // this is the key change, to record res and carry on. 
           hi = mid - 1; 
       } 
       else if (a[mid] > T) 
          hi = mid - 1;  
       else 
          lo = mid + 1; 
    }
    
    return res;            // return res here. 
}

struct testcase { 
    vector<int> arr; 
    int item;
    int result; 
};

int main() 
{ 
    vector<testcase> tests = { 
        { {1,2,3,4,5,6}, 4, 3}, 
        { {3,3,3,3,3,3,3}, 3, 0}, 
        { {0}, 0, 0},
        { {1,2,3,4,5,6,7,8,8}, 8, 7}  
    };

    for (auto t: tests) { 
       if (t.result == bsearch(t.arr, t.item)) { 
           cout << "test passed\n" << endl; 
       }
       else { 
           cout << "test failed\n" << endl; 
       }
    }

    return 0; 
}
