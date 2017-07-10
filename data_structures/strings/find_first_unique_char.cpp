#include <string> 
#include <vector> 
#include <set> 

int firstUniqChar(string s) {
    	// first keeps track of index, and the second the count of the char.
	    vector<pair<int, int>> idxcnt (26);
        for (auto& v: idxcnt) { 
            v.first = 0; 
            v.second = 0; 
        }

	    // set keeps track of all the single occurance chars (indexes)    
        set<int> singleidx; 
        
        for (int i=0; i<s.length(); ++i) { 
			// if not present, then create entries. 
            if (idxcnt[s[i]-'a'].second == 0) { 
                singleidx.insert(i); 
                idxcnt[s[i]-'a'].first = i; 
            }
			// char is no longer unique, so remove it from singleidx set.
            else if (idxcnt[s[i]-'a'].second == 1) { 
                singleidx.erase(idxcnt[s[i]-'a'].first);
            }
            // increment count for char. 
            idxcnt[s[i]-'a'].second = idxcnt[s[i]-'a'].second+1; 
        }        
        
		// return the first index which char is unique. 
        return (singleidx.empty()) ? -1 : *singleidx.begin();
 }

int main()
{ 
	return 0; 
} 
