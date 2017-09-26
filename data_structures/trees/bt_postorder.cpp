#include <stack>
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

inline void pushall(TreeNode* root, stack<pair<TreeNode*, bool>> & s)
{ 
	while (root) { 
		s.push({root, false}); 
		root = root->left; 
	}
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res; 

	// the bool is to track if the right side of subtree is pushed to stack or not
	stack<pair<TreeNode*, bool>> s; 
	pushall(root, s); 
	
	while (!s.empty()) { 
		// if there is no right child or if it has already been visited. 
		if (!s.top().first->right || s.top().second) { 
			res.push_back(s.top().first->val); 
			s.pop();
		}
		// if there is a right subtree, then visit it. 
		else { 
			s.top().second = true; 
			pushall(s.top().first->right, s); 
		}
	}
	
	return res; 
}

int main()
{
    return 0;  
}
