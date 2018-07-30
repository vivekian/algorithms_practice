#include <unordered_map> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

namespace { 
    using vs = std::vector<string>; 
}

vector<string> anangrams(vector<string>& dict) 
{
   unordered_map<string, vs> anagrams; 

   for (auto& s: dict) { 
       string sortedstr(s); 
       sort(sortedstr.begin(), sortedstr.end()); 

       if (anagrams.count(sortedstr)) { 
            anagrams[sortedstr].push_back(s); 
       }
       else { 
           anagrams[sortedstr] = {s}; 
       }
   }

   vs res = {}; 

   for (auto& s: anagrams) {
       if (s.second.size() == 1) { 
           res.push_back(s.second[0]); 
       }
   }

   return res; 
}

void print(vs& strlist) 
{
   for (auto& s: strlist) { 
       printf("%s\n", s.data()); 
   } 
}

int main()
{
    vs strlist = {"DICE", "CEDI", "ab"}; 
    auto res = anangrams(strlist); 
    print(res); 
    assert (res == vs{"ab"}); 
    return 0;  
}
