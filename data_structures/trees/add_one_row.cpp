 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

void insert(TreeNode* root, int v, int d) { 

	if (d == 2) { 
		TreeNode* lnode = new TreeNode(v); 
		TreeNode* rnode = new TreeNode(v); 

		lnode->left = root->left; 
		rnode->right = root->right; 
 
		root->left = lnode; 
		root->right = rnode; 
	} 
	else { 
		if (root->left)
			insert(root->left, v, d-1); 
		if (root->right) 
			insert(root->right, v, d-1); 
	}		
} 
 
TreeNode* addOneRow(TreeNode* root, int v, int d) {
	if (!d) { 
		return root; 
	} 

	if (d == 1) { 
		TreeNode* newroot = new TreeNode(v); 
		newroot->left = root; 
		root = newroot; 
	}

	insert(root, v, d); 	

	return root; 	
}

int main() 
{ 
	return 0; 
} 
