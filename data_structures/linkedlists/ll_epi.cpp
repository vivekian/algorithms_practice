// Given an input linked list and a function pointer to a filter function, return a 
// linked list which has nodes which pass the filter function. Create a new linked list 

#include <iostream> 
#include <vector> 

using std::vector; 
using std::cout; 

template <typename T>
struct Node 
{ 
    Node(T in):data(in),next(nullptr) {}
    T data; 
    Node* next; 
};

// the pointer to the function is const, not the function itself. 
// the data pointed to by head is const, not the pointer itself. 
template <typename T>
Node<T>* FilterLinkedList(const Node<T>* head, bool (*const func) (const T& data))
{
    Node<T>* newhead = nullptr, *newcurr = nullptr; 
    const Node<T>* curr = head; 

    while (curr) {
        if (func(curr->data)) { 
            if (!newhead) { 
                newhead = new Node<T>(curr->data);  
                newcurr = newhead; 
            }
            else { 
               newcurr->next = new Node<T>(curr->data); 
               newcurr = newcurr->next;  
            }
        }
        curr = curr->next; 
    }        
     
    return newhead; 
} 

// delete a node in a singly linked list
template <typename T>
Node<T>* Delete(Node<T>* head, const T& data) 
{
    Node<T>* curr = head, *prev = curr; 

    if (head->data == data) { 
        head = head->next; 
        free(curr); 
        return head; 
    } 

    curr = curr->next; 

    while (curr) {

        if (curr->data == data) { 
            prev->next = curr->next; 
            free(curr); 
            break;
        }

        prev = curr; 
        curr = curr->next; 
    }

    return head; 
}

// Reverse a linked list 
template <typename T> 
Node<T>* Reverse(Node<T>* const head) 
{ 
    if (!head || !head->next) 
        return head; 
    
    Node<T>* prev = head, *curr = head->next; 
    head->next = nullptr; 

    while (curr) { 
       Node<T>* nextnode = curr->next; 
       curr->next = prev; 
       prev = curr; 
       curr = nextnode; 
    } 

    return prev; 
} 

// Remove duplicates from a sorted single linked list 
template <typename T> 
void RemoveDuplicates(Node<T>* head)
{ 
    if (!head || !head->next) 
        return; 

    Node<T>* curr = head->next, *prev = head; 
   
    while (curr) { 
     
        if (curr->data == prev->data) { 
            prev->next = curr->next; 
            free(curr); 
            curr = prev->next;  
        }
        else {
            prev = curr; 
            curr = curr->next; 
        } 
     }

}

template <typename T> 
Node<T>* Midpoint(Node<T>* head) 
{ 
    if (!head || !head->next) 
        return head; 

    Node<T> *curr = head, *fwd = curr; 

    while (fwd && fwd->next) {
        curr = curr->next;
        fwd = fwd->next->next; 
    }

    return curr; 
} 

// validate if a given single linked list has its elements 
// in a palindrome
template <typename T> 
bool IsPalindrome(Node<T>* head) 
{ 
    Node<T>* midpoint = Midpoint(head); 
    Node<T>* reversed = Reverse(midpoint); 
    
    while (head && reversed) { 
        // reached the midpoint with odd number of elements 
        if (head == reversed) 
            return true; 
        
        if (head->data != reversed->data) { 
            return false; 
        } 

        head = head->next; 
        reversed = reversed->next; 
    }

    // reached end of list with 
    return true; 
}

template <typename T> 
Node<T>* Insert(const vector<T>& data)
{ 
    if (data.empty()) 
        return nullptr; 

    Node<T>* head = nullptr, *curr = nullptr; 

    for (const auto& item: data) 
    { 
        if (!head) { 
           head = new Node<T>(item); 
           curr = head; 
        } 
        else { 
            curr->next = new Node<T>(item); 
            curr = curr->next; 
        }
    }

    return head; 
} 

