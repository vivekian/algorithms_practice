#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

bool issum(vector<int> sofar, vector<int> rest, int n, int sum) 
{
   if (sum == n) 
      return true; 

   if ((sum > n) || rest.empty())
      return false; 

   // choose one vector which has the element and another one 
   // which does not have the item. 
   vector<int> next = sofar; 
   int tmp = rest[0]; 
   next.push_back(tmp); 
   rest.erase(rest.begin()); 

   return (issum(next, rest, n, sum + tmp)) || 
          (issum(sofar, rest, n, sum)); 
}

int main()
{
    vector<int> p = {10,12,5,7}; 
    assert(issum({}, p, 25, 0) == false); 
    assert(issum({}, p, 24, 0) == true); 
    assert(issum({}, p, 13, 0) == false); 
    assert(issum({}, p, 34, 0) == true); 
    return 0;  
}
