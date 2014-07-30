#include <stdio.h> 
#include <stdlib.h> 

int palindrome(const char* s) 
{
	if (!s) 
		return 0; 
 
	const char* t = s; 

	while(*t) { 
		t++; 
	}  
 	t--; 
	
	while(s <= t) { 
		if (*s != *t) { 
			return 0; 
		} 
		s++; 
		t--; 
	} 
	
	return 1; 
} 

int main() 
{ 
	printf("%d\n", palindrome("abba")); 
	printf("%d\n", palindrome("aba")); 
	printf("%d\n", palindrome("abad")); 
	printf("%d\n", palindrome("a")); 
	return 0; 
} 

