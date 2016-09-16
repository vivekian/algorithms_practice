// fibonacci recursive solution grows exponentially. 
// exactly at 1.61^n (golden ratio) 

#include <iostream> 
#include <map> 
using namespace std; 

static map<unsigned, unsigned> g_FiboCache; 

unsigned int fibo(int n) 
{ 
	map<unsigned,unsigned>::iterator i = g_FiboCache.find(n); 
	if (i != g_FiboCache.end())  
		return i->second; 

	g_FiboCache[n] = fibo(n-1) + fibo(n-2); 

	return g_FiboCache[n]; 
} 

int main() 
{
	g_FiboCache[0] = 0; 
	g_FiboCache[1] = 1; 
 
	cout << fibo(100) << endl; 
	return 0; 
} 
