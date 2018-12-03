#include <set> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <fstream> 

using namespace std; 

string comp(string a, string b) { 
    string res = ""; 

    for (int i=0; i<a.size(); ++i) { 
        if (a[i] == b[i]) { 
            res += a[i]; 
        }
    }

    return res; 
}

int main()
{
    fstream myfile("input.txt", ios_base::in); 
    string s; 
    vector<string> v; 


    while(myfile >> s) { 
        v.emplace_back(s); 
    }


    for (int i=0; i<v.size(); ++i) { 
        for (int j=i+1; j<v.size(); ++j) { 
            auto str = comp(v[i], v[j]); 

            if (str.size() == v[i].size()-1) { 
                cout << str << endl;  
                break; 
            }
        }
    }

    return 0;  
}
