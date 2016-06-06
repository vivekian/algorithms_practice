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

    while (lo <= hi) { 
       int mid = lo + ((hi - lo)/2); 

       if (a[mid] == T) 
          return mid; 
       else if (a[mid] > T) 
          hi = mid - 1;  
       else 
          lo = mid + 1; 
    }
    
    return -1; 
}

int findFirstItem(const vector<int>& a, const int T) 
{ 
    int index = bsearch(a, T); 
  
    if (index == -1) 
        return index; 
    
    index--; 

    while (index >= 0) {     
        if (a[index] != T) { 
           break;  
        }
        index--; 
    }

    return index+1;
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
       if (t.result == findFirstItem(t.arr, t.item)) { 
           cout << "test passed\n" << endl; 
       }
       else { 
           cout << "test failed\n" << endl; 
       }
    }

    return 0; 
}
