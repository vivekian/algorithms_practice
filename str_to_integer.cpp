#include <iostream> 
using namespace std; 

int str_to_integer(string & Str) 
{ 
	bool isNegative = false; 
	int i = 0;
	int num = 0;  
	
	if (Str == "0") 
		return 0; 

	if (Str[0] == '-') {  
		isNegative = true;
		++i; 	
	}  

	for (; i<Str.length(); ++i)  
		num = (num * 10) + (Str[i] - '0'); 

	if (isNegative) 
		num = -num; 

	return num; 
} 

int main() 
{
	string str = "0"; 
	string str1 = "123"; 
	string str2 = "-123"; 
	string str3 = "999999999"; 
	
	cout << str_to_integer(str) << endl; 
	cout << str_to_integer(str1) << endl; 
	cout << str_to_integer(str2) << endl; 
	cout << str_to_integer(str3) << endl; 
	return 0; 
} 


