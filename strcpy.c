// strcpy implementation  

#include <stdio.h> 

void mystrcpy(char* s, char* t) 
{ 
	while ((*t = *s) != '\0') 
	{ 
		s++; 
		t++; 
	} 
} 

int main()
{ 
	char x[] = "now is the time"; 
	char y[100]; 
	
	mystrcpy(x, y); 
	printf("%s\n", y); 
	return 0; 
} 
