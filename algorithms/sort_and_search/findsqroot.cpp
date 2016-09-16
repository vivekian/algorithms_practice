// problem 12.6 of EPI book. 
// find the integer square root of a number

// best approach to solve a problem like this is to run through a few 
// examples and see if there is a general pattern which comes up. 

#include <iostream> 
#include <utility> 
#include <vector> 
#include <numeric> 

using namespace std; 

long long square(int K) 
{ 
    return K * K; 
}

int findSqRoot(const int Num) 
{
    long lo = 0; 
    long hi = Num;

    while (lo <= hi) { 

       
       long long mid = (lo < 0) ?  (hi - lo)/2 : (lo + (hi - lo)/2); 
       long long prod = square(mid); 

       if (prod == Num) {               // exact integer match 
           return mid; 
       } 
       else if (prod > Num) {           
           hi = mid - 1; 
       } 
       else { 
           lo = mid + 1; 
       }
    }

    return hi;                          // return hi because lo became greater than hi and hi is the closest match. 
} 

int main() 
{ 
    vector<pair<int, int>> testcases = 
    { 
        {0,0}, 
        {9,3}, 
        {12, 3}, 
        {1, 1}, 
        {300, 17}, 
        {121, 11},
    }; 

    for (auto& test: testcases) { 
        if (findSqRoot(test.first) != test.second) { 
            cout << "test failed" << endl; 
        } 
    } 

    return 0; 
} 
