#include <cmath> 
#include <string> 
#include <iostream> 

using namespace std; 

int fact(int i) { 
    int sum = i; 

    while (i > 1) { 
        sum *= i-1; 
        --i; 
    } 

    return sum; 
} 

namespace { 
    int factarray [] = { 
        0,
        1, 
        2, 
        6, 
        24, 
        fact(5), 
        fact(6), 
        fact(7), 
        fact(8), 
        fact(9)
    }; 
}  
        
string getPermutation(int n, int k) {

    string input = ""; 
    string res = ""; 
    
    for (int i=1; i<=n; ++i) { 
        input += '0' + i; 
    }

    if (k == 0) { 
        return res; 
    } 

    while (n) { 
       int idx = ceil(k / (static_cast<double>(factarray[n])/n)); 
       res += input[idx-1]; 
       input.erase(idx-1, 1); 
       k = k - ((factarray[n]/n) * (idx-1)); 
       --n; 
   } 

    return res; 
}

int main()
{
   cout << getPermutation(3, 6) << endl;  
   cout << getPermutation(8, 66) << endl;  
   cout << getPermutation(8, 0) << endl;  
   cout << getPermutation(2, 2) << endl;  
   cout << getPermutation(1, 1) << endl;  
   cout << getPermutation(9, 101134) << endl;  
   cout << getPermutation(4, 20) << endl;  
} 
