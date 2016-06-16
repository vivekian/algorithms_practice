// the idea is to classify all the anagrams in the english dictionary language. 
// use a hashmap to store all the words but sorted alphabetically. then as you find 
// a matching entry to the sorted word, add the word to the vector list.

#include <algorithm> 
#include <cassert>
#include <fstream>
#include <iostream> 
#include <sys/stat.h> 
#include <unordered_map> 
#include <string> 
#include <vector> 

using namespace std; 

namespace { 
    const string DICT_NAME = "/usr/share/dict/words"; 

    // fastest way to check if a file exists or not
    bool fileExists(const char *filename) 
    { 
        struct stat buffer; 
        return (stat(filename, &buffer) == 0); 
    }
}
    
class AnagramMap 
{ 
    public: 
        AnagramMap(const char *filename); 
        ~AnagramMap() {} 

        // notice how in C++11 due to rvalue refs we are able to get 
        // the vector<string> returned and its not inefficient.
        vector<string> getAnagrams(string word); 
    
    private: 
        void addEntry(string word); 
        // this is the closest to hashmap/hashtable in C++11. 
        unordered_map<string, vector<string>> m_Map; 
}; 

vector<string> AnagramMap::getAnagrams(string word) 
{ 
    sort(word.begin(), word.end()); 
    auto iter = m_Map.find(word);

    if (iter == m_Map.end())  
        return vector<string>(); 
    else 
        return iter->second; 
}

void AnagramMap::addEntry(string word) 
{
    if (word.empty()) 
       return; 

    string unsorted_word(word); 
    sort(word.begin(), word.end()); 
    m_Map[word].push_back(unsorted_word); 
}

AnagramMap::AnagramMap(const char *filename)
{
   if (!fileExists(filename)) 
      throw string("dictionary does not exist"); 

   ifstream infile(filename); 
   string word; 

   while (infile >> word) { 
       transform(word.begin(), word.end(), word.begin(), ::tolower); 
        
       if (word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == string::npos) { 
            addEntry(word); 
       }
   }
}

int main(int argc, char *argv[]) 
{ 
    if (!argv[1]) { 
        cerr << "specify input word" << endl;
        return -1; 
    }

    string inputword(argv[1]);  
    AnagramMap amap(DICT_NAME.c_str()); 
    
    auto listwords = amap.getAnagrams(inputword); 

    if (listwords.empty()) 
        cout << "no anagram words found" << endl; 
    else { 
        for (const auto& word: listwords) { 
            cout << word << endl; 
        }
    }

    return 0; 
} 
