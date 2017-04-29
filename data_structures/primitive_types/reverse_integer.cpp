#include <cmath> 
#include <iostream> 

using namespace std; 

int reverse (int x) 
{
    if (!x) { 
        return x; 
    } 

    if (x == std::numeric_limits<int>::min()) { 
        cerr << "overflow" << endl; 
        return 0; 
    } 

    bool isnegative = false; 

    if (x < 0) { 
         isnegative = true; 
         x = abs(x); 
    } 

    int res = x % 10; 
    x /= 10; 

    while (x) { 
       // this is critical because we need to check for overflow before the overflow happens
       if (res > (std::numeric_limits<int>::max()/10)) { 
           cerr << "overflow" << endl; 
           return 0; 
       } 
       res = (res * 10) + (x % 10); 
       x /= 10; 
    } 

    return isnegative ? (-1 * res): res; 
} 

int main() 
{ 
    cout << reverse(123)<< endl; 
    cout << reverse(0)<< endl; 
    cout << reverse(-123)<< endl; 
    cout << reverse(1)<< endl;
    cout << reverse(10) << endl; 
    cout << reverse(std::numeric_limits<int>::max()) << endl;  
    cout << reverse(1534236469) << endl;  
    cout << reverse(-1563847412) << endl; 
    return 0; 
} 
