// Paranthesis validator using STL built in Stack class 
// Practice without using built in class. 

#include <iostream> 
#include <stack> 
#include <string> 

bool IsValid(const std::string& Str) 
{ 
	std::stack<char> s;
	bool valid = true;  

	for (const char& c: Str) 
	{ 
		if (c == '(') 
		{  
			s.push('(');
		}  
		else if (c == ')') 
		{		
			if (s.empty()) 
			{  
				std::cerr << "Paranthesis string is invalid" << std::endl; 
				valid = false;
				break;  
			} 
			else 
				s.pop(); 
		} 
		else 
		{ 
			std::cerr << "Invalid character" << std::endl; 
			valid = false;
			break;  
		} 
	} 
	
	if (!s.empty()) 
	{ 
		valid = false;
	}  	

	return valid; 
} 

int main() 
{ 
	std::string str = "(())"; 
	std::string str1 = "(()))"; 
	std::string str2 = ")()(("; 
	std::string str3 = "(((((()())))))"; 

	std::cout << IsValid(str) << std::endl; 
	std::cout << IsValid(str1) << std::endl; 
	std::cout << IsValid(str2) << std::endl; 
	std::cout << IsValid(str3) << std::endl; 

	return 0;
} 
