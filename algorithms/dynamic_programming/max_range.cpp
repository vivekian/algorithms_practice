
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int max_range_sum(vector<int> v) 
{
   int sum = 0, ans = 0; 

   for (unsigned i=0; i<v.size(); ++i) { 
       sum += v[i]; 
       ans = max(sum, ans); 

       if (sum < 0) 
           sum = 0; 
   }

   return ans;  
}


int main()
{
    assert(max_range_sum({3,1,-3,5,2,1}) == 9); 
    assert(max_range_sum({3,1,-3,-5,4}) == 4); 
    assert(max_range_sum({3,-3}) == 3); 
    return 0;  
}
