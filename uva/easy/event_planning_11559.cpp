#include <limits> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

struct hotel { 
    uint32_t p; 
    vector<uint32_t> beds;
};

struct data 
{
   uint32_t nump; 
   uint32_t budget;
   uint32_t numh; 
   uint32_t weeks; 

   vector<hotel> hotels; 
};

void solve_problem(const data& d) 
{ 
    uint32_t mincost = numeric_limits<uint32_t>::max();

    for (const auto& h: d.hotels) { 
        uint32_t cost = h.p * d.nump; 
    
        if (cost <= d.budget) { 
             for (const auto& b: h.beds) {
                if ((b >= d.nump) && (cost < mincost)) { 
                        mincost = cost; 
                }
            }
        }
    }

    cout << ((mincost == numeric_limits<uint32_t>::max()) ? "stay home" : to_string(mincost));
    cout << endl; 
} 

int main()
{
    string s;
    vector<data> problems; 
    
    while (getline(cin, s)) { 

        if (s.empty()) { 
            continue;
        }
        
        data d; 
        sscanf(s.c_str(), "%u %u %u %u", &d.nump, &d.budget, &d.numh, &d.weeks);
        
        for (int i=0; i<d.numh; ++i) {
           hotel h;
           h.beds.resize(d.weeks);
           cin >> h.p; 
          
           for (int j=0; j<d.weeks; ++j) { 
               cin >> h.beds[j]; 
           }

           d.hotels.push_back(move(h));
        }

        problems.push_back(move(d));
    } 

     
    for(const auto& p: problems)
    {
       solve_problem(p); 
    }
     
    return 0;  
}
