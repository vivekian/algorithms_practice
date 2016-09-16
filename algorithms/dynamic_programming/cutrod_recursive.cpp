#include <algorithm> 
#include <cstdio> 
#include <stdint.h> 

// solution to the cutting a rod into peices to get maximum revenue. 
// from Introduction to Algorithms (15.1) 3rd Edition. 

uint32_t cutrod(uint32_t price[], uint32_t ninches) 
{ 
    uint32_t maxvalue = 0; 

    if (ninches == 0) 
        return 0;

    // notice that we iterate from 1 because we first cut a 1 inch part
    // and add it to the max value for the rest (ninchines - 1).  
    for (unsigned i=1; i<=ninches; ++i) { 
        maxvalue = std::max(maxvalue, 
                            price[i]+ cutrod(price, ninches-i));
    }

    return maxvalue; 
}

int main() 
{
    /// the first entry is a dummy value so we iterate from 1.  
    uint32_t price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; 
    printf("max value = %u\n", cutrod(price, 6));
    printf("max value = %u\n", cutrod(price, 10));
    return 0; 
} 
