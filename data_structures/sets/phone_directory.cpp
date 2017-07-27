#include <set> 
using namespace std; 

class PhoneDirectory {
private: 
    int max_num = 0; 
    int cnt = -1; 
    set<int> s; 
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        max_num = maxNumbers; 
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int ret=-1; 
        
        if (!s.empty()) {
            ret = *s.begin(); 
            s.erase(s.begin()); 
        }
        else if (cnt != max_num-1) { 
            ++cnt; 
            ret = cnt; 
        }
        
        return ret; 
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number > cnt && number < max_num) { 
            return true; 
        }
        
        return s.count(number); 
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number <= cnt && !s.count(number)) { 
            s.insert(number); 
        }
    }
};

