#include <cstdio> 
#include <stdint.h> 

namespace { 
    const uint64_t M = 10; 
    const uint64_t N = 10; 

    uint64_t numpaths[M][N]; 
}

uint64_t find_num_paths(uint64_t x, uint64_t y) 
{
   if (x >= M-1)  // if we reach the bottom most row then there is only one path 
       return 1; 

   if (y >= N-1)  // if we reach the right most col then there is only one path
       return 1; 

   if (numpaths[x][y]) 
       return numpaths[x][y];

   uint64_t sum = find_num_paths(x+1, y) +  // go down 
                  find_num_paths(x, y+1);   // go right 

   numpaths[x][y] = sum; 
   return sum; 
}

int main() 
{ 
    printf("%llu\n", find_num_paths(0, 0));
    return 0; 
}
