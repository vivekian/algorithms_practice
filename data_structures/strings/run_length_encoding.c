#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// this function implements run length encoding.
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

int decode(const char* encoded, char* t) 
{ 
    while (*encoded) { 
        if (*encoded >= '0' && *encoded <= '9') { 
            
            int num = *encoded - '0'; 
            encoded++; 
            
            while(num) { 
                *t = *encoded; 
                num--; 
                t++; 
            } 

            encoded++; 
        }
        else { 
           return 1;  
        }
    } 

    return 0; 
}

void call_encode(const char* s) 
{
    if (!*s){ 
        printf("empty string\n");
        return;  
    } 
    
    char* t = (char*)malloc(strlen(s)); 
    encode(s, t); 
    printf("%s\n", t); 
    free(t);
}

void call_decode(const char* encoded) 
{ 
    char t[256]; 
    if (!decode(encoded, t)) { 
        printf("%s\n", t);
    } 

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

    call_decode("3a2b4c"); 
    return 0;
} 
