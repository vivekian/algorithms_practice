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
    root->right->right = new bst_node(20); 
    root->right->right->left = new bst_node(19); 

    root->right->left->right = new bst_node(17); 
    root->right->left->left = new bst_node(13); 

    return root; 
}

void assign_child_to_parent(bst_node* parent, bst_node* child, bool ischildright) 
{ 
    if (ischildright) { 
        parent->right = child; 
    } 
    else { 
        parent->left = child; 
    } 
} 

void delete_node_helper(bst_node* parent, bst_node* delnode) 
{
    cout << "deleting node with value " << delnode->value << endl; 
    bool ischildright = parent->right == delnode; 

    // please see page 297 of introduction to algorithms for all cases 
    // if right child does not exist, then promote left child of the node to be deleted 
    if(!delnode->right) { 
        assign_child_to_parent(parent, delnode->left, ischildright); 
        return; 
    }
    // if left child does not exist, then promote right child of the node to be deleted  
    else if (!delnode->left) { 
        assign_child_to_parent(parent, delnode->right, ischildright); 
        return; 
    }
    // if both children exist for the node to be deleted  
    else {
        // if the right child's left child does not exist for the node to be deleted. 
        // then assign promote the right child assign the node to be deleted's left child 
        // to the empty left pointer.  
        if (!delnode->right->left) { 
            assign_child_to_parent(parent, delnode->right, ischildright); 
            delnode->right->left = delnode->left; 
        } 
        // this is the complex case. 
        else { 
            auto tmp = delnode->right->left; 
            delnode->right->left = tmp->right; 
            tmp->right = delnode->right; 
            tmp->left = delnode->left; 
            assign_child_to_parent(parent, tmp, ischildright);   
        } 
    } 

    delete delnode; 
} 

bool delete_node(bst_node* root, bst_node* delnode) 
{ 
    bool lres, rres;  
    if (root->right == delnode || root->left == delnode) 
    { 
        delete_node_helper(root, delnode); 
        return true; 
    } 

    if (root->left) { 
        lres = delete_node(root->left, delnode); 
    }
    if (root->right) {  
        rres = delete_node(root->right, delnode); 
    } 

    return lres || rres; 
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

int main() 
{ 
    bst_node* root = make_tree(); 
    write_bst(cout, root); 
    delete_node(root, root->left->left);
    cout << endl; 
    write_bst(cout, root);  
    cout << endl; 
    delete_node(root, root->right->left); 
    write_bst(cout, root); 
    delete_node(root, root->right); 
    write_bst(cout, root); 
    return 0; 
} 
