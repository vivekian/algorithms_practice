#include <cstdio> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int main()
{
    int tc, a, b, c; 
    int i=1;

    scanf("%d", &tc); 

    while (tc--) { 
        scanf("%d %d %d", &a, &b, &c); 
        int z = max(min(max(a, b), c), min(a,b)); 
        printf("Case %d: %d\n", i++, z); 
    }

    return 0;  
}
