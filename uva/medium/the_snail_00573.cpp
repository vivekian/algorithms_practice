#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

struct testcase { 
    uint32_t h; 
    uint32_t up; 
    uint32_t down; 
    float f; 
}; 

void solve(const vector<testcase>& tests) 
{
    for (const auto& t: tests) { 
        float height = t.up - t.down; 
        uint32_t day = 1; 
        float fatigue = static_cast<float>(t.f/100) * t.up; 
        float climb = t.up - fatigue; 

        while (height >= 0 && height < t.h) {
            ++day; 

            // slide up 
            if (climb > 0) { 
                 height += climb; 
            }
            
            if (height >= t.h) { 
                break; 
            }

            // slide down 
            height -= t.down;
             
            if (height < 0) { 
                break; 
            }

            climb -= fatigue;
        }
        
        cout << ((height >= t.h) ? "success":"failure")  << " on day " << day << endl; 
    }
}

int main()
{
    vector<testcase> tests; 

    do { 
        testcase t; 
        cin >> t.h >> t.up >> t.down >> t.f; 

        if (t.h == 0) { 
            break; 
        }

        tests.push_back(move(t)); 
    } while (1); 

    solve(tests); 

    return 0;  
}
