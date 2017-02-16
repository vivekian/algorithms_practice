#include <iostream> 
using namespace std; 

int count_bits(unsigned int num) 
{ 
    int cnt = 0; 

    while (num) { 
        if (num & 1) { 
            ++cnt; 
        } 
        num >>= 1; 
    } 

    return cnt; 
} 

int main()
{ 
    cout << count_bits(23) << endl; 
    return 0; 
} 
