#include <deque> 
using namespace std; 

class HitCounter {
public:
    deque<pair<int, int>> q;
    
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
     void hit(int timestamp) {
        // if a queue is empty, then add a new timestamp.
        if (q.empty() || (q.back().first != timestamp)) {
            q.push_back(make_pair(timestamp, 1));
        }
        else { 
         // if last item has same timestamp as new ts, then just increment cnt;
            q.back().second++;
        }
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
       if (q.empty()) 
            return 0; 
      
        while (timestamp - (q.front().first) >= 300 && !q.empty()) {
            q.pop_front();
        }

        int res = 0; 
        for (const auto& i: q) { 
            res += i.second; 
        }
        return res; 
    }
};
