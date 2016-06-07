#include <iostream> 
#include <string> 

using namespace std; 

bool permutate(string soFar, string rest, string findit) 
{ 
	if (rest == "") { 
		cout << soFar << endl;
		if (soFar == findit) 
		{ 
			cout << "Found it!!" << endl; 
			return true; 
		}  
		return false; 
	} 
	else { 
		for (int i = 0; i < rest.length(); ++i) { 
			string next = soFar + rest[i]; 
			string remain = rest.substr(0,i) + rest.substr(i+1); 
			if (permutate(next, remain, findit)) return true;  
		} 
	}

	return false; 
} 

int main()
{ 
	string s = "abcd"; 
	permutate("", s, "abcdef"); 
	return 0; 
} 
