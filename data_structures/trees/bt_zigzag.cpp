// solution to problem 103 on leetcode 
#include <queue> 
#include <vector> 
#include <iostream> 

using namespace std; 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

struct Item{ 
	TreeNode* node; 
	int level; 
}; 

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res; 
	queue<Item> q; 

 	if (!root) { 
		return res; 
	} 

	q.push({root, 0}); 

	while (!q.empty()) { 
		Item item = q.front(); 
		q.pop();

        // this is not efficient, a better approach is to get 
        // the height of the tree, and then allocate enough memory. 
        res.resize(item.level+1);  

		// push item at the back if pushing left to right 
        if (!(item.level % 2)) { 
            res[item.level].push_back(item.node->val); 
        } 
        // push item at the front if printing right to left.
        else { 
            res[item.level].insert(res[item.level].begin(), item.node->val);
        }

        if (item.node->left) { 
            q.push({item.node->left, item.level+1});
        } 
        if (item.node->right) { 
            q.push({item.node->right, item.level+1});
        }        
	} 

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
	auto root = makeTree(); 
	auto res = zigzagLevelOrder(root); 
	printtree(cout, res); 
    return 0; 
} 
