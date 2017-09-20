#include <algorithm> 
#include <vector>
#include <iostream> 

using namespace std; 

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
    int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); 
    int l = r-1; 
    int len = arr.size(); 
    vector<int> res; 

    for (int i=0; i<k; ++i) { 
        if (l < 0) { 
            res.emplace_back(arr[r++]); 
        }
        else if (r >= len) { 
            res.emplace_back(arr[l--]); 
        }
        else { 
            res.emplace_back((abs(arr[l] - x) <= abs(x - arr[r])) ? arr[l--] : arr[r++]); 
        }
    }

    sort(res.begin(), res.end()); 

    return res; 
}

namespace { 
    struct test { 
        vector<int> in; 
        int k; 
        int x; 
        vector<int> res; 
    }; 

    vector<test> testcases = { 
        {{-98, -60, -1, 3, 26}, 2, 0, {-1, 3}}, 
        {{-98, -60, -1, 3, 26}, 2, -1000, {-98, -60}},
        {{-98, -60, -1, 3, 26}, 2, 1000, {3, 26}}, 
        {{-3,-1,0,2,5,6}, 3, 1, {-1,0,2}}
    };
}

int main()
{ 
    for (auto& t: testcases) { 
        if (findClosestElements(t.in, t.k, t.x) != t.res) { 
            cerr << "failed" << "\n"; 
        }
    }

    return 0; 
}
