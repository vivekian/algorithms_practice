#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 

using namespace std; 

string get_common_prefix(string s1, string s2) 
{ 
    int i=0, j=0; 
    for ( ; i<s1.size() && j<s2.size(); i++,j++) { 
        if (s1[i] != s2[j]) { 
            return s1.substr(0, i); 
        } 
    } 

    if (i < s1.size()) { 
       return s2; 
    } 
    
    return s1; 
} 
     

string longest_common_prefix(vector<string>& strs) 
{
    if (strs.empty()) { 
        return ""; 
    } 

    int min_idx = 0; 

    // find the string with the smallest length. 
   for (int i=1; i<strs.size(); ++i) { 
      if (strs[i].size() < strs[min_idx].size()) { 
          min_idx = i; 
      } 
   } 

   string common = strs[min_idx]; 

   // iterate all the strings 
   for (int i=0; i<strs.size(); ++i) { 
       if (i != min_idx) {
           common = get_common_prefix(common, strs[i]); 
       } 
    } 

   return common; 
}

int run_tests() 
{ 
    typedef vector<string> strlist; 

    vector<pair<strlist, string>> testcases = { 
        {{"geeksforgeeks", "geeksfor", "geeks", "geek"},{"geek"}},
        {{" ","   ", ""},{""}}
    }; 

    for (auto& test: testcases) { 
        if (test.second == longest_common_prefix(test.first)) { 
            cout << "passed" << endl; 
        } 
        else { 
            cout << "failed" << endl; 
            return 1; 
        } 
    }

    return 0; 
}

int main() 
{
    return run_tests(); 
} 
