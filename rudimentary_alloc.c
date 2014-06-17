// Simple allocator from K&R (5.5) 
// Allocates and frees memory in a LIFO approach 

#include <stdio.h> 
#define ALLOCSIZE 1000 

static char allocbuff[ALLOCSIZE]; 
static char* allocp = allocbuff; 

char* alloc(int n) 
{ 
	if (allocp + n > allocbuff + ALLOCSIZE) 
		return 0; 

	allocp += n; 
	return allocp - n;
} 

void afree(char *p) 
{ 
	if (p && ((p >= allocbuff) && (p <= allocbuff + ALLOCSIZE)))
		allocp = p; 
} 

int main() 
{ 
	char* x = alloc(50); 
	char* y = alloc(200); 
	char* z = alloc(750); 

	if ((z - x) == 250) 
		printf("Success\n"); 
	else 
		printf("Failure\n"); 

	afree(z); 
	afree(y); 
	afree(x); 

	if (allocp == allocbuff) 
		printf("Success \n"); 
	else 
		printf("Failure \n"); 

	return 0; 
}  
