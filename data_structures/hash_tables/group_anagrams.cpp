
#include <iostream> 
#include <string> 
#include <vector> 
#include <unordered_map> 

using namespace std; 

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> table; 

    for (auto &s: strs) { 
        auto t = s; 
        sort(t.begin(), t.end()); 
        table[t].push_back(s); 
    }    

    vector<vector<string>> res; 

    for (auto item: table) { 
        res.emplace_back(item.second); 
    }
       
    return res;  
}

int main()
{
    return 0;  
}
