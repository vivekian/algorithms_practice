#include <iostream> 
using namespace std; 

struct node {
    int val; 
    node* next; 

    node(int v): val(v) {this->next = nullptr;}
};

node* swap_nodes(node* head) 
{
   if (!head) 
      return nullptr; 

   // dummy node to point to head. 
   node zero(0);
   zero.next = head; 
   
   node* first = &zero; 
   node* second = head;  
   node* third = head->next; 

   while (second && third) { 
       first->next = third; 
       second->next = third->next; 
       third->next = second; 

       if (second->next) { 
            first = second; 
            second = second->next; 
            third = second->next; 
       }
       else { 
           break; 
       } 
   }

   return zero.next; 
}

void write(node* head) 
{
   while (head) { 
       cout << head->val << " "; 
       head = head->next; 
   } 

   cout << endl; 
}

int main()
{
    node n1(1), n2(2), n3(3), n4(4), n5(5); 
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5; 
    write(&n1); 
    auto s = swap_nodes(&n1); 
    write(s); 
    return 0;  
}
