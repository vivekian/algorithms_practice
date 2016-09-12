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

bool delete_node(bst_node* root, bst_node* delnode) 
{
    return true; 
} 

int main() 
{ 
    bst_node* root = make_tree(); 
    return 0; 
} 
