// this solves problem 12.3 of EPI 
// return the index i when A[i] == i 
// return -1 when no such index exists 

#include <iostream> 
#include <vector> 

using namespace std; 

int find_index_item_match(const vector<int> &A) 
{ 
    int lo = 0; 
    int hi = A.size()-1; 

    while (lo <= hi) { 
        int mid = lo + (hi - lo)/2; 
        if (A[mid] == mid) 
            return mid; 
        if (A[mid] > mid) 
            hi = mid-1; 
        else 
            lo = mid+1; 
    }

    return -1; 
}

struct test { 
    vector<int> arr; 
    int res; 
};

int main() 
{ 
    vector<test> testcases = { 
        { {-1, 1, 2, 5, 7, 9, 22}, 1}
    }; 

    for (auto test: testcases) { 
        if (find_index_item_match(test.arr) != test.res) { 
            cout << "test failed\n" << endl; 
        }
    }

    return 0; 
}


