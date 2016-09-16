#include <cstdint>
#include <limits>
#include <iostream>
#include <stdio.h> 

using namespace std; 

void printbinary(uint32_t num) 
{ 
    for (int i=0; i<32; ++i) { 
        printf("%c", num&1 ? '1' : '0'); 
        num = num >> 1; 
    }

    printf("\n"); 
}

void printbinary(int32_t num) 
{ 
    for (int i=0; i<32; ++i) { 
        printf("%c", num&1 ? '1' : '0'); 
        num = num >> 1; 
    }

    printf("\n"); 
}

int main() 
{ 
    printf("unsigned max: %u\n", numeric_limits<unsigned>::max()); 
    printbinary(numeric_limits<unsigned>::max()); 

    // this results in an overflow. addition results in 0. 
    uint32_t x = numeric_limits<unsigned>::max() + 1; 
    printf("unsigned max overflow by 1: %u \n", x); 
    printbinary(x);

    // to avoid this store result in uint64_t 
    unsigned long xl = static_cast<uint64_t>(numeric_limits<unsigned>::max()) + 1;
    printf("avoid overflow and store in unsigned long%lu\n", xl); 
    cout << sizeof(xl) << endl; 

    int32_t y = numeric_limits<int>::max(); 
    printf("int32 max: %d\n", y); 
    printbinary(y); 
    int32_t yof = numeric_limits<int>::max() + 1; 
    printf("int32 max overflow: %d\n", yof); 
        
    y = numeric_limits<int>::min(); 
    printf("%d\n", y); 
    printbinary(y); 

    return 0; 
}
