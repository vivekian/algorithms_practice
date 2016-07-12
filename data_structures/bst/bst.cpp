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

int main(int argc, char ** argv)
{
    vector<uint32_t> nums = {10, 20, 8, 35, 6, 22, 3}; 
    unique_ptr<BST_node<uint32_t>> head; 

    for (const auto &num: nums)
        head = Insert(move(head), num);  

    cout << Search(head, uint32_t(8)) << endl; 
    cout << Search(head, uint32_t(36)) << endl; 

    return 0; 
} 

