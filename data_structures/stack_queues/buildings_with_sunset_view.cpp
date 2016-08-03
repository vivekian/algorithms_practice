// the question asks if we can list all the buildings are lined up one behind another 
// all facing west and can see the sunset. ofcourse smaller or equal heighted buildings 
// which are behind one another won't be able to see the sunset. input is given from 
// east to west in terms of building height. 

#include <vector> 
#include <stack> 
#include <iostream> 

using std::vector; 
using std::stack; 
using std::cout; 

int GetBuildingsWithSunsetView(const vector<uint32_t>& buildings, vector<uint32_t>& buildings_view)
{ 
    if (buildings.empty()) 
        return -1; 

    stack<uint32_t> s; 

    for (const auto& b: buildings) { 

        if (s.empty()) { 
            s.push(b); 
        }
        else { 

            while (!s.empty() && s.top() <= b) { 
                s.pop(); 
            }

            s.push(b); 
        }
    }

    while (!s.empty()) { 
        buildings_view.push_back(s.top());
        s.pop();
    }

    return 0; 
}

int main()
{ 
    // from east to west 
    vector<uint32_t> input_bldgs = {6, 2, 4, 1, 3}; 
    vector<uint32_t> output_bldgs = {}; 

    GetBuildingsWithSunsetView(input_bldgs, output_bldgs); 

    for(const auto& b: output_bldgs) 
        cout << b << " "; 

    cout << "\n"; 

    return 0; 
}
