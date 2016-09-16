#include <algorithm> 
#include <cstdio> 
#include <stdint.h> 

// solution to the cutting a rod into peices to get maximum revenue. 
// from Introduction to Algorithms (15.1) 3rd Edition. 
// this is solving using memoization. 

namespace {
    /// the first entry is a dummy value so we iterate from 1.  
    const uint32_t price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; 
    constexpr uint32_t entries = sizeof(price)/sizeof(uint32_t);
    // this array is for memoization so that we don't recompute the solution 
    // over and over again. 
    uint32_t revenues[entries] = {0};
}; 

uint32_t cutrod(const uint32_t price[], const uint32_t n) 
{ 
    uint32_t maxvalue = 0; 

    if (revenues[n]) 
        return revenues[n]; 

    if (n == 0) 
        return 0;

    // notice that we iterate from 1 because we first cut a 1 inch part
    // and add it to the max value for the rest (n - 1).  
    for (unsigned i=1; i<=n; ++i) {
         
        maxvalue = std::max(maxvalue, 
                            price[i]+ cutrod(price, n-i));
    }

    revenues[n] = maxvalue; 
    return maxvalue; 
}

int main() 
{
    printf("max value = %u\n", cutrod(price, 6));
    printf("max value = %u\n", cutrod(price, 10));

    return 0; 
} 
