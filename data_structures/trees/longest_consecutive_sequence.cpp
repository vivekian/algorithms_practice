// 298. Binary Tree Longest Consecutive Sequence 
/* 
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/ 

#include <algorithm> 

using namespace std; 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int longest(TreeNode* root, int currmax) 
{
    int lmax = currmax; 
    int rmax = currmax; 

    if (root->left) { 
        lmax = max(currmax, longest(root->left, (root->left->val == root->val+1) ? 
                                                currmax+1: 1)); 
    } 
    
    if (root->right) { 
        rmax = max(currmax, longest(root->right, (root->right->val == root->val+1) ? 
                                                currmax+1: 1)); 
    }

    return max(lmax, rmax) ; 
}

int longestConsecutive(TreeNode* root) {
    if (!root) { 
        return 0; 
    } 

    return longest(root, 1); 
}

int main()
{ 
    return 0; 
} 
