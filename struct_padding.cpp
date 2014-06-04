#include <iostream> 
using namespace std; 

struct foo
{ 
	int x; 
	char c; 
}; 

int main() 
{
	struct foo bar;  
	int* y; 
	cout << sizeof(struct foo) << endl; 
	cout << sizeof(bar.x) << endl; 
	cout << sizeof(y) << endl; 
	return 0;
}
