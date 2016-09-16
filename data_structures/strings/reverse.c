#include <stdio.h> 

void reverse(char* s) 
{ 
	char* t = s; 

	while(*t)  
		t++;

	t--; 

	while(s < t) 
	{ 
		char tmp = *s; 
		*s = *t; 
		*t = tmp; 
		s++;  
		t--; 
	} 
} 

int main() 
{ 
	char s[] = "hello world"; 
	reverse(s); 
	printf("%s\n", s); 
	return 0; 
} 
