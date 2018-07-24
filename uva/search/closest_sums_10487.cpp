
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int closest_sum(vector<int>& v, int q) 
{
    if (q < v[0]) 
        return (v[0] + v[1]); 
    
    int closestsum = v[0] + v[1]; 

    for (unsigned i=0; i<v.size(); ++i) { 
        for (unsigned j=i+1; j<v.size(); ++j) { 
            int sum = v[i] + v[j];
            if (abs(q - sum) <= abs(q - closestsum)) { 
                closestsum = sum; 
            } 
        }
    }

    return closestsum;  
}

int main()
{
    int k=1; 

    while (true) { 
        int n = 0, m = 0; 
        scanf("%d", &n); 
    
        if (n == 0) 
            break; 

        vector<int> v(n); 
        int i=0; 

        while (n) { 
            scanf("%d", &v[i]); 
            ++i; --n; 
        }

        sort(v.begin(), v.end()); 
        scanf ("%d", &m); 
        printf("Case %d:\n", k);  

        while (m) { 
            int q; 
            scanf("%d", &q); 
            printf("Closest sum to %d is %d.\n", q, closest_sum(v, q)); 
            --m; 
        }

        ++k; 
    }

    return 0;  
}
