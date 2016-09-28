#include <iostream> 
using namespace std; 

uint32_t reverseBits(uint32_t n)
{ 
    if (!n) { 
        return 0; 
    } 

    uint32_t left = 0x80000000; 
    uint32_t right = 0x1; 

    while (left > right) { 
        bool isleft = n & left; 
        bool isright = n & right; 

        if (isleft && !isright) { 
            n = n | right; // switch on the right side bit 
            n = n & ~left; // switch off the left side bit 
        } 
        
        if (!isleft && isright) { 
            n = n & ~right; 
            n = n | left; 
        } 

        left = left >> 1; 
        right = right << 1; 
    } 

    return n; 
}

int main()
{ 
    cout << hex << reverseBits(0xF) << endl; 
    cout << hex << reverseBits(0x80000000) << endl; 
    return 0; 
} 
