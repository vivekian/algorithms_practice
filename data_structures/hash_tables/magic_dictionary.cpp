#include <vector> 
#include <string> 
#include <unordered_map> 
#include <iostream> 

using namespace std; 

class MagicDictionary {

private: 
	unordered_map<int, vector<string>> md; 
	
	int diff_strs(string s1, string s2) { 
		int len = s1.length(); 
		int diff = 0; 

		for (int i=0; i<len; ++i) { 
			if (s1[i] != s2[i]) { 
				++diff; 
			} 
		}

		return diff; 
	}

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
    	for (string s: dict) { 
			md[s.length()].emplace_back(s); 
		}    
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
    	int len = word.size(); 
		
		if (md.count(len) == 0) { 
			return false; 
		} 
		
		for (string s: md[len]) { 
			if (1 == diff_strs(s, word)) { 
				return true; 
			} 	
		} 

		return false;     
    }
};


int main()
{
   return 0;  
}
