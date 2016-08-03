// merge two sorted linked lists. 
//
//  restrictions: 
//      don't use extra space. reuse nodes.     
//
//  edge cases: 
//      one list is empty, other is not. 
//      both lists are empty 

#include <cassert> 
#include <iostream> 
#include <memory> 
#include <vector> 

using namespace std; 

struct Node { 
    int data; 
    shared_ptr<Node> next; 

    Node(int d): data(d), next(nullptr) {} 
};

// assume for this case that numbers are added in sorted order 
void Insert(shared_ptr<Node>& head, int num) 
{ 
    assert(head); 
    auto curr = head; 

    while (curr->next.get()) { 
        curr = curr->next; 
    }

    curr->next = make_shared<Node>(num); 
}

void Print(shared_ptr<Node>& head) 
{ 
    assert(head); 
    auto curr = head; 

    while (curr.get()) { 
        cout << curr->data; 
        curr = curr->next; 
        if (curr.get()) 
            cout << "->";
        else 
            cout << endl; 
    }

}

shared_ptr<Node> merge(shared_ptr<Node>& heada, shared_ptr<Node>& headb)
{ 
    if (!heada.get() && !headb.get()) 
        return nullptr; 

    if (!heada) 
        return headb; 

    if (!headb) 
        return heada; 

    auto curra = heada; 
    auto currb = headb; 

    shared_ptr<Node> head;

    // this first check is a duplicate check from the while loop
    // but critical to make sure that head is recorded. 
    if(curra->data <= currb->data) { 
        head = curra; 
        curra = curra->next; 
    }
    else { 
        head = currb; 
        currb = currb->next;
    }

    auto curr = head;  

    while(curra.get() && currb.get()) { 
        if (curra->data <= currb->data) { 
            curr->next = curra; 
            curra = curra->next; 
        }
        else { 
            curr->next = currb; 
            currb = currb->next; 
        }
        curr = curr->next; 
    } 

    if (!curra.get()) 
        curr->next = currb; 
    if (!currb.get()) 
        curr->next = curra; 

    return head; 
}

shared_ptr<Node> make_list(const vector<int>& a) 
{ 
    shared_ptr<Node> head = make_shared<Node>(a.at(0));

    for (int i=1; i<a.size(); ++i) 
        Insert(head, a.at(i)); 

    return head; 
}

int main() 
{
    shared_ptr<Node> head  = make_list({1,3,5,7,9});  
    shared_ptr<Node> head2 = make_list({2,4,6,8,10});  
    
    auto mergedhead = merge(head, head2); 
    Print(mergedhead); 

    shared_ptr<Node> heada  = make_list({0});  
    shared_ptr<Node> headb = make_list({2,4,6,8,10});  
    
    auto mergedhead2 = merge(heada, headb); 
    Print(mergedhead2); 

    return 0; 
}
