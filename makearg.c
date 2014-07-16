#include <stdio.h> 
#include <string.h>
#include <stdlib.h>  

int makeargv(const char* s, char*** argv) 
{ 
    char* t = malloc(strlen(s));
    memcpy(t, s, strlen(s));

    printf("%s\n", t); 
    
    char* tmp = strtok(t, " "); 
    printf("%s\n", tmp);  
    int idx = 0; 
    
    char** targ = *argv; 

    while(tmp != NULL) 
    {
        printf("%lu\n", strlen(tmp));  
        targ[idx] = malloc(strlen(tmp)); 
//        memcpy((*argv)[idx], tmp, strlen(tmp)); 
        idx++; 
        tmp = strtok(NULL, " "); 
    } 
     
    return idx; 
} 

int main() 
{ 
    const char* str = "hello world this is nvidia"; 
    char** argv; 

    int numtokens = makeargv(str, &argv); 

    int i = 0; 
/*    for (i = 0; i < numtokens; i++) 
        printf("%s\n", argv[i]); 
*/ 
    return 0; 
} 
