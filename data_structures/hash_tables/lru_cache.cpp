#include <limits> 
#include <iostream> 
#include <unordered_map> 
#include <list> 

using namespace std; 

class LRUCache {
public:
    LRUCache(int capacity) {
     	cap = capacity;    
    }
    
    int get(int key) {
        int res = -1; 

  		if (hashtable.find(key) != hashtable.end()) { 
			q.remove(key); 
			q.push_front(key); 
		    res = hashtable[key]; 	      
        }

        return res; 
    }
    
    void put(int key, int value) {
       // if the key already exists, then remove from the queue 
       // and move it to the front since its a fresh hit 
       if (hashtable.find(key) != hashtable.end()) { 
			q.remove(key);
		}
		else if (q.size() == cap) { 
            // hash table can only store cap number of entries, so remove the LRU entry. 
            hashtable.erase(q.back()); 
		    q.pop_back();
		} 
			
	    // move key to the front of the queue 
        q.push_front(key); 
		hashtable[key] = value; 
    }

private: 
	// this is the cache 
    unordered_map<int, int> hashtable;
    // list is used to maintain the queue of LRU items. 
	list<int> q; 
    // capacity of the queue 
	int cap;  
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{ 
    LRUCache lr(2);
    cout << lr.get(1) << endl;  
    lr.put(1,1); 
    lr.put(2,2); 
    cout << lr.get(1) << endl;  
    cout << lr.get(2) << endl;  
    lr.put(3,3); 
    cout << lr.get(1) << endl; 
    return 0; 
} 
