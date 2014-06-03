
#include <iostream> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 

typedef struct Node 
{ 
	int item;
	Node* left; 
	Node* right; 
	
	Node(int Item): item(Item), left(NULL), right(NULL) {} 
} Node; 

Node* Insert(Node* Root, int Item) 
{ 
	if (Root == NULL)
		return new Node(Item); 
	
	if (Item <= Root->item) 
		Root->left = Insert(Root->left, Item); 
	else 
		Root->right = Insert(Root->right, Item); 

	return Root; 
}  

int Search(Node* Root, int Item) 
{ 
	if (Root == NULL) 
		return 0; 

	if (Root->item == Item) 
		return 1; 
	else if (Item <= Root->item) 
		return Search(Root->left, Item); 
	else 
		return Search(Root->right, Item); 
} 

void Print(Node* Root) 
{ 
	if (Root == NULL) 
		return; 
	
	Print(Root->left); 
	cout << Root->item << endl; 
	Print(Root->right); 
} 

int GetHeight(Node* Root) 
{
	if (Root == NULL) 
		return 0; 
	
	cout << Root->item << endl; 

	int lh = GetHeight(Root->left);
	if (lh == -1) 
		return -1; 	
 	cout << "yes" <<endl; 	
	int rh = GetHeight(Root->right); 
	if (rh == -1) 
		return -1; 

	if (abs(lh - rh) > 1) 
		return -1; 
	else 
		return max(lh, rh) + 1; 
} 


bool IsBalanced(Node* Root) 
{
	return (GetHeight(Root) != -1); 
}  

int main()
{ 
	Node root(10); 
	Insert(&root, 8);  
	Insert(&root, 12);  
	Insert(&root, 6);  
	Insert(&root, 11);  
	Insert(&root, 13);  
	Insert(&root, 9);  

	Print(&root); 

	cout << (Search(&root, 11) ? "Found" : "Not Found") << endl; 	
	cout << (Search(&root, 23) ? "Found" : "Not Found") << endl; 	
	cout << IsBalanced(&root) << endl; 

	Node* root2 = Insert(root2, 1); 
	Insert(root2, 2); 
	Insert(root2, 3); 
	
	cout << IsBalanced(root2) << endl; 

	return 0; 
} 
