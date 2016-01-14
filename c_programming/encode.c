
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encode(const char* s, char* t)
{ 
    const char* prev = s;
    int cnt = 1;
    s++;

    while(*prev) {
        if (*s == *prev) {
            cnt++;
        }
        else {
            *t = '0' + cnt;
            t++;
            *t = *prev;
            t++;
            cnt = 1;
        }

        prev++;
        s++;
    } 
} 

void call_encode(const char* s) 
{
    if (!(*s)){ 
        printf("empty string\n");
        return;  
    } 
    char* t = (char*)malloc(strlen(s)); 
    encode(s, t); 
    printf("%s\n", t); 
    free(t);
} 

int main()
{
    const char* s = "aaaabbccdd"; 
    call_encode(s);
    
    call_encode("aabbccdd");  
    call_encode("abcd");  
    call_encode("aaaa");  
    call_encode("a");  
    call_encode("\0");  

    return 0;
} 
