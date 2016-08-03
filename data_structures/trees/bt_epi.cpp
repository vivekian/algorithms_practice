#include <iostream> 
#include <list> 
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

    BT_node():left(nullptr), right(nullptr){}
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

// solution to problem 10.6 of EPI 
// if you are going to a nullptr from a leaf node, it does not contribute.
// if you are going to a leaf node, then add its value to the sum and return.
uint32_t SumNodes(unique_ptr<BT_node<bool>> &root, uint32_t num) 
{ 
    if (!root) 
        return 0; 

    num = (num << 1) + (root->data);
    
    if (!root->left && !root->right) 
        return num; 

    return SumNodes(root->left, num) + 
           SumNodes(root->right, num); 
}

bool DoesPathSumMatch(unique_ptr<BT_node<uint32_t>> &root, const uint32_t sum, uint32_t num) 
{ 
    if (!root) 
        return false; 

    num += root->data; 

    if (num == sum) 
        return true; 

    return (DoesPathSumMatch(root->left, sum, num) || 
            DoesPathSumMatch(root->right, sum, num));
}

// Insert all the leaf nodes in a linked list as they appear from left to right
template <typename T> 
void GetLeafNodes (const unique_ptr<BT_node<T>> &root, list<T> &leafnodes) 
{
   if (!root) 
      return; 

   GetLeafNodes(root->left, leafnodes);  

   if (!root->left && !root->right) 
       leafnodes.push_back(root->data); 

   GetLeafNodes(root->right, leafnodes); 
} 

unique_ptr<BT_node<uint32_t>> MakeTree() 
{ 
    unique_ptr<BT_node<uint32_t>> head = make_unique<BT_node<uint32_t>>();  
    head->data = 30; 
    head->left = make_unique<BT_node<uint32_t>>(); 
    head->left->data = 20;
    head->left->left = make_unique<BT_node<uint32_t>>(); 
    head->left->left->data = 10; 
    head->left->right = make_unique<BT_node<uint32_t>>(); 
    head->left->right->data = 25; 
    head->right = make_unique<BT_node<uint32_t>>(); 
    head->right->data = 50;  
    head->right->left = make_unique<BT_node<uint32_t>>(); 
    head->right->left->data = 25; 
    head->right->right = make_unique<BT_node<uint32_t>>(); 
    head->right->right->data = 70; 

    return head; 
} 

// The key idea is to store the right children in the stack 
// to be remembered and processed at a later stage. The current
// node will always be processed right away and the left node is processed
// first after the current node is done. 
void PreOrderTraversal(const unique_ptr<BT_node<uint32_t>>& head)
{
    BT_node<uint32_t>* curr = head.get();
    stack<BT_node<uint32_t>*> stk; 

    while (curr) {
        cout << curr->data << " "; 
        
        if (curr->right) 
            stk.push(curr->right.get()); 
       
        // keep going left as long as nodes exist 
        curr = (curr->left) ? curr->left.get(): nullptr; 

        // if a node does not exist, then pop out a right child
        if (!curr && !stk.empty()){
           curr = stk.top(); 
           stk.pop(); 
        }
    }

    cout << endl; 
}

void InorderTraversal(const unique_ptr<BT_node<uint32_t>> &head) 
{ 
    stack<BT_node<uint32_t>*> stk; 
    BT_node<uint32_t>* curr = head.get(); 

    // the key here is to push all the elements on the stack atleast once. 
    while (curr || !stk.empty()) { 
        if (curr->left) { 
            stk.push(curr); 
            curr = curr->left.get(); 
        }
        else { 
            curr = stk.top(); 
            stk.pop(); 
            cout << curr->data << "\n"; 
            curr = curr->right.get(); 
        }
    }

    cout << endl; 
}


void TestPreorder() 
{ 
    unique_ptr<BT_node<uint32_t>> head = MakeTree(); 
    PreOrderTraversal(head); 
    InearrderTraversal(head); 
} 

void TestLeafNodes() 
{ 
    unique_ptr<BT_node<uint32_t>> head = MakeTree(); 
    list<uint32_t> leafnodes; 
    GetLeafNodes(head, leafnodes); 

    for (const auto& leaf: leafnodes) 
        cout << leaf << " "; 

    cout << endl; 
}

void TestPathSumMatch() 
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
 
    cout << DoesPathSumMatch(head, 175, 0) << endl; 
    cout << DoesPathSumMatch(head, 155, 0) << endl; 
}

void TestSumNodes() 
{ 
    unique_ptr<BT_node<bool>> head = make_unique<BT_node<bool>>(); 
    head->data = 1; 
    head->left = make_unique<BT_node<bool>>(); 
    head->left->data = 0; 
    head->left->left = make_unique<BT_node<bool>>(); 
    head->left->left->data = 1; 
    head->left->right = make_unique<BT_node<bool>>(); 
    head->left->right->data = 1; 
    head->right = make_unique<BT_node<bool>>(); 
    head->right->data = 1;

    cout << SumNodes(head,0) <<endl;  
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
    head->right->left->data = 45; 
    cout << IsSymmetric(head, head) << endl; 
    head->right->left->data = 15; 
    cout << IsSymmetric(head, head) << endl; 
}

int main(int argc, char ** argv)
{
    TestSymmetry();
    TestSumNodes();
    TestPathSumMatch(); 
    TestLeafNodes(); 
    TestPreorder(); 
    return 0; 
} 

