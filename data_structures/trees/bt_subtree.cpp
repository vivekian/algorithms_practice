#include <iostream> 

using namespace std;  

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool matchTree(TreeNode* s, TreeNode* t) { 
	if (!s && !t) { 
		return true; 
	} 

	if ((s && t) && (s->val == t->val)) { 
		return matchTree(s->left, t->left) && matchTree(s->right, t->right); 
	} 

	return false; 
}

bool isSubtree(TreeNode* s, TreeNode* t) {

	if (!s && !t) { 
		return true; 
	} 
	
	if ((!s && t) || (s && !t)) { 
		return false; 
	} 

    // this is the important idea here if values match, then explore subtrees. 
	if ((s->val == t->val) && (matchTree(s,t))) { 
        return true; 
    }

    // now explore again with left and right child.     
    return (isSubtree(s->left, t) || isSubtree(s->right, t)); 
}

int main()
{ 
	return 0; 
}
