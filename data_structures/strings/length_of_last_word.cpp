// solution to problem 59 of LeetCode 

#include <vector> 
#include <string> 
#include <iostream> 

using namespace std; 

int lengthOfLastWord(string s) {
    auto len = s.length(); 

    if (!len) { 
        return 0; 
    } 

    vector<bool> ischar(len, false); 
    int i=0; 

    for(i=0; i<len; ++i) { 
        if (isalpha(s[i])) { 
            ischar[i] = true; 
        }
    } 
    
    --i; 

    while (i>=0 && !ischar[i]) { 
        --i; 
    }
    
    int last=i; 

    while (i>=0 && ischar[i]) { 
        --i;
    }

    return (last - i); 
}

int main() 
{
    cout << lengthOfLastWord("Hello World") << endl;  
    cout << lengthOfLastWord("Hello World ") << endl;  
    cout << lengthOfLastWord("") << endl;  
    cout << lengthOfLastWord("a") << endl;  
    cout << lengthOfLastWord("ab") << endl;  
    cout << lengthOfLastWord(" ") << endl;  
    cout << lengthOfLastWord("Hello World                     ") << endl;  
    return 0; 
} 
