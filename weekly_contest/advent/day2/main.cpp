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
    vector<int> v; 
    long twocount = 0; 
    long threecount = 0; 


    while(myfile >> s) { 
    
        vector<int> charcnt(26, 0); 
        bool two = false; 
        bool three = false; 

        for (const char c: s) { 
            charcnt[c-'a']++; 
        }

        for (const int cnt: charcnt) { 
            if (cnt == 2) { 
                two = true; 
            }
            if (cnt == 3) { 
                three = true; 
            }
        }

        if (two) { 
            twocount++; 
        }

        if (three) { 
            threecount++; 
        }
    }

    cout << twocount * threecount << endl; 
    return 0;  
}
