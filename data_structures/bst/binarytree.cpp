#include <iostream> 
#include <memory> 
#include <stack>
#include <vector> 

// solving problems listed in Chapter 10 (BinaryTrees) of EPI (Elements of Programming Interviews)

using namespace std; 

template <typename T> 
struct BT_node 
{ 
    T data; 
    unique_ptr<BT_node<T>> left, right; 
}; 

template <typename T>
void InorderTraversal(unique_ptr<BT_node<T>>& head)
{ 
    if (head->left) 
        InorderTraversal(head->left); 

    cout << head->data << " "; 

    if (head->right) 
        InorderTraversal(head->right); 
}

// A tree is balanced if the difference in the height of its left and right
// subtree is no more than 1. 
template <typename T> 
bool IsBalanced (unique_ptr<BT_node<T>>& head) 
{ 
    if (head->right && head->left) 
        return IsBalanced(head->left) && IsBalanced(head->right); 
    else if (!head->right && !head->left) 
        return true; 

    return false; 
}


// This refers to problem 10.2 in EPI. Something to remember is that "Key" is the 
// final solution which is passed by reference. the value returned is the number of 
// nodes which are children to a node. 
template <typename T>
int FindKthBalancedRoot(unique_ptr<BT_node<T>>& Root, int k, uint32_t& Key) 
{
   int lnodes = 0, rnodes = 0; 

   if (Root->left) 
      lnodes = FindKthBalancedRoot(Root->left, k, Key); 
   if (Root->right) 
      rnodes = FindKthBalancedRoot(Root->right, k, Key);
   if (abs(lnodes - rnodes) == k) 
      Key = Root->data;
    
   return rnodes + lnodes + 1; 
}

// solution to problem 10.3 if a tree is symmetric or not.
// key insight is to elimnate all the 'false' cases first.
// if the recursion reaches leaf null nodes, we return true. 
template <typename T> 
bool IsSymmetric(unique_ptr<BT_node<T>>& root1, unique_ptr<BT_node<T>>& root2) 
{ 
   if (!root1 && !root2) 
       return true;

   if ((!root1 && root2)  || (root1 && !root2)) 
       return false; 

   if (root1->data != root2->data) 
       return false; 
   
   return (IsSymmetric(root1->left, root2->right) && 
           IsSymmetric(root1->right, root2->left));
}

void TestSymmetry()
{ 
    unique_ptr<BT_node<uint32_t>> head = make_unique<BT_node<uint32_t>>();  
    head->data = 100;
    head->left = make_unique<BT_node<uint32_t>>(); 
    head->left->data = 50;
    head->left->right = make_unique<BT_node<uint32_t>>(); 
    head->left->right->data = 25; 
    head->right = make_unique<BT_node<uint32_t>>(); 
    head->right->data = 50;  
    head->right->left = make_unique<BT_node<uint32_t>>(); 
    head->right->left->data = 25; 
    cout << IsSymmetric(head, head) << endl; 
    head->right->left->data = 15; 
    cout << IsSymmetric(head, head) << endl; 
}

int main(int argc, char ** argv)
{
    TestSymmetry();
    return 0; 
} 

