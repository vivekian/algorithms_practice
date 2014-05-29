
// Problem 5.4 Find the closest integer with the same weight. 
// The idea is that the number of bits which are set to 1 in an 
// unsigned long define the weight of the integer. Find the 
// closest integer of the same weight such that the diff between 
// them is minimum. 

#include <iostream> 
using namespace std; 

unsigned long Insert(unsigned long Num, const bool IsSet, const int Bit) 
{ 
	return IsSet? (Num | (1 << Bit)) : (Num & ~(1 << Bit)); 
} 

unsigned long Swap (unsigned long Num, const unsigned Bit) 
{
	bool lo = Num & (1 << (Bit -1)); 
	bool hi = Num & (1 << Bit); 
	Num = Insert(Num, lo, Bit); 
	Num = Insert(Num, hi, Bit-1); 
	return Num; 
}     

unsigned long find_closest_integer(unsigned long num) 
{ 
	unsigned long tmp = num; 
	unsigned idx = 0; 
	bool prev = false, curr = false; 

	while(tmp) { 
		curr = tmp & 1; 

		if ((idx > 0) && (prev != curr)) 
			break;

		prev = curr;  
		tmp >>= 1;
		++idx;  
	} 
	
	return Swap(num, idx); 	
} 

int main()
{ 
	cout << "8 " << find_closest_integer(8) << endl; 
	cout << "1 " << find_closest_integer(1) << endl; 
	cout << "2 " << find_closest_integer(2) << endl; 
	cout << "15 " << find_closest_integer(15) << endl; 
	cout << "1024 " << find_closest_integer(1024) << endl; 
	cout << "2047 " << find_closest_integer(2047) << endl; 
	return 0; 
} 
