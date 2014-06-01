// Reverse a single linked list 

#include <iostream> 
using namespace std; 

typedef struct Node 
{ 	
	int item; 
	Node* next;
	
	Node(int Item): item(Item),next(NULL) {}   
} Node; 

void Insert(Node* Head, int Item) 
{ 
	Node* curr = Head; 

	while(curr->next) 
		curr = curr->next; 
	
	curr->next = new Node(Item); 
}

void Print(Node* Head) 
{ 
	Node* curr = Head; 
	
	while(curr) { 
		cout << curr->item << endl; 
		curr = curr->next;
	} 
}

void Reverse(Node** Head) 
{ 
	Node* prev = *Head; 
	Node* curr = prev->next; 

	if (!curr) 
		return; 

	// Important to make the first node's next ptr NULL. 
	prev->next = NULL; 

	while(curr) { 
		Node* tmp = curr->next; 
		curr->next = prev; 
		prev = curr; 
		curr = tmp; 
	} 
	
	*Head = prev;
}   

int main() 
{ 
	Node head(1); 

	Insert(&head, 2); 
	Insert(&head, 3); 
	Insert(&head, 4); 
	Insert(&head, 5); 
	Insert(&head, 6); 

	Print(&head); 

	Node* newhead = &head;
	Reverse(&newhead); 
	cout << endl; 
	Print(newhead); 
	
	return 0; 
} 
