#include <algorithm> 
#include <vector> 
#include <iostream> 
#include <queue> 

using namespace std;  
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

vector<double> averageOfLevels(TreeNode* root) {

	vector<double> res; 
	queue<TreeNode*> q; 

	q.push(root); 

	while (!q.empty()) { 
		vector<TreeNode*> tmp; 
		
		while (!q.empty()) { 
			tmp.push_back(q.front()); 
			q.pop(); 
		} 

		long sum = 0; 
	    for (auto &n: tmp) { 
			sum += n->val; 
			
			if (n->left) { 
				q.push(n->left); 
			} 
			if (n->right) { 
				q.push(n->right); 
			} 
		} 

		res.push_back(static_cast<double>(sum)/tmp.size()); 	
	} 		

	return res; 	
}
