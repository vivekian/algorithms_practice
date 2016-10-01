// this is a solution to a leetcode problem: 
// https://leetcode.com/problems/compare-version-numbers/

#include <vector> 
#include <iostream> 
#include <string> 
#include <cstdlib> 

using namespace std; 

struct version { 
    version(string v) 
    { 
        auto pos = v.find("."); 

        while (pos != string::npos) { 
            revisions.emplace_back(atoi(v.substr(0,pos).c_str())); 
            v = v.substr(pos+1);
            pos = v.find(".");  
        } 
       
        revisions.emplace_back(atoi(v.c_str()));  
    }

    int compare(version& other) 
    { 
        int i=0; 

        while (i < revisions.size() && i < other.revisions.size()) { 
            if (revisions[i] > other.revisions[i]) {
                return 1; 
            } 
            else if (revisions[i] < other.revisions[i]) { 
                return -1; 
            }
            
            ++i;  
        } 

        while (i < revisions.size()) { 
            if (revisions[i] > 0) { 
                return 1; 
            } 
            ++i; 
        } 

        while (i < other.revisions.size()) { 
            if (other.revisions[i] > 0) { 
                return -1; 
            } 
            ++i; 
        } 
        
        return 0; 
    } 

    vector<int> revisions; 
}; 

int compareVersion (string version1, string version2) 
{ 
    version v1(version1);  
    version v2(version2);  

    return v1.compare(v2); 
} 

int main()
{
    cout << compareVersion(string("1.1"), string("1.2")) << endl;  
    cout << compareVersion(string("1.2"), string("1.1")) << endl;  
    cout << compareVersion(string("1.1"), string("1.1")) << endl;  
    cout << compareVersion(string(""), string("")) << endl;  
    cout << compareVersion(string("1.1"), string("")) << endl;  
    cout << compareVersion(string("13"), string("0")) << endl;  
    cout << compareVersion(string("13.234567"), string("13.234568")) << endl;  
    cout << compareVersion(string("01"), string("1")) << endl;  
    cout << compareVersion(string("1.1"), string("1.10")) << endl;  
    cout << compareVersion(string("1"), string("1.1")) << endl;  
    cout << compareVersion(string("1"), string("1.01")) << endl;  
    return 0; 
} 
