
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

vector<int> find_pattern(string T, string P) 
{
   vector<int> res; 
   auto pos = T.find(P);  

   while (pos != string::npos) { 
       res.push_back(pos); 
       pos = T.find(P, pos+1); 
   }

   return res; 
}

int main()
{
    string T = "sometimes there are a series of dreams where a dream has multiple dreams"; 
    string P = "dream";

    auto res = find_pattern(T, P); 

    for (const auto& i: res) { 
        printf("%d\n",i);  
    }

    return 0;  
}
