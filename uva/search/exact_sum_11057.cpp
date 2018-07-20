#include <algorithm> 
#include <map> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

void solve(vector<int>& p, int m) 
{
   pair<int, int> sol = {0,0}; 
   std::sort(p.begin(), p.end()); 

   for (unsigned i=0; i<p.size(); ++i) { 
       /* search and check if it exists, then get iterator */ 
       if (binary_search(p.begin(), p.end(), m-p[i])) { 
        auto it = lower_bound(p.begin(), p.end(),  m - p[i]); 
       
        /* found a pair of books */  
        if (it - p.begin() != i) {
            /* solution not found so far */ 
            if (sol == make_pair<int, int>(0, 0)) { 
                sol = {p[i], *it}; 
            }
            else {
                if (abs(p[i] - *it) < abs(sol.first - sol.second)) { 
                    sol = {p[i], *it}; 
                }
            }
        }
       }
   } 

   printf("Peter should buy books whose prices are %d and %d.\n\n", sol.first, sol.second);  
}

int main()
{
    int n; 
    
    while (scanf("%d", &n) != EOF) { 
        int i=0; 
        int m=0; 
        vector<int> p(n); 

        while (n) { 
            scanf("%d", &p[i]); 
            ++i; --n; 
        }

        scanf("%d", &m); 
        solve(p, m); 
    }

    return 0;  
}

