#include <iostream> 
#include <vector> 

using namespace std; 

struct dll_node { 
    int value; 
    dll_node* prev; 
    dll_node* next;

    dll_node(int val): value(val),prev(nullptr), next(nullptr){} 
}; 

dll_node* make_dll(const vector<int>& items) 
{ 
    dll_node* head = new dll_node(items[0]); 
    dll_node* tmp = head; 

    for (int i=1; i < items.size(); ++i) { 
       tmp->next = new dll_node(items[i]);  
       tmp->next->prev = tmp; 
       tmp = tmp->next; 
    }
    
    tmp->next = nullptr;  
    return head; 
}

void write_dll(ostream& os, const dll_node* head) 
{ 
    const dll_node* tmp = head; 
    
    while (tmp) { 
        os << tmp->value;  
        if (tmp->next) { 
           os << "->"; 
        }  
        tmp = tmp->next; 
    } 

    os << endl; 
}

int main() 
{ 
    dll_node* head = make_dll(vector<int>({1,2,3,4,5,6,7,8,9}));
    write_dll(cout, head);  

    return 0; 
} 
