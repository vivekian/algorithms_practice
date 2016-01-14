#include <string> 
#include <iostream> 
using namespace std; 

// the principle to remember is that you pick 
// one char and permutate the other around it 
// you need to go through each char in the list 
void Permutate(string soFar, string rest) 
{ 
    if (rest == "") { 
        cout << soFar << endl; 
    } 
    else 
    { 
        for (int i = 0; i < rest.length(); ++i) 
        { 
            string next = soFar + rest[i]; 
            string remaining = rest.substr(0, i) + rest.substr(i+1); 
            Permutate(next, remaining); 
        } 
    } 
} 

int main() 
{ 
    string s = "abc"; 
    Permutate("", s); 
    return 0; 
} 
