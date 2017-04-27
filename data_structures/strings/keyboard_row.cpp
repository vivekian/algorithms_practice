/* solution to problem 500 on leetcode (keyboard row) */ 

#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

namespace { 
	string rows[] = { "qwertyuiop",
					  "asdfghjkl",
					  "zxcvbnm" };
}; 

inline int get_bucket(const char c) 
{ 
	for (int i=0; i<3; ++i) { 
		if (rows[i].find(c) != string::npos) { 
			return i; 
		}
	}
	
	return -1; 
}

vector<string> findWords(vector<string>& words) {
	vector<string> res; 

	for (const auto& word: words) { 
		int prev_bucket = get_bucket(tolower(word[0]));
		int curr_bucket = prev_bucket; 

		for (auto c: word) { 
			curr_bucket = get_bucket(tolower(c));		
			
			if (prev_bucket != curr_bucket) { 
				break; 
			} 

            prev_bucket = curr_bucket; 
		} 
		
        if (prev_bucket == curr_bucket) { 
            res.emplace_back(word); 
        }
	} 

	return res;         
}

int main() 
{
	vector<string> input = {"alaska", "hello", "dad", "peace"};
	auto res = findWords(input);

	for (auto r: res) { 
		cout << r << endl; 
	} 

	return 0; 
}
