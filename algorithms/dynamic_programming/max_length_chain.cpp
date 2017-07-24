#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

inline bool isvalid (vector<int>& a, vector<int>& b) { 
	return (a[1] < b[0]);
}
    
int findLongestChain(vector<vector<int>>& pairs) {
	
	auto cmp = [](const vector<int>& p1, const vector<int>& p2) { return p1[0] < p2[0];};
	sort(pairs.begin(), pairs.end(), cmp); 
	
	int len = pairs.size(); 
    
    if (!len) { 
        return 0; 
    }
	
    vector<int> max_cnt(len, 1); 
	int global_max = 1; 

	for (int i=len-1; i >= 0; --i) { 
		for (int j=i; j<len; ++j) { 
			if (isvalid(pairs[i], pairs[j])) { 
				max_cnt[i] = max(max_cnt[i], max_cnt[j] + 1); 
				global_max = max(max_cnt[i], global_max); 
			} 
		}
	}

	return global_max; 	
}

int main() 
{ 
	vector<vector<int>> pairs = {{1,2},{3,4},{3,5},{5,6},{6,7},{8,9}}; 
	cout << findLongestChain(pairs) << endl;

	return 0; 
} 
