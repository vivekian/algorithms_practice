#include <stdio.h> 
#include <stdlib.h> 

int mystrstr(const char* str, const char* sub) 
{ 
	if (!str || !sub) 
		return -1; 

	const char* s = str; 
	const char* t = sub; 

	while(*s) { 
		while((*s == *t)) { 
			s++; 
			t++;
			printf("%c\n", *t);  
		}  
	
		if (*t == '\0') { 
			return (s - str - (t - sub)); 
		}
		
		if (t != sub) { 
			t = sub;
			continue;  
		} 
		
		s++; 
	} 

	return -1; 
} 

int main()
{
    printf("%d\n",mystrstr("helloworld", "low"));  	 
    printf("%d\n",mystrstr("helloworld", "lowa"));  	 
    printf("%d\n",mystrstr("helloworld", "h"));  	 
    printf("%d\n",mystrstr("helloworld", "d"));  	 
	return 0; 
} 
