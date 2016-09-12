// solution to problem 15.15 of EPI (Elements of Programming Interviews) 

#include <algorithm> 
#include <iostream> 
#include <queue> 
#include <vector>

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
    root->right->left->right->left = new bst_node(16); 
    root->right->left->left = new bst_node(13); 

    return root; 
}

bool is_node_descendent(bst_node* root, bst_node* child) 
{ 
    if (!root) { 
       return false; 
    }  
    if (root == child) { 
        return true; 
    } 

    return is_node_descendent(root->left, child) || 
           is_node_descendent(root->right, child); 
} 

void find_nodes(bst_node* root, vector<int>& keys, vector<bst_node*>& nodes) 
{
    if (!root) { 
       return; 
    } 

    if (keys.end() != find(keys.begin(), keys.end(), root->value)) { 
        nodes.push_back(root); 
    } 

    find_nodes(root->left, keys, nodes); 
    find_nodes(root->right, keys, nodes); 
} 

bool are_nodes_ordered(bst_node* root, vector<int> keys) 
{ 
    vector<bst_node*> nodes; 
 
    find_nodes(root, keys, nodes); 

    if (nodes.size() != 3) { 
       return false; 
    } 

    return is_node_descendent(nodes[0], nodes[1]) && 
           is_node_descendent(nodes[1], nodes[2]);  
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

    cout << are_nodes_ordered(root, vector<int>{12, 15, 16}) << endl; 
    cout << are_nodes_ordered(root, vector<int>{12, 15, 19}) << endl; 

    return 0; 
} 