template <typename T> 
void Print(const Node<T>* const head)
{ 
    const Node<T>* curr = head; 

    while(curr) { 
        cout << curr->data << " "; 
        curr = curr->next; 
    }

    cout << "\n";  
}

bool Filter(const uint32_t& item) 
{ 
    return (item % 2); 
}

void TestNodeFilter()
{ 
    vector<uint32_t> items = {1,2,3,4,5}; 
    Node<uint32_t>* head = Insert(items); 
    Print(head); 
    
    Node<uint32_t> *filterhead = FilterLinkedList(head, Filter);     
    Print(filterhead); 
} 

void TestDeleteNode() 
{ 
    vector<uint32_t> items = {1,2,3,4,5}; 
    Node<uint32_t>* head = Insert(items); 
    Print(head); 
    
    uint32_t k = 3, j = 1;  
    Node<uint32_t> *newhead = Delete(head, k);     
    Print(newhead);
    newhead = Delete(head, j);     
    Print(newhead); 
}

void TestPalindrome()
{ 
    vector<uint32_t> items = {2, 3, 4, 3, 2}; 
    Node<uint32_t>* head = Insert(items); 
    Print(head); 

    cout << IsPalindrome(head) << "\n";

    vector<uint32_t> items2 = {2, 3, 3, 2}; 
    Node<uint32_t>* head2 = Insert(items2); 
    Print(head2);

    cout << IsPalindrome(head2) << "\n";

    items2 = {2,3,4}; 
    head2 = Insert(items2); 
    cout << IsPalindrome(head2) << "\n"; 
}

// find the median of a circular linked list 
template <typename T> 
T FindMedianCircularList(Node<T>* random_node) 
{
    Node<T>* minNode = random_node, *curr = random_node->next;
    int cnt = 1; 

    // we have already iterated random_node as the first element, 
    // so we stop when we reach it. 
    while (curr != random_node) { 
        if (curr->data <= minNode->data) { 
            minNode = curr; 
        } 
        curr = curr->next; 
        ++cnt; 
    } 
   
    curr = minNode;
    T median;  
    int j = 0; 

    // for odd numbers, the median is n/2th number 
    // for even numbers, the median is (n/2) + (n/2)+1th element.
    while (j < cnt) { 
        if (j == ((cnt-1) >> 1)) { 
            median = (cnt & 1) ? curr->data: ((curr->data) + (curr->next->data))/2;
            break;
        } 
        ++j;     
        curr = curr->next; 
    }
        
    return median;           
}

// convert a linear linked list to a circular linked list 
template <typename T> 
void ConvertToCircular(Node<T>* head) 
{ 
    if (!head) 
        return; 

    Node<T>* curr = head; 

    while (curr->next) 
        curr = curr->next; 

    // connect tail to head
    curr->next = head; 
} 

void TestCircularList() 
{ 
    vector<uint32_t> items = {1,2,3,4,5}; 
    Node<uint32_t>* head = Insert(items); 
    Print(head); 
    ConvertToCircular(head);
    cout << FindMedianCircularList(head) << "\n"; 
    items = {100, 2, 12, 23, 46, 78, 96, 99}; 
    head = Insert(items); 
    Print(head); 
    ConvertToCircular(head);
    cout << FindMedianCircularList(head) << "\n"; 
}

void TestRemoveDuplicates() 
{ 
    vector<uint32_t> items = {1,1,2,3,3,4,5,5}; 
    Node<uint32_t>* head = Insert(items); 
    Print(head); 
   
    Node<uint32_t>* midpoint = Midpoint(head); 
    Print(midpoint); 
    
    RemoveDuplicates(head); 
    Print(head);  

    head = Reverse(head);
    Print(head);  

    midpoint = Midpoint(head); 
    Print(midpoint); 
}

int main()
{ 
    TestNodeFilter(); 
    TestDeleteNode(); 
    TestRemoveDuplicates(); 
    TestPalindrome(); 
    TestCircularList(); 
} 
