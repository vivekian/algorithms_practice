
#include <iostream> 
#include <cstdlib> 
#include <cmath> 
using namespace std; 

typedef struct Node 
{ 
	int item;
	Node* left; 
	Node* right; 
	Node* parent; 
	
	Node(int Item): item(Item), left(NULL), right(NULL), parent(NULL)  {} 
} Node; 

Node* Insert(Node* Root, int Item) 
{ 
	if (Root == NULL)
		return new Node(Item); 
	
	if (Item <= Root->item) 
	{ 
		Root->left = Insert(Root->left, Item); 
		Root->left->parent = Root; 
	} 
	else { 
		Root->right = Insert(Root->right, Item); 
		Root->right->parent = Root;
	} 
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

bool ValidateBST(Node* Root) 
{ 
	if (Root == NULL) 
		return true; 

	bool leftValid = false; 
	bool rightValid = false; 	

	if (Root->left)
	{  
		if (Root->left->item <= Root->item) 
		{ 
			leftValid = ValidateBST(Root->left); 
		} 
	} 
	else 
	{ 
		leftValid = true; 
	} 

	if (Root->right) 
	{ 
		if (Root->right->item > Root->item) 
		{ 
			rightValid = ValidateBST(Root->right); 
		}
	} 
	else 
	{ 
		rightValid = true;
	} 

	return leftValid && rightValid; 
}  

int FindMin(Node* Root) 
{ 
	if (Root == NULL) 
		return -1; 

	Node* t = Root; 

	while(t->left) 
		t = t->left; 

	return t->item; 
} 

int FindMax(Node* Root) 
{ 
	if (Root == NULL) 
		return -1; 
	
	Node* t = Root; 
	
	while(t->right) 
		t = t->right; 
	
	return t->item; 
} 

int GetHeight(Node* Root) 
{
	if (Root == NULL) 
		return 0; 
	
	cout << Root->item << endl; 

	int lh = GetHeight(Root->left);
	if (lh == -1) 
		return -1; 	
	int rh = GetHeight(Root->right); 
	if (rh == -1) 
		return -1; 

	if (abs(lh - rh) > 1) 
		return -1; 
	else 
		return max(lh, rh) + 1; 
} 

// If leaf left child - parent 
// If leaf right child
//		first parent's parent which is a left child 
// If a node with children  
//		left most child of a right subtree 
 
int GetNext(Node* T, int Item)
{
	if (T == NULL) 
		return -1; 
	
	if(T->item == Item) 
	{ 
		if(!T->left && !T->right) 
		{ 
			// if leaf is a left child 
			if (T->parent->left == T) 
			{  
				return T->parent->item; 
			} 
			// if leaf is a right child 
			else 
			{ 
				Node* next = T->parent; 
				while(next && next->parent && (next != next->parent->left)) 
					next = next->parent; 
				
				return (next->parent ? next->parent->item: -1); 
			} 
		} 
		else 
		{ 
			return FindMin(T->right); 
		}
	} 
	else if (Item < T->item) 
	{ 
		return GetNext(T->left, Item); 
	} 
	else 
	{ 
		return GetNext(T->right, Item); 
	}  
} 

bool DoesPathSumExist(Node* Root, int Sum, const int PathSum) 
{ 
	if (Root == NULL)
		return false; 

	if (!Root->left && !Root->right) 
	{ 
		Sum += Root->item; 
		return (Sum == PathSum); 
	} 

	return DoesPathSumExist(Root->left, Sum + Root->item, PathSum) || 
		   DoesPathSumExist(Root->right, Sum + Root->item, PathSum); 
} 


	
bool IsBalanced(Node* Root) 
{
	return (GetHeight(Root) != -1); 
}  

int main()
{ 
	Node* root = NULL;  
	root = Insert(root, 10);   
	Insert(root, 8);  
	Insert(root, 12);  
	Insert(root, 6);  
	Insert(root, 11);  
	Insert(root, 13);  
	Insert(root, 9);  

	Print(root); 

	cout << (Search(root, 11) ? "Found" : "Not Found") << endl; 	
	cout << (Search(root, 23) ? "Found" : "Not Found") << endl; 	
	cout << IsBalanced(root) << endl; 
	
	cout << DoesPathSumExist(root, 0, 100) << endl; 
	cout << DoesPathSumExist(root, 0, 24) << endl; 
	cout << DoesPathSumExist(root, 0, 35) << endl; 

	cout << ValidateBST(root) << endl; 
	cout << FindMin(root) << endl; 
	cout << FindMax(root) << endl;
	cout << "11 " << GetNext(root, 11) << endl;  
	cout << "9 " << GetNext(root, 9) << endl;  
	cout << "13 " << GetNext(root, 13) << endl;  
	cout << "8 " << GetNext(root, 8) << endl;  
	cout << "10 " << GetNext(root, 10) << endl;  
	return 0; 
} 
