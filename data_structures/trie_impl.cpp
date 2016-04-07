#include <iostream> 
#include <memory> 
#include <vector> 

using namespace std; 

class Trie 
{
    public:  
    Trie():words(0), prefixes(0)
    {
        for (int i=0; i<26; ++i) 
            edges.push_back(nullptr);
    }

    ~Trie() {} 

    void addWord(string word); 
    uint32_t countPrefixes(string prefix) const; 
    uint32_t countWords(string word) const; 

    private: 
        uint32_t words; 
        uint32_t prefixes; 
        vector<unique_ptr<Trie>> edges; 
}; 

void Trie::addWord(string word) 
{
    // if the word is empty then increment the word count  
    if (word.size() == 0) { 
        words++; 
    }
    else { 
        prefixes++; 
        char k = word[0]; 
        
        // create a new Trie object if one does not exist. 
        if (edges[k-'a'].get() == nullptr) { 
            edges[k-'a'].reset(new Trie());
        }
        
        // erase the first letter and recurse into the next vertex
        word.erase(0, 1); 
        edges[k-'a']->addWord(word); 
    }
}

uint32_t Trie::countWords(string word) const 
{ 
    char k = word[0]; 

    // if the word is empty, then query has been searched
    if (word.size() == 0) 
        return words; 
    else if (edges[k-'a'].get() == nullptr) { 
        return 0; 
    } 
    // remove the first char and recursively iterate again
    else { 
        word.erase(0, 1);  
        return edges[k-'a']->countWords(word); 
    }
}

uint32_t Trie::countPrefixes(string prefix) const 
{
   char k = prefix[0]; 
   
   if (prefix.size() == 0) 
       return words + prefixes; 
   else if (edges[k-'a'].get() == nullptr) { 
       return 0; 
   }
   else { 
       prefix.erase(0,1); 
       return edges[k-'a']->countPrefixes(prefix);
   }
}


int main() 
{ 
    Trie root; 
    
    root.addWord(string("the")); 
    root.addWord(string("them")); 
    root.addWord(string("their")); 
    root.addWord(string("then")); 

    cout << root.countWords(string("the")) << endl; 
    cout << root.countWords(string("them")) << endl; 
    cout << root.countPrefixes(string("the")) << endl; 

    return 0; 
}
