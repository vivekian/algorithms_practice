#include <vector> 
#include <string> 

using namespace std; 

class Solution {
    private: 
    int num = 0; 

    void generate_helper(string sofar, int open, int close, vector<string>& res) { 
        // we generated all the open parenthesis, now time to close them.  
		if (open == num) { 
            for (int i=0; i<(num-close); ++i) { 
                sofar += ')';
            }
            res.push_back(sofar);
            return; 
        }
        else { 
			// there are always two choices to make - open and close. e.g. (( or ()     
            generate_helper(sofar+'(', open+1, close, res);
            
            if (close < open) { 
                generate_helper(sofar+')', open, close+1, res); 
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        num = n; 
        vector<string> res; 
        
        if (!n) { 
            res.push_back(""); 
        }
        else {         
            generate_helper("(", 1, 0, res);
        }
        return res; 
    }
};
