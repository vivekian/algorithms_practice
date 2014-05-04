#include <iostream> 
#include <vector> 
using namespace std; 

vector<unsigned> g_FiboCache; 

unsigned int fibo(int n) 
{ 
	for (int i = 2; i <= n; ++i) { 
		g_FiboCache[i] = g_FiboCache[i-1] + g_FiboCache[i-2]; 
	} 

	return g_FiboCache[n]; 
} 

int main() 
{
	const int N = 100; 

	g_FiboCache.resize(N+1); 
	g_FiboCache[0] = 0; 
	g_FiboCache[1] = 1; 
 
	cout << fibo(N) << endl; 
	return 0; 
} 
