#include <unordered_set> 
#include <iostream> 
#include <queue> 
#include <string> 
#include <unordered_map> 

using namespace std; 

struct Node { 
    string word; 
    int depth; 

    Node(string w, int d): word(w), depth(d) { }
}; 

inline bool word_compare(const string& a, const string& b) 
{ 
	int cnt = 0; 

	for (int i=0; i<a.length(); ++i) { 
		if (a[i] != b[i]) { 
			++cnt;
            if (cnt > 1) { 
               return false; 
            } 
		} 
	} 

	return true;
} 		

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	// queue is used to do BFS 
 	queue<Node*> q;
	// once a word has been used it is removed from the dict (aka visited) 
	unordered_set<string> dict;
	auto di = dict.begin();
	copy(wordList.begin(), wordList.end(), inserter(dict, di));
	q.push(new Node({beginWord, 1}));

	while (!q.empty()) {
			const auto node = q.front();
			q.pop();
			
			// compare against all the words and push nodes which only 
			// differ by 1 char to the queue. 
			for (di = dict.begin(); di != dict.end(); ) {
				if (word_compare(*di, node->word)) { 
					if (*di == endWord) { 
						return node->depth+1; 
					}
					
					q.push(new Node({*di, node->depth+1}));
					
					// erase the word and setup di correctly
					di = dict.erase(di);
				}
				else { 
					++di; 
				} 
			}
	}

  	return 0;     
}

int main() 
{ 
	vector<string> wordlist = {"hot","dot","dog","lot","log","cog"}; 
	string start = "hit"; 
	string last = "cog";
	
	cout << ladderLength(start, last, wordlist) << endl; 

	return 0; 
} 
