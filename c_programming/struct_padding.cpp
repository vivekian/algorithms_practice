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

	// although the total size is 5, compiler pads extra bytes to 8 
	// this is done for alignment purposes.  
	cout << sizeof(struct foo) << endl; 
	cout << sizeof(bar.x) << endl; 
	
	// this is printing 8 bytes, because we are on a 64 bit machine 
	cout << sizeof(y) << endl; 
	return 0;
}
