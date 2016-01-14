#include <iostream> 
using namespace std; 

// does not deal when y is an odd number 
int div_by_shift(unsigned x, unsigned y) 
{ 
	int cnt = 0; 

	if (y == 0) { 
		cerr << "Division by 0 not allowed" << endl; 
		return -1; 
	} 
	
	while (y != 1) { 
		y >>= 1; 
		++cnt; 
	} 
	
	while (cnt) { 
		x >>= 1; 
		--cnt; 
	} 
	
	return x; 
}

void assert_check(int a, int b) 
{ 
	if (a != b) 
		cerr << "both integers are not the same " << a << " " << b << endl; 
	else 
		cout << a << endl; 
}  

int main()
{ 
	assert_check(div_by_shift(6,2), (6/2)) ; 
	assert_check(div_by_shift(128,2), (128/2));  
	assert_check(div_by_shift(15,3), (15/3)); 
	assert_check(div_by_shift(15,3), (15/3));  
	assert_check(div_by_shift(15,4), (15/4));  
	assert_check(div_by_shift(632565,32), (632565/32));  
	return 0; 
} 
