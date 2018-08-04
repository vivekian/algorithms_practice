
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int count_cigarrates(int n, int k) 
{
   int curr = n; 
   int extra = 0; 

   while (curr >= k) { 
       curr -= k; 
       ++extra; ++curr; 
   }
    
   return n + extra;  
}
    

int main()
{
    cout << count_cigarrates(4, 3) << endl; 
    cout << count_cigarrates(10, 3) << endl; 
    cout << count_cigarrates(100, 5) << endl; 
    return 0;  
}
