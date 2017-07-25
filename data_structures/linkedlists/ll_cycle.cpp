#include <iostream> 
using namespace std; 

// does a cycle exist in a linked list
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	if (!head || !head->next) { 
		return false; 
	}
	
	auto slow = head; 
	auto fast = head->next->next; 
	
	while (slow && fast && (slow != fast)) { 
		slow = slow->next; 
		
		if (fast->next) { 
			fast = fast->next->next; 
		}
		else { 
			return false; 
		}
	}
	
	if (!slow || !fast) { 
		return false; 
	}
	
	return true; 
}

int main()
{ 
    return 0; 
}
