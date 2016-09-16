#include <iostream> 
using namespace std; 

void MoveSingleDisk(int disk, char src, char dst)
{ 
	cout << "moving disk " << disk <<  " from " << src << " to " << dst << endl; 
} 

/* the primary idea is to not to worry about the n-1 disks 
   and consider it as an abstract operation, just move them
   and then move the single bottommost disk and again move 
   back the n-1 disks back on top of the bottommost disk */ 

void MoveTower(int n, char src, char dst, char tmp) 
{ 
	if (n > 0) 
	{ 
		MoveTower(n-1, src, tmp, dst); 
		MoveSingleDisk(n-1, src, dst); 
		MoveTower(n-1, tmp, dst, src); 
	} 
}  

int main() 
{ 
	char src = 'a'; 
	char dst = 'b'; 
	char tmp = 'c'; 
	
	int n; 
	cout << "enter no of disks" << endl; 
	cin >> n; 
	
	MoveTower(n, src, dst, tmp); 

	return 0; 
} 
