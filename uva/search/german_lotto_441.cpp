
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

// complete exhaustive search 
void print_all_subsets(const vector<int>& s) 
{
    int k = s.size(); 

    for (int a=0; a<k-5; a++) { 
        for (int b=a+1; b<k-4; b++) { 
            for (int c=b+1; c<k-3; c++) {
               for (int d=c+1; d<k-2; d++) { 
                   for (int e=d+1; e<k-1; e++) { 
                       for (int f=e+1; f<k; f++) {
                           printf("%d %d %d %d %d %d\n", 
                                  s[a], s[b], s[c], s[d], s[e], s[f]); 
                       }
                   }
               } 
           }
        }
    }
}

int main()
{
    vector<int> s = {1,2,3,4,5,6,7,8,9};
    print_all_subsets(s );
    return 0;  
}
