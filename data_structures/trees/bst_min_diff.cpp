

/* Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

*/

#include <vector> 
#include <algorithm> 
#include <cstdlib>
#include <limits>  
#include <utility> 

using namespace std; 

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root, vector<int>& res)
{
    if (root->left) { 
        preorder(root->left, res); 
    }
    
    res.push_back(root->val); 
    
    if (root->right) { 
        preorder(root->right, res); 
    } 
}

int getMinimumDifference(TreeNode* root) {

        if (!root) {
                return 0;
        }
       
		vector<int> res;  
        preorder(root, res); 
        
        int minvalue = abs(res[1] - res[0]);
        
        for (int i=2; i<res.size(); ++i) { 
            if (abs(res[i] - res[i-1]) < minvalue) {
                minvalue = abs(res[i] - res[i-1]); 
            }
        }
        
        return minvalue; 
}

int  main()
{ 
	return 0; 
}  
