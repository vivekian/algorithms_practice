#include <algorithm> 
#include <cstdio> 
#include <stdint.h> 

namespace { 
    const uint32_t MAX_CURRENCIES = 5; 
    
    const char* names[] = { 
        "USD", 
        "GBP", 
        "INR", 
        "JPY", 
        "EUR" }; 

    const double exchange_rate [MAX_CURRENCIES][MAX_CURRENCIES]= { 
        { 1.000, 0.700, 67.690, 118.690, 0.930 }, // USD
        { 1.428, 1.000, 96.630, 169.630, 1.320 }, // GBP
        { 0.015, 0.010,  1.000,   1.760, 0.013 }, // INR
        { 0.084, 0.058,  0.569,   1.000, 0.008 }, // JPY
        { 1.079, 0.755, 73.030, 128.179, 1.000 }, // EUR 
    };

    double maxratetbl[MAX_CURRENCIES] = {0};

}

double find_max_rate(const uint32_t start)
{ 
    if (start == MAX_CURRENCIES-1) 
        return 1; 

    if (maxratetbl[start]) 
        return maxratetbl[start];

    double maxrate = exchange_rate[start][MAX_CURRENCIES-1];

    for (unsigned i=start; i<MAX_CURRENCIES-1; ++i) { 
        maxrate = std::max(maxrate, exchange_rate[start][i+1] * find_max_rate(i+1));
    }   

    printf("max rate between %s and %s: %f\n", names[start], 
            names[MAX_CURRENCIES-1], maxrate);

    maxratetbl[start] = maxrate;
    return maxrate; 
} 

int main() 
{ 
    double final_amount = 100 * find_max_rate(0); 
    printf("$100 = E%f\n", final_amount);
    return 0; 
} 

