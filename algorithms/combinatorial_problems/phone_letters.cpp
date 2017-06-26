#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

namespace { 
   vector<string> lettermap = {
       "", 
       "", 
       "abc", 
       "def",
       "ghi",
       "jkl",
       "mno", 
       "pqrs",
       "tuv",
       "xyz"
   }; 
}

void letter_helper(vector<string>& res, string sofar, string rest) { 
	if (rest.empty()) { 
		res.push_back(sofar); 
	} 
	else {
		string letters = lettermap[rest[0]-'0']; 
		string next = rest.substr(1); 		

		for (const char c: letters) { 
			letter_helper(res, sofar + c, next);  
		} 
	} 
} 

vector<string> letterCombinations(string digits) {
	vector<string> res = {}; 
    
    if (digits.empty()) { 
        return res; 
    } 
    
    letter_helper(res, "", digits);         
	return res; 
}

void print(ostream& os, vector<string>& res) { 
	for (const auto& r: res) { 
		os << r << endl; 
	} 
} 

int main()
{
	auto res = letterCombinations("0");  
	print(cout, res); 
    return 0; 
} 
