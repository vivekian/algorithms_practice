// A string consists of ‘0’, ‘1’ and '?'. The question mark can be either '0' or '1'. Find all possible combinations for a string.

// "01?" -> 011, 010
// "11?" -> 110, 111 
// "1?0?" -> 1000, 1001, 1100, 1101
// "??" -> 00, 01, 10, 11

#include <iostream> 
#include <string> 

using namespace std; 

void solve_permutation(string sofar, string rest) 
{ 
    while (!rest.empty()) { 
        if (rest[0] == '?') {
            solve_permutation(sofar+'0', rest.substr(1)); 
            solve_permutation(sofar+'1', rest.substr(1));

            // this is the critical return. when we recursively call, then 
            // the recursive call takes care of the rest of the string. so 
            // when we are at this point, we should just return. 
            return; 
        }
        else { 
            sofar = sofar + rest[0]; 
        }
        rest.erase(0,1); 
    }

    cout << sofar << endl; 
}

void permutate(string input) 
{ 
    solve_permutation("", input);  
} 

int main() 
{
    permutate(string("10??"));
    cout << endl; 

    permutate(string("10??1?"));
    return 0;
} 
