
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

auto solution(int A, int B, int C) 
{
   int x, y, z;

   for (x=-100; x <=100; ++x) { 
    for (y=-100; y <= 100; ++y) { 
        for (z=-100; z <= 100; ++z) { 
            if ((x != y && y != z && z != x) && 
                (A == x+y+z) && (B == x*y*z) && (C == (x*x) + (y*y) + (z*z))) { 
                    printf("yes");
                    return make_tuple(x, y, z); 
                }                 
            }
        }
   }

   return make_tuple(0, 0, 0);  
}

int main()
{
    auto t = solution(6,6,14); 
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';
    return 0;  
}
