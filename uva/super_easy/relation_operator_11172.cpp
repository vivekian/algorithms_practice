#include <cstdio> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int main()
{
    int tc, a, b; 
    int i=1;
    char c; 

    scanf("%d", &tc); 

    while (tc--) { 
        scanf("%d %d" , &a, &b); 
        c = (a > b) ? '>' : (a == b) ? '=' : '<';
        printf("%c\n", c); 
    }

    return 0;  
}
