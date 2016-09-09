// create a bst from a sorted list stored in a vector. 
// solution uses recursion to create the root and then the 
// right and left children from the midpoints. 

#include <iostream> 
#include <vector> 

using namespace std; 

template <typename T>
struct bst_node 
{ 
    T val; 
    bst_node* right; 
    bst_node* left; 

    bst_node(T value): val(value), right(nullptr), left(nullptr){}
}; 

template <typename T> 
bst_node<T>* make_tree_helper(const vector<T>& items, const int start, const int end) 
{
    int mid = (start + (end - start)/2); 
    bst_node<T>* root = new bst_node<T>(items[mid]); 

    if (mid+1 <= end) { 
        root->right = make_tree_helper(items, mid+1, end); 
    }
    
    if (start <= mid-1) { 
        root->left = make_tree_helper(items, start, mid-1); 
    } 

    return root; 
}

template <typename T> 
bst_node<T>* make_tree_sorted_list(const vector<T>& items) 
{
    return make_tree_helper(items, 0, items.size() - 1); 
}

template <typename T> 
void write(ostream& os, const bst_node<T>* root) 
{ 
    const bst_node<T>* node = root; 

    if (!node) { 
        return; 
    }
    
    if (node->left) { 
       write(os, node->left); 
    } 
    
    os << node->val << " "; 

    if (node->right) { 
       write(os, node->right); 
    }  
} 

int main()
{
    vector<int> items = {1, 2, 3, 4, 5, 6}; 
    bst_node<int>* root = make_tree_sorted_list(items); 
    write(cout, root);

    return 0; 
} 
