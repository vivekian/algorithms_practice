#include <iostream> 
#include <string> 

using namespace std;

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
