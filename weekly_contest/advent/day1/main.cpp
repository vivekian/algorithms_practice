#include <set> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <fstream> 

using namespace std; 

int main()
{
    fstream myfile("input.txt", ios_base::in); 
    string s; 
    set<int> set_of_sums; 
    vector<int> v; 
    long long rollingsum = 0; 

    while(myfile >> s) { 
        v.emplace_back(stoi(s, nullptr));
    }

    int i = 0; 

    while (1) { 
        rollingsum += v[i]; 
        i = (i + 1) % v.size(); 
       
        if (set_of_sums.count(rollingsum)) { 
            cout << rollingsum << endl; 
            break; 
        }
        else { 
            set_of_sums.insert(rollingsum); 
        }
    }

    return 0;  
}
