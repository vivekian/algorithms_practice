#include <cstdio> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int main()
{
    int k; 
    int cx, cy; 
    int x, y; 

    
    while (scanf("%d", &k) && k) { 
        scanf("%d %d", &cx, &cy); 

        while (k--) { 
            scanf("%d %d" , &x, &y); 
            string res = "divisa"; 

            if (y > cy) {
                res =  (x > cx) ? "NE" : (x < cx) ? "NO" : "divisa";
            }
            else if (y < cy) { 
                res =  (x > cx) ? "SE" : (x < cx) ? "SO" : "divisa";
            }
               
            printf("%s\n", res.c_str());  
        }
    }

    return 0;  
}
