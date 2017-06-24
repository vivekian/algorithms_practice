#include <iostream> 
#include <stack>

using namespace std;  

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private: 
    stack<TreeNode*> s; 
    
public:
    BSTIterator(TreeNode *root) {
        while (root) { 
            s.push(root); 
            root = root->left; 
        }    
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        
        auto node = s.top(); 
        s.pop(); 
        int res = node->val; 
            
        if (node->right) { 
            s.push(node->right); 
            node = node->right; 
                
            while (node->left) { 
                s.push(node->left); 
                node = node->left; 
            } 
        }
        
        return res; 
    }
};

int main() 
{ 
	TreeNode root(5); 
	root.left = new TreeNode(2); 
	root.right = new TreeNode(7); 

	BSTIterator i = BSTIterator(&root);
    while (i.hasNext()) cout << i.next();	
	cout << endl; 
	return 0; 
} 
