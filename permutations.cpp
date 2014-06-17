#include <string> 
#include <iostream> 
using namespace std; 

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
