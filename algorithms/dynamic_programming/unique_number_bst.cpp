#include <vector> 
using namespace std; 

class Solution {
private: 
    inline int numTree_helper(int n, vector<int>& nut) { 
        int total_nut = (nut[n] == -1) ? 0: nut[n]; 
        
        if (total_nut) { 
            return total_nut; 
        }
     
		// for each i it could be a root, and there would be 
		// i-1 size left subtree and n-i right subtree.    
		// recursively compute them and then multiply them because we 
		// need to get total number of possibilities of unique trees. 
        for (int i=1; i<=n; ++i) { 
            total_nut += numTree_helper(i-1, nut) * 
                         numTree_helper(n-i, nut); 
        }
        
        nut[n] = total_nut; 
        return total_nut; 
    }
    
public:
    int numTrees(int n) {
        if (n <= 2) 
            return n; 
 
		// memoization so that we don't recurse over and over again.        
        vector<int> nut(n+1, -1); 
        nut[0] = 1; 
        nut[1] = 1; 
      
        return numTree_helper(n, nut); 
    }
};
