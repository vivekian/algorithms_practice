// solve https://leetcode.com/problems/minimum-depth-of-binary-tree/
// find the min height of a tree - leaf node which is closest to the root. 

#include <algorithm> 

struct node { 
    int val; 
    node* left; 
    node* right; 
}; 

int get_min_height(node* root) 
{ 
    if (!root) { 
        return 0; 
    } 

    // if a leaf node, return 1 
    if (!root->left && !root->right) { 
        return 1; 
    } 

    int lh = 0; 
    int rh = 0; 

    if (root->left) { 
        lh = get_min_height(root->left);  
    } 

    if (root->right) { 
        rh = get_min_height(root->right); 
    } 

    // if there is no right child then just take the left subtree's height and return it
    // same if there is no left child then just take the right subtree's height and return it
    if (!rh) { 
        return lh+1; 
    } 
    if (!lh) { 
        return rh+1; 
    } 

    // both subtrees exist, then take the minimum and return. 
    return std::min(lh, rh) + 1; 
} 

int main()
{ 
    node root; 
    return 0; 
} 
