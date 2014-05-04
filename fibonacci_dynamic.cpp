#include <iostream> 
#include <map> 
using namespace std; 

static map<unsigned int, unsigned int> g_FiboCache; 

unsigned int fibo(int n) 
{ 
	map<unsigned int,unsigned int>::iterator i = g_FiboCache.find(n); 
	if (i != g_FiboCache.end())  
		return i->second; 
		
	if (n <= 2) { 
		g_FiboCache[n] = 1; 
		return 1; 
	} 

	cout << n <<endl; 	
	g_FiboCache[n] = fibo(n-1) + fibo(n-2); 
	return g_FiboCache[n]; 
} 

int main() 
{ 
	cout << fibo(500) << endl; 
	return 0; 
} 
