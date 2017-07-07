#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

class Trie {
private:
	 const int NUM_LETTERS = 26;  
     vector<Trie*> children; 
	 bool isword; 
public:
    /** Initialize your data structure here. */
    Trie() {
		children.resize(NUM_LETTERS); 
		fill(children.begin(), children.end(), nullptr); 
		isword = false; 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	if (word.empty()) {
			isword = true;  
			return; 
		} 

		if (children[word[0]-'a'] == nullptr) { 
			children[word[0]-'a'] = new Trie(); 
		}
 
	    children[word[0]-'a']->insert(word.substr(1)); 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       if (word.empty()) { 
			return isword; 
		} 
		
		auto idx = word[0]-'a';
		
		if (children[idx]) { 
			return children[idx]->search(word.substr(1)); 
		} 
	
		return false; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
    	if (prefix.empty()) { 
			return true;  
		} 
		
		auto idx = prefix[0] - 'a';
		if (children[idx]) { 
			return children[idx]->startsWith(prefix.substr(1)); 
		} 

		return false; 
    }
};

int main()
{ 
	Trie trie; 
	
	trie.insert("alphabet"); 
	trie.insert("alpha"); 
	trie.insert("alphaprune");

	cout << trie.search("alpha") << endl;  
	cout << trie.search("alphabeta") << endl;  
	cout << trie.search("") << endl;  
	cout << trie.startsWith("alp") << endl;  
	cout << trie.startsWith("alpp") << endl;  
	cout << trie.startsWith("alphabet") << endl;  
	cout << trie.startsWith("alphabetz") << endl;  

	return 0; 
}
