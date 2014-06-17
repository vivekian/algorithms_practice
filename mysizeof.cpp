// Implement your own SIZEOF macro 
#include <iostream> 
using namespace std; 

#define SIZEOF(var) (char*)(&var+1) - (char*)(&var) 

int main() 
{
	int x = 23; 
	cout << SIZEOF(x) << endl;  
	return 0; 
} 
