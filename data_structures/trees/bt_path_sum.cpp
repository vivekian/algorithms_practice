#include <numeric> 
#include <iostream> 
#include <vector> 

using namespace std; 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 
void preorder(TreeNode* root, int target, vector<int> currpath, vector<vector<int>>& res) 
{
	currpath.push_back(root->val); 
 
	// if leaf node, then add to path and return.
	if (!root->left && 
		!root->right && 
		(std::accumulate(currpath.begin(), currpath.end(), 0) == target)) { 
		res.push_back(currpath); 
	}
	else {
		if (root->left) { 
			preorder(root->left, target, currpath, res); 
		} 
		if (root->right) { 
			preorder(root->right, target, currpath, res); 
		} 
	}
}
			
	

vector<vector<int>> pathsum(TreeNode* root, int sum) 
{
	vector<vector<int>> res; 

	if (!root) { 
		return res; 
	} 
	
	vector<int> currpath; 
	preorder(root, sum, currpath, res); 

	return res; 			 
} 

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

void printtree(ostream& out, vector<vector<int>>& treepaths) 
{
	for (const auto& path: treepaths) { 
		for (const auto item: path) { 
			out << item << ","; 
		} 
		out << "\n"; 
	} 
}

int main() 
{
	TreeNode* root = makeTree(); 
	auto res = pathsum(root, 10);  
	printtree(cout, res); 
	return 0; 
} 
