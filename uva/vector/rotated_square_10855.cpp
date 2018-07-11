
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

namespace { 
    using square = vector<string>; 
}

square rotate(square& input) 
{
   const auto N = input.size(); 
   string s(N, ' '); 
   square res(N, s); 

   for (int i=0; i<N; ++i) { 
       for (int j=0; j<N; ++j) { 
           auto r = j; 
           auto c = N-1-i;
           res[r][c] = input[i][j];   
       }
   }

   return res; 
}

int find_subsquares(const square& big, const square& small) 
{
   int res = 0; 

   for (int i=0; i<big.size()-small.size(); ++i) { 
            auto pos = big[i].find(small[0]); 
            
            if (pos != string::npos) { 
                int r=1; 
                for (; r<small.size(); ++r) { 
                    if (big[i+r].substr(pos, small.size()) != small[r]) { 
                            break; 
                    }
                }

                if (r == small.size()) 
                    ++res; 
            }
    }
    
    return res; 
} 

void print(ostream& os, const vector<string>& v) 
{
   os << '\n'; 
   for (const auto& i: v) { 
       os << i << '\n'; 
   } 
}

int main()
{
    do { 
        int bigN, smallN; 
        scanf("%d %d", &bigN, &smallN); 

        if (bigN == 0 || smallN == 0) 
            break; 

        square big, small; 

        // parse big square 
        while (bigN) { 
            char s[bigN+1]; 
            scanf("%s", s); 
            big.emplace_back(string(s)); 
            --bigN; 
        }

        // parse small square 
        while (smallN) { 
            char s[smallN+1]; 
            scanf("%s", s); 
            small.emplace_back(string(s)); 
            --smallN; 
        }

        cout << '\n';
        for (int i=0; i<4; i++) { 
            cout << find_subsquares(big, small) << " "; 
            small = rotate(small); 
        }

    }while(1); 

    return 0;  
}
