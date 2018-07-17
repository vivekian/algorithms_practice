#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

string next_code_id(string s) 
{
   if (std::next_permutation(s.begin(), s.end()))
           return s;
   else 
           return "No Successor"; 
}

int main()
{
    char s[51]; 

    while (scanf("%s", s) != EOF) { 
        string str(s); 
        
        if (str == "#") 
            break; 

        printf("%s\n", next_code_id(str).c_str()); 
    }

    return 0;  
}
