#include <stdio.h> 

void swap(char* s, char* t) 
{ 
	char tmp = *s;
	*s = *t; 
	*t = tmp; 
} 

// the key here is to have a terminator so the function is 
// generic in nature. 
void reverse_string(char* input_string, const char terminator) 
{
	char* start = input_string;  
	char* last = input_string;  

	while(*last != terminator)
		last++;  

    last--;  

	while(start <= last) 
	{ 
		swap(start, last); 
		start++; 
		last--; 
	} 	
}

char* reverse_sentence(char* sentence) 
{ 
	char* start = sentence;
	char* forward = sentence;  

	while(*forward != '\0') 
	{ 
		if (*forward == ' ') 
		{ 
			reverse_string(start, ' ');
			start = forward + 1;  
		} 
		forward++; 
	}

	reverse_string(start, '\0');  
		
	return sentence; 	
} 

int main() 
{
	char input[] = "this is a program to reverse the position of all the words in a sentence"; 

    reverse_string(input, '\0');
	printf("%s\n", reverse_sentence(input)); 
 
	return 0; 
} 
