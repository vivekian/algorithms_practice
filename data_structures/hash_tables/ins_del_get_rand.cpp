// this is a question from leetcode which asks: 
// Design a data structure that supports all following operations in average O(1) time.
//
// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
//
// we use unordered_map since its specifically asks for O(1) time complexity. 

#include <iostream> 
#include <random> 
#include <unordered_map> 

using namespace std; 

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto itr = m_map.find(val); 
        
        if (itr == m_map.end()) { 
            m_map[val] = true; 
            return true; 
        } 
        
        return false; 
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto itr = m_map.find(val); 
        
        if (itr == m_map.end()) { 
            return false; 
        }
        
        m_map.erase(val); 
        return true; 
    }
    
    /** Get a random element from the set. */
    int getRandom() {
	    // this is an assumption that we make - if there are no elements in the set
        // then return 0. 
        if (m_map.empty()) { 
			return 0; 
		}

        auto random_itr = std::next(std::begin(m_map), get_rnd_num()); 
        return random_itr->first; 
    }

private: 
    unordered_map<int, bool> m_map;

	int get_rnd_num() { 
		return (rand() % (int)(m_map.size()));
	} 
		
};

int main()
{  
	RandomizedSet obj;
	int val = 1;    
    
    for (int i=1; i<10; ++i) { 
        obj.insert(i); 
    } 

    bool param_1 = obj.insert(val);
    cout << obj.getRandom() << endl; 
    bool param_2 = obj.remove(val);
    int param_3 = obj.getRandom();
    cout << obj.getRandom() << endl;  
    cout << obj.getRandom() << endl; 
  
    return 0; 
} 
