#include <cstdio> 
#include <iostream> 

using namespace std; 

void memcpy(void* src, void* dst, size_t length) 
{ 
	if (!src || !dst) 
		return; 

	const char* s = static_cast<const char*>(src); 
	char* d = static_cast<char*>(dst); 

	while(length--)
		*d++ = *s++; 
	
	return; 	
} 

int main()
{
	const char* source = "abcdefghi\0"; 
	char* dest = new char[100]; 
	
	memcpy((void*)source, dest, 100); 
	cout << dest << endl; 	 

	delete []dest; 
	return 0; 
}  
