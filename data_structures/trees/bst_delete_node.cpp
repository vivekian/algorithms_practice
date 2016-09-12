#include <queue> 
#include <iostream> 

using namespace std; 

struct bst_node 
{
    int value; 
    bst_node* left; 
    bst_node* right; 

    bst_node(int val): value(val), left(nullptr), right(nullptr) {} 
}; 

bst_node* make_tree() 
{ 
    bst_node* root = new bst_node(12); 
    
    root->left = new bst_node(5); 
    root->right = new bst_node(18); 

    root->left->left = new bst_node(2); 
    root->left->right = new bst_node(9); 
    root->right->left = new bst_node(15); 
    root->right->right = new bst_node(19); 

    root->right->left->right = new bst_node(17); 
    root->right->left->left = new bst_node(13); 

    return root; 
}

void write_bst(ostream& os, const bst_node* root) 
{ 
    if (!root) 
        return; 

    queue<const bst_node*> curr_level, next_level;

    curr_level.push(root); 

    while (!curr_level.empty()) { 
        auto node = curr_level.front(); 
        curr_level.pop(); 

        os << node->value << " "; 

        if (node->left) { 
           next_level.push(node->left); 
        } 
        if (node->right) {
           next_level.push(node->right);  
        }

        if (curr_level.empty()) { 
            swap(curr_level, next_level); 
            os << endl; 
        }
    } 
        
} 

bool delete_node(bst_node* root, bst_node* delnode) 
{
    return true; 
} 

int main() 
{ 
    bst_node* root = make_tree(); 
    write_bst(cout, root); 
    return 0; 
} 
