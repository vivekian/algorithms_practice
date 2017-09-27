#include <utility> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

namespace { 
    // path available to end of maze. 
    vector<vector<int>> m = { 
        {1,1,1,0},
        {1,0,1,1},
        {1,0,0,1},
        {0,0,0,1}
    };

    // no path to destination
    vector<vector<int>> m2 = { 
        {1,1,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,0},
        {0,0,0,0,1}
    };
}

// simple maze solution where we start from (0,0) and goto (3,3). 
// for simplicity try to go either down or right
// but never left or back up. 1 indicates path, 0 indicates wall. 

bool DFS(vector<vector<int>> &m, pair<int, int> p, pair<int, int> d, vector<vector<bool>>& v) 
{
   cout << p.first << " " << p.second << endl; 
   if (p == d) { 
       return true; 
   } 

   v[p.first][p.second] = true; 

   // try down 
   if  (p.first < d.first && m[p.first+1][p.second] == 1 && !v[p.first+1][p.second]) {
       if (DFS(m, {p.first+1, p.second}, d, v)) { 
               return true; 
       }
   }

   // try right - as long as not crossing boundary. 
   if  (p.second < d.second && m[p.first][p.second+1] == 1 && !v[p.first][p.second+1]) {
       if (DFS(m, {p.first, p.second+1}, d, v)) { 
               return true; 
       }
   }

   return false; 
}

bool solve(vector<vector<int>> &m) { 
    pair<int, int> s = {0,0};
    pair<int, int> d = {m.size()-1, m.size()-1}; 
    vector<vector<bool>> v(m.size()); 

    for (auto& i: v) { 
        i.resize(m.size()); 
    }

    return DFS(m, s, d, v); 
}

int main()
{
    cout << solve(m) << endl; 
    cout << solve(m2) << endl; 
    return 0;  
}
