#include <iostream> 
#include <string> 
#include <stack> 
#include <vector> 

using namespace std; 

int longestValidParentheses(string s) 
{ 
	stack<int> st; 
    vector<bool> valid (s.length(), false); 

	if (s.length() == 0) {
		return 0; 
	} 

	for (int i=0; i<s.length(); ++i) { 
        char c = s[i];

		if (c == '(') { 
			st.push(i); 
		} 
		else { 
			if (!st.empty()) { 
                valid[st.top()] = true; 
                valid[i] = true;  
				st.pop(); 
			} 
		} 
	} 

    int cnt = 0, maxcnt = 0;  
    
    for (const auto c: valid) { 
       if (c) { 
          ++cnt; 
       }
       else { 
           if (cnt > maxcnt) { 
               maxcnt = cnt; 
           }
           cnt = 0; 
       }
    }

	return (cnt > maxcnt) ? cnt : maxcnt; 
} 

int main()
{ 
	cout << longestValidParentheses("(()") << endl; 
	cout << longestValidParentheses(")()())") << endl; 
	cout << longestValidParentheses(")") << endl; 
	cout << longestValidParentheses("") << endl; 
	cout << longestValidParentheses(")") << endl; 
	cout << longestValidParentheses("((()))") << endl; 
	cout << longestValidParentheses(")(()((") << endl; 
	cout << longestValidParentheses(")(()(()))))") << endl; 
	cout << longestValidParentheses("()(()") << endl; 
	return 0; 
} 					
	
