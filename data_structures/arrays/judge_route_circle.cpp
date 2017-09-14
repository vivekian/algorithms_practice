#include <iostream> 
#include <utility> 
#include <string> 

using namespace std; 

bool judgeCircle(string moves) {
    pair<int, int> pos = {0,0};            

    for (const char m: moves) { 
        switch(m) { 
            case 'U': pos.first--; break; 
            case 'D': pos.first++; break; 
            case 'L': pos.second--; break; 
            case 'R': pos.second++; break; 
            default: break; 
        }
    }

    return ((pos.first == 0) && (pos.second == 0)); 
}

int main()
{
    cout << judgeCircle("RDLU") << endl;  
    cout << judgeCircle("RRLL") << endl;  
    cout << judgeCircle("RRRRRRRRRRRRRRRRRRRRRRRLLLLLLLL") << endl;  
    return 0; 
}
