#include <iostream> 
#include <memory> 
#include <vector> 

using namespace std; 

template <typename T> 
struct BST_node 
{ 
    T data; 
    unique_ptr<BST_node<T>> left, right; 
}; 

template <typename T> 
unique_ptr<BST_node<T>> Insert(unique_ptr<BST_node<T>> head, const T& item) 
{ 
    if (!head) {
        head = make_unique<BST_node<T>>(); 
        head->data = item; 
        return head;
    } 

    if (item < head->data)
        head->left = Insert(move(head->left), item);
    else
        head->right = Insert(move(head->right), item); 

    return head; 
}

template <typename T>
void InorderTraversal(unique_ptr<BST_node<T>>& head)
{ 
    if (head->left) 
        InorderTraversal(head->left); 

    cout << head->data << " "; 

    if (head->right) 
        InorderTraversal(head->right); 
}

template <typename T> 
bool Search(const unique_ptr<BST_node<T>>& head, const T& item) 
{ 
    if (head && head->data == item) 
        return true; 

    if (item < head->data && head->left) 
        return Search(move(head->left), item); 
    else if (head->right)
        return Search(move(head->right), item); 

    return false; 
}

template <typename T> 
BST_node<T>* FindKey(unique_ptr<BST_node<T>>& head, const T& item)
{
   BST_node<T>* tmp = head.get();

   while (tmp) { 
      if (tmp->data == item) 
         return tmp; 

      if (item < tmp->data) 
          tmp = tmp->left.get(); 
      else  
          tmp = tmp->right.get(); 
   }

   return nullptr;    
}

template <typename T> 
void FindKLargestItems(unique_ptr<BST_node<T>>& head, int k, vector<T>& items)
{
   unique_ptr<BST_node<T>> &tmp = head; 

   if (tmp->right && items.size() != k) 
        FindKLargestItems(tmp->right, k, items); 

   if (items.size() != k) 
       items.emplace_back(tmp->data);

   if (tmp->left && items.size() != k) 
       FindKLargestItems(tmp->left, k, items);  
} 

/* 
template <typename T> 
T FindKthLargestUsingStack(unique_ptr<BST_node<T>>& head, int k) 
{ 

}
*/ 


template <typename T>
bool IsBST(const unique_ptr<BST_node<T>>& head, T lower, T higher) 
{
    bool isLeft, isRight; 

    if (!head) 
        return true; 

    if (head->data < lower || head->data > higher) 
        return false; 

    return (IsBST(head->left, lower, head->data) && 
            IsBST(head->right, head->data, higher)); 
} 

int main(int argc, char ** argv)
{
    vector<uint32_t> nums = {10, 20, 8, 35, 6, 22, 3}; 
    unique_ptr<BST_node<uint32_t>> head; 

    for (const auto &num: nums)
        head = Insert(move(head), num);  

    InorderTraversal(head); 
    cout << endl; 

    cout << Search(head, uint32_t(8)) << endl; 
    cout << Search(head, uint32_t(36)) << endl; 
    cout << IsBST(head, numeric_limits<uint32_t>::min(), numeric_limits<uint32_t>::max()) << endl; 

    InorderTraversal(head);  
    cout << endl;

    cout << FindKey(head, uint32_t(8))->data << endl; 
   
    InorderTraversal(head);  
    cout << endl; 
    vector<uint32_t> items; 
    FindKLargestItems(head, 3, items); 

    for (const auto& item: items) 
       cout << item << endl;  

    return 0; 
} 

