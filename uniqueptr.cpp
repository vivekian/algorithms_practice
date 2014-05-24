// Simple example to illustrate RAII for unique pointers 
// Unique pointers support both -> and * operators and provide automatic garbage collection.  

#include <iostream> 
using namespace std; 

class X 
{ 
public: 
	X(){} 
	~X() { cout << "Destructor X" << endl; } 
	void Print() { cout << "X" << endl; } 
}; 

int main() 
{ 
	unique_ptr<X> ptr(new X()); 
	ptr->Print(); 
	return 0; 
} 
