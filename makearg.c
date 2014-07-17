#include <stdio.h> 
#include <string.h>
#include <stdlib.h>  

int makeargv(const char* s, char*** argv) 
{ 
    char* t = malloc(strlen(s));
    memcpy(t, s, strlen(s));
    
    /* count the number of tokens */ 
	char* tmp = strtok(t, " "); 
    int idx = 0; 

    while(tmp != NULL) 
    {
        idx++; 
        tmp = strtok(NULL, " "); 
    } 

	/* allocate an array of pointers */ 
	*argv = malloc((idx+1) * (sizeof(char*))); 

	/* t was destroyed when strtok was called the first time
	   this copies it again */ 
	strcpy(t, s); 
	
	/* we split the string again and mark the pointers
	   in the array we allocated. see how we don't 
	   allocate memory again  */ 
	**argv = strtok(t, " "); 
 
	int i = 1;
	for ( ; i < idx; i++) 
		*((*argv) + i) = strtok(NULL, " ");  
    		
	/* this is to mark that we are done */ 
	*((*argv) + idx) = NULL; 	
	return idx; 
} 

int main() 
{ 
    const char* str = "hello world this is nvidia"; 
    char** argv; 

    int numtokens = makeargv(str, &argv); 

    int i = 0; 
    for (i = 0; i < numtokens; i++) 
        printf("%s\n", argv[i]); 
 
    return 0; 
} 
