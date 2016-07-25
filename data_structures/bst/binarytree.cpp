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

int main(int argc, char ** argv)
{
    return 0; 
} 

