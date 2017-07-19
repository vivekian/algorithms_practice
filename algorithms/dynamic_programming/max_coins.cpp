#include <iostream> 
#include <unordered_map>
#include <string> 
#include <vector>
#include <sstream> 
#include <algorithm>  

using namespace std; 

namespace { 
    unordered_map<string, int> memo;

    string tostr(const vector<int>& v) { 
		 stringstream ss;
    	 copy( v.begin(), v.end(), ostream_iterator<int>(ss, " "));
		 return ss.str();
    } 
}

// recursive solution not DP.
int max_coins(vector<int>& nums) 
{
    const int len = nums.size(); 

    if (!len) { 
        return 0;
    }

    int res = 0; 

    for (int i=0; i<len; ++i) { 
        int currsum = nums[i] * 
                      ((i == 0)?1:nums[i-1]) * 
                      ((i==len-1)?1:nums[i+1]);
        auto next = nums; 
        next.erase(next.begin() + i); 
        res = max(res, currsum + max_coins(next));
    }

    return res; 
}

int main()
{
   vector<int> nums = {3, 1, 4,  7};
   cout << max_coins(nums) << endl; 
}
