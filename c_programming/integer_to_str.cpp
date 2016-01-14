// Write your own integer to string routine which takes care of negative numbers as well 

#include <string> 
#include <iostream> 

using namespace std; 

string inttostr(int Num) 
{
	string str = "";
	char prefix = ' '; 
 
	if (Num == 0) 
		str = "0"; 

	if (Num < 0) { 
		prefix = '-'; 
		Num = -Num; 
	} 

	while (Num) { 
		str = static_cast<char>('0' + (Num % 10)) + str; 
		Num /= 10; 
	} 
	
	return prefix + str; 	
}  		

int main() 
{
	cout << inttostr(-123) << endl;  
	cout << inttostr(123) << endl;  
	cout << inttostr(0) << endl;  
	cout << inttostr(999999999) << endl;  
	cout << inttostr(1) << endl;  
	return 0; 
} 
