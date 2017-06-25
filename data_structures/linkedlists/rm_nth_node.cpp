#include <iostream> 

using namespace std; 

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	if (!head) 
		return nullptr; 

	auto curr = head; 
	auto follow = head; 

	while(n && curr->next) { 
		--n; 
		curr = curr->next; 
	} 

    // this is a key check to make sure that if the first node
    // itself has to be removed. 
	if (n) { 
		head = follow->next; 
		return head; 
	} 

	while (curr->next) { 
		follow = follow->next; 
		curr = curr->next; 
	} 

	auto tmp = follow->next; 
	follow->next = follow->next->next; 

	return head; 
}

int main() 
{ 
	ListNode head(1); 
	
	if (nullptr == removeNthFromEnd(&head, 1)) { 
		cout << "pass" << endl; 
	} 

	return 0; 
} 

