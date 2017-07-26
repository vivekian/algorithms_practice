#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <unordered_map> 

using namespace std; 

class WordDistance {
private: 
	unordered_map<string, vector<int>> pos;  
	int len=0; 

public:
    WordDistance(vector<string> words) {
		len = words.size(); 
		
		for (int i=0; i<len; ++i) { 
			pos[words[i]].push_back(i); 
		}
    }
    
    int shortest(string word1, string word2) {
      	auto &v1 = pos[word1]; 
		auto &v2 = pos[word2];
		int min_diff = len; 

		for (int i=0; i<v1.size(); ++i) { 
			for (int j=0; j<v2.size(); ++j) { 
				int diff = abs(v1[i] - v2[j]); 
				
				if (diff < min_diff) { 
					min_diff = diff; 
				} 
			} 
		}

		return min_diff;   
    }
};

int main()
{ 
	vector<string> words = {"a","b","c","d","e","a"}; 
	WordDistance wd(words); 
	cout << wd.shortest("a", "d") << endl; 
	return 0; 
} 
