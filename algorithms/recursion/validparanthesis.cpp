#include <vector> 
#include <utility> 
#include <string> 
#include <iostream> 

using namespace std; 

bool isvalid(string s, int open) 
{
   if (s.empty()) { 
       return (open == 0); 
   } 

   if (s[0] == ')') { 
       if (open <= 0) { 
           return false; 
       } 
       --open; 
       return isvalid(s.substr(1), open); 
   }
   else if (s[0] == '(') {
       ++open; 
       return isvalid(s.substr(1), open); 
   }
   else { 
       // consider empty string
       if (isvalid(s.substr(1), open)) { 
           return true; 
       } 
       // consider close braces 
       if (isvalid(s.substr(1), open-1)) { 
           return true; 
       }
       // consider open braces 
       if (isvalid(s.substr(1), open+1)) { 
           return true; 
       }
   }
   
   return false; 
}

bool checkValidString(string s) {
    return isvalid(s,  0);             
}

namespace { 

    vector<pair<string, bool> > testcases = { 
        {"()", true}, 
        {"((*)", true}, 
        {"(())", true}, 
        {"((*", false}, 
        {"(((***()", true},
        {"((((****()()(((**)*)", true}, 
        {")(", false},
        {"**))(*", true}
    };
}

int main()
{
    for (auto t: testcases) { 
        if (checkValidString(t.first) != t.second) { 
            cerr << t.first << " " << "failed" << endl; 
        }
    } 

    return 0; 
}
