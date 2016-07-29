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

template <typename T>
Node<T>* FilterLinkedList(const Node<T>* const head, bool (*func) (const T& data))
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

int main()
{ 
    TestNodeFilter(); 
} 
