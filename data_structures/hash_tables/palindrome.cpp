// write a program to test if a string is a palindrome or not. 
// we assume all chars are lower case and use a vector of 26 chars to store frequency count. 
// if length is even, then all chars should be even count. 
// if length is odd, then only one char can be odd count. 

#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

bool IsPalindrome(const string& s) 
{
    vector<int> freq(26); 
    for_each(s.begin(), s.end(), [&freq](const char& c) {++freq[c-'a'];});
   
    int odd_count = 0; 

    for (const auto& f: freq) { 
       if (f & 1) { 
          ++odd_count;
       }
       if (odd_count > 1) { 
           break; 
       } 
    }

    return (odd_count <= 1); 
}

void RunTests() 
{ 
    cout << IsPalindrome("edified") << endl; 
    cout << IsPalindrome("deed") << endl; 
    cout << IsPalindrome("test") << endl; 
}

int main() 
{ 
    RunTests(); 
    return 0; 
} 
