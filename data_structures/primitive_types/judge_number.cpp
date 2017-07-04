#include <cmath> 
#include <limits> 
#include <iostream> 
#include <vector> 
using namespace std; 

bool judgeSquareSum(int c) {
	int max = ceil(sqrt(c)); 
	
	for (int i=0 ; i<=max; ++i) { 
		int sqterm = c - (i * i); 
		int root = sqrt(sqterm); 

		if (sqterm == (root * root)) { 
			return true; 
		} 
	} 

	return false; 
}

namespace { 
	struct test { 
		int n; 
		bool res;
		
		test(int num, bool exp): n(num), res(exp) {} 
	};

	vector<test> testcases = { 
		{ 0, true}, 
		{ 1, true},
		{ 2, true}, 
		{ 3, false},  
		{ 4, true},  
		{ 5, true}, 
		{ 6, false}, 
		{ 7, false}, 
		{13, true}, 
		{15, false}, 
		{25, true},
		{numeric_limits<int>::max(), false}};
}

int main() 
{ 
	for (const auto& t: testcases) { 
		if (judgeSquareSum(t.n) != t.res) { 
			cout << "fail\n"; 
		} 
	} 
	
	return 0; 
} 
		 
