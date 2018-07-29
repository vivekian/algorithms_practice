#include <limits>
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int min_coins(vector<int> denom, int value) 
{
   constexpr int minval = numeric_limits<int>::max(); 
   vector<int> coins(value+1, minval); 

   // all the denominations will require a single coin. 
   for (auto &i: denom) 
      coins[i] = 1; 

   for (int i=denom[0]; i<= value; i++) {
       if (coins[i] == 1) 
         continue; 

       for (int j=i-1; j>=denom[0]; --j) { 
             int sum = coins[j] + coins[i-j]; 
             if (sum < coins[i]) { 
                 coins[i] = sum; 
             }
       }
   }
   
   return coins[value];  
}

int main()
{
    printf("8 %d\n", min_coins({1,5}, 8)); 
    printf("8 %d\n", min_coins({1,3,5}, 8)); 
    return 0;  
}
