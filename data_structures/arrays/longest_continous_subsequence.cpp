#include <vector> 
#include <string> 
#include <iostream> 

using namespace std; 

int findLengthOfLCIS(vector<int>& nums) 
{
	if (nums.empty()) { 
		return 0; 
	}

	int cnt = 1, maxcnt = 1; 
	
	for (int i=1; i<nums.size(); ++i) { 
		if (nums[i] > nums[i-1]) { 
			++cnt; 
			maxcnt = max(cnt, maxcnt); 
		} 
		else { 
			cnt = 1; 
		} 
	} 

	return maxcnt;  	       
}

namespace { 
	struct test{ 
		vector<int> v; 
		int res; 
	}; 

	vector<test> testcases = { 
		{{1,2,3}, 3}, 
		{{3,2,1}, 1}, 
		{{1,2,3,7,4,5}, 4}}; 
}

int main()
{
	for (test& t: testcases) { 
		if (t.res != findLengthOfLCIS(t.v)) { 
			cerr << "longest subsequence" << endl; 
		} 
	} 

	return 0; 
}
