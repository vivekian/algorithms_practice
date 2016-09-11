#include <iostream> 
#include <queue> 
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

void write_bst(ostream& os, const dll_node* root) 
{ 
    if (!root) 
        return; 

    queue<const dll_node*> curr_level, next_level;

    curr_level.push(root); 

    while (!curr_level.empty()) { 
        auto node = curr_level.front(); 
        curr_level.pop(); 

        os << node->value << " "; 

        if (node->prev) { 
           next_level.push(node->prev); 
        } 
        if (node->next) {
           next_level.push(node->next);  
        }

        if (curr_level.empty()) { 
            swap(curr_level, next_level); 
            os << endl; 
        }
    } 
        
} 

void write_dll(ostream& os, const dll_node* head) 
{ 
    auto tmp = head; 
    
    while (tmp) { 
        os << tmp->value;  
        if (tmp->next) { 
           os << "->"; 
        }  
        tmp = tmp->next; 
    } 

    os << endl; 
}

// the idea is to find the middle node, and then recursively 
// find the right and left children which are aliased by next 
// and prev nodes. 
//
// its important to take note of the sentinal conditions, if either
// of start or end is null, then return null. 
//
// once a node is removed from the dll as the subroot, then its next and 
// prev nodes pointers poiting to it are set to null. 
dll_node* convert_to_bst_helper(dll_node* start, dll_node* end) 
{ 
    if (start == end) { 
        return start; 
    }
    if (!start || !end) { 
       return nullptr; 
    }

    auto curr = start; 
    auto mid = curr; 

    while (curr != end && curr->next->next) { 
        curr = curr->next->next; 
        mid = mid->next; 
    } 

    if (mid->prev) 
        mid->prev->next = nullptr; 
    if (mid->next) 
        mid->next->prev = nullptr; 

    mid->next = convert_to_bst_helper(mid->next, end); 
    mid->prev = convert_to_bst_helper(start, mid->prev); 

    return mid; 
} 

dll_node* convert_to_bst(dll_node* head) 
{
    dll_node* curr = head; 

    while (curr->next) { 
        curr = curr->next; 
    } 
    
    return convert_to_bst_helper(head, curr); 
}

int main() 
{ 
    dll_node* head = make_dll(vector<int>({1,2,3,4,5,6,7,8,9,10,11,12,13,14}));
    write_dll(cout, head);  
    dll_node* root = convert_to_bst(head); 
    write_bst(cout, root); 
    return 0; 
} 
