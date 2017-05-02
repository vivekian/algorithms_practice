// solve problem 482 of leet code. 
// non empty string has to be split into groups of size k except for the 
// first group which can be smaller than size k. 

#include <algorithm> 
#include <string> 
#include <cctype> 
#include <iostream> 

using namespace std; 

string licenseKeyFormatting(string S, int K)
{ 
    const auto len = S.length(); 
    string res;  
    int i = len-1; 
    int j = 0; 

    while (i>=0) {

        if (isalpha(S[i]) || isdigit(S[i])) { 
            if (j == K) { 
                res.push_back('-'); 
                j = 0; 
            }

            res.push_back(toupper(S[i])); 
            ++j; 
        }
        
        --i;
    }

    reverse(res.begin(), res.end()); 
    return res; 
} 

int main() 
{ 
    cout << licenseKeyFormatting("4-azbd-3Fg", 4) << endl; 
    cout << licenseKeyFormatting("2-4A0r7-4k", 4) << endl; 
    cout << licenseKeyFormatting("AB", 1) << endl; 
    cout << licenseKeyFormatting("--2----A-----B----", 1) << endl; 
    return 0; 
} 
