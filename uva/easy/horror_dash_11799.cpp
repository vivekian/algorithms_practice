#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

// At this event, N (1 ≤ N ≤ 100) students dressed in the scariest
// costumes possible start out in a race to catch a poor clown running on
// the same track
//
// To keep the event running for as long as possible, the clown must run fast enough not to be caught by any of the scary creatures. However, to keep the audience on the edge of their seats, the clown must not run too fast either
//
//

struct testcase { 
    uint32_t num; 
    vector<uint32_t> speeds; 
}; 

void find_min_speed(const vector<testcase>& tests) 
{
   for (int i=0 ;i<tests.size(); ++i) { 
        auto item = max_element(tests[i].speeds.begin(), tests[i].speeds.end()); 
        cout << "Case " << i+1 << ": " << *item << endl; 
   } 
}

int main()
{
    uint32_t N; 
    vector<testcase> tests; 

    cin >> N; 
    tests.reserve(N);

    while (N) {
        testcase t;  
        cin >> t.num; 
        
        t.speeds.resize(t.num); 

        for (int i=0; i<t.num; ++i) { 
            cin >> t.speeds[i]; 
        }

        tests.push_back(move(t)); 
        N--; 
    }

    find_min_speed(tests); 
    return 0;  
}
