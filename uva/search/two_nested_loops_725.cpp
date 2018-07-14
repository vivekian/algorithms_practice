
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

constexpr int subsolve(int d, int N) 
{
    int n = d * N; 
    int tmp = 0; 
    int used = d < 10000; 
    tmp = n; while(tmp) {used |= 1 << (tmp%10); tmp/=10;}    
    tmp = d; while(tmp) {used |= 1 << (tmp%10); tmp/=10;}    
    return used;
}

void solve()
{     
   for (int N=2; N<80; ++N) { 
        for (int fghij = 1234; fghij <= 98765/N; ++fghij) { 
            int used = subsolve(fghij, N);
            
            if (used == (1<<10)-1) { 
                printf("%0.5d %0.5d = %d\n", fghij*N, fghij, N); 
            }
        }
    }
}

int main()
{
    solve();
    return 0;  
}
