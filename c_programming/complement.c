#include <stdio.h> 

int comp(int num) 
{ 
    int res = 0; 
    int cnt = 0; 

    while (num) { 
        if (!(num & 1)) { 
            res = res | (1 << cnt); 
        } 
        ++cnt; 
        num = num >> 1; 
    }
        
    return res;  
} 

int main() 
{ 
    printf("%d\n", comp(5)); 
    printf("%d\n", comp(2)); 
    return 0; 
} 
