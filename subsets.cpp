#include <iostream> 
#include <string> 

using namespace std;

// the principle to remember is to decide if a 
// char is in or out and recursively call both 
// functions. 
void Subsets(string soFar, string rest) 
{ 
	if (rest == "") 
	{ 
		cout << soFar << endl; 
	} 
	else 
	{ 
		Subsets(soFar + rest[0], rest.substr(1)); 
		Subsets(soFar, rest.substr(1)); 
	} 
} 

void ListSubsets(string s) 
{ 
	Subsets("", s); 
} 

int main() 
{ 
	string s = "abcd"; 
	ListSubsets(s); 
	return 0; 
} 
