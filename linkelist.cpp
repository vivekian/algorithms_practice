// Reverse a single linked list 

#include <iostream> 
using namespace std; 

typedef struct Node 
{	
	int item; 
	Node* next;
	
	Node(int Item): item(Item),next(NULL) {}   
} Node; 


namespace LinkedList 
{ 
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
	
		void Delete(Node** Head, int Item) 
		{ 
			Node* prev = *Head; 
			Node* curr = prev->next; 
		
			if(!prev) 
				return; 

			if(prev->item == Item) { 
				*Head = curr; 
				delete prev; 
				return; 
			} 

			while (curr) { 
				if (curr->item == Item) { 
					prev->next = curr->next; 
					delete curr; 
					break; 
				} 
				prev = curr; 
				curr = curr->next; 
			} 
		} 	

		Node* Merge(Node* HeadA, Node* HeadB) 
		{ 
			if(!HeadA && !HeadB) 
				return NULL; 
			
			if (!HeadA) 
				return HeadB; 
			
			if (!HeadB) 	
				return HeadA; 

			Node* a = HeadA; 
			Node* b = HeadB; 
			Node* newHead = NULL; 			

			if (a->item > b->item) { 
				newHead = b; 
				b = b->next; 
			} 
			else { 
				newHead = a; 
				a = a->next; 
			}

			Node* tmp = newHead; 
 
			while(a && b) { 
				if (a->item > b->item) { 
					tmp->next = b;
					b = b->next;  
				}
				else { 
					tmp->next = a;
					a = a->next; 
				}
				tmp = tmp->next;  
			} 

			//Merge if list 1 is iterated, and list 2 remains.  
			if(a)  
				tmp->next = a; 

			if(b)  
				tmp->next = b; 
	 
			return newHead; 
		} 	

		// The basic idea is to find the median, then reverse the rest of the list
		// Next start merging it with the original list. 

		void ZipList(Node* Head) 
		{ 
			Node* curr = Head; 
			Node* median = Head; 
			Node* prev = median; 

			while(curr && curr->next) { 
				curr = curr->next->next;
				prev = median;  
				median = median->next; 
			} 

			prev->next = NULL;
			LinkedList::Reverse(&median); 
			 
			Node* b = median; 
			Node* a = Head;
			Node* anext = a->next; 
			Node* bnext = b->next; 
			
			while(a) { 
				a->next = b; 
				b->next = anext; 
				b = bnext; 
				a = anext; 
				if(a) 
					anext = a->next; 
				if(b) 
					bnext = b->next; 
			}  
		} 
} 		

int main() 
{ 
	Node head(1); 

	LinkedList::Insert(&head, 2); 
	LinkedList::Insert(&head, 3); 
	LinkedList::Insert(&head, 4); 
	LinkedList::Insert(&head, 5); 
	LinkedList::Insert(&head, 6); 

	LinkedList::Print(&head); 

	Node* newhead = &head;
	LinkedList::Reverse(&newhead); 
	
	cout << endl; 
	LinkedList::Print(newhead); 
	
	LinkedList::Delete(&newhead, 6); 
	cout << endl; 
	LinkedList::Print(newhead); 

	Node h1(1); 
	LinkedList::Insert(&h1, 3); 
	LinkedList::Insert(&h1, 5); 
	LinkedList::Insert(&h1, 7); 
	Node h2(2);
	LinkedList::Insert(&h2, 4); 
	LinkedList::Insert(&h2, 6); 
	LinkedList::Insert(&h2, 8); 

	Node* h3 = LinkedList::Merge(&h1, &h2);  
	cout << endl; 
	LinkedList::Print(h3); 

	LinkedList::ZipList(h3); 
	cout << endl; 
	LinkedList::Print(h3); 

	return 0; 
} 
