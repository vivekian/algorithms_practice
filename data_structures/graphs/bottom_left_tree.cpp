// solution to problem 513 - Bottom Left Value of Leetcode. 

#include <queue> 
#include <iostream> 

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};  

int findBottomLeftValue(TreeNode* root) {
        
        if (!root) { 
            return 0; 
        } 
        
        queue<TreeNode*> items; 
        items.push(root);
        TreeNode* curr = nullptr; 
        
        while (!items.empty()) { 
                
                curr = items.front();
                items.pop(); 

                // pushing the right child first and then the left child 
                // is the key here. 
                if (curr->right) { 
                    items.push(curr->right);
                }
                if (curr->left) { 
                    items.push(curr->left);
                }
        }
                
        return curr->val; 
 }

int main() 
{ 
	TreeNode root(2), l(1), r(3); 
	root.left = &l; 
	root.right = &r; 

	cout << findBottomLeftValue(&root) << endl; 
	return 0; 
} 
