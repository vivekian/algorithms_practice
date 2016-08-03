#include <iostream> 
#include <string> 

using namespace std; 

typedef struct node 
{ 
	string word; 
	int count; 
	node* right; 
	node* left; 
} Node; 

Node* Insert(Node* Root, const string& Word) 
{ 
	if (Root == NULL) 
	{ 
		Root = new Node(); 
		Root->word = Word; 
		Root->right = NULL; 
		Root->left = NULL;
		Root->count = 1;  
		return Root;  
	} 

	int cmp = (Root->word).compare(Word); 

	if (!cmp) 
	{ 
		Root->count++; 
	} 
	else if (cmp < 0) 
	{ 
		Root->right = Insert(Root->right, Word); 
	} 
	else 
	{ 
		Root->left = Insert(Root->left, Word); 
	} 
	
	return Root; 
} 

void PrintTree(Node* Root) 
{ 
	if(Root->left) 
	{ 
		PrintTree(Root->left); 
	} 

	cout << Root->word << " " << Root->count << endl; 
	
	if(Root->right) 
	{ 
		PrintTree(Root->right); 
	} 
} 

int main() 
{ 
	Node* root = NULL; 
	string sentence = "now is for all good men to come to the aid of the party"; 
	string delim = " "; 
	string word = ""; 

	size_t pos = sentence.find(delim); 

	while (pos != string::npos) 
	{ 
		word = sentence.substr(0, pos); 
		root = Insert(root, word);  
		sentence.erase(0, pos + 1);
		pos = sentence.find(delim);  
	}

	root = Insert(root, word); 
	PrintTree(root); 
	return 0; 
} 
