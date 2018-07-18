#include <numeric> 
#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int main()
{
    int n=0; 
    int setno=0; 

    while (scanf("%d", &n)) { 
        if (!n) 
            break; 

        vector<int> heights(n); 

        while (n) { 
            scanf("%d", &heights[n-1]); 
            --n; 
        }

        sort(heights.begin(), heights.end()); 
        int average = std::accumulate(heights.begin(), heights.end(), 0) / heights.size();
        
        int i=0, j=heights.size()-1, k=0;

        while (i < j) { 
            
            while (heights[j] == average && (i<j))
                --j; 

            while (heights[i] == average && (i<j)) 
                ++i; 

            if (i>=j) 
                break; 

            --heights[j]; 
            ++heights[i]; 
            ++k; 
        }

        ++setno; 
        printf("Set #%d\n", setno); 
        printf("The minimum number of moves is %d\n\n", k); 
    }
    
    return 0;  
}
