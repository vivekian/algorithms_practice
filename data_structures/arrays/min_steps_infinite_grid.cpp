#include <iostream> 
#include <vector> 
#include <cstdlib> 

using namespace std; 

inline int getMinSteps(int X1, int X2, int Y1, int Y2) 
{ 
	return max(abs(X2-X1), abs(Y2-Y1)); 
}

int coverPoints(vector<int> &X, vector<int> &Y)
{
	if (X.size() < 2) { 
		return 0; 
	} 

	int sum = 0; 

	for (int i=0; i<X.size()-1; ++i) { 
		sum += getMinSteps(X[i], X[i+1], Y[i], Y[i+1]); 
	}

	return sum; 
}

int main() 
{
	vector<int> X = {0,2,5,7}; 
	vector<int> Y = {0,7,3,2}; 

	cout << coverPoints(X, Y) << endl; 
	return 0;  
}
