// This is solution to problem 144

#include <iostream> 
#include <vector> 
#include <stack> 

using namespace std; 

/**
 * Definition for a binary tree node.*/ 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res = {}; 
		stack<TreeNode*> nodes; 
		TreeNode* curr = root; 

		while (curr || !nodes.empty()) { 
			if (!curr) { 
				curr = nodes.top(); 
				nodes.pop(); 
			} 
			
			res.push_back(curr->val); 
			if (curr->right) { 
				nodes.push(curr->right); 
			} 

			curr = curr->left; 
		} 	

   		return res;  
    }
};

TreeNode* makeTree() 
{ 
	TreeNode* root = new TreeNode(1); 
	root->left = new TreeNode(2); 
	root->left->left = new TreeNode(4); 
	root->left->right = new TreeNode(5); 
	root->right = new TreeNode(3); 
	root->right->left = new TreeNode(6); 
	root->right->right = new TreeNode(7); 
	return root; 
} 

int main() 
{ 
	Solution solution; 
	TreeNode* root = makeTree(); 
	auto sol = solution.preorderTraversal(root); 

	for (auto s: sol) { 
		cout << s << ","; 
	} 

	return 0; 
} 
