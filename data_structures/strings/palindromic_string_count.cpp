inline bool ispalindrome(string str) { 
        int i=0; 
        int j=str.length()-1; 
        
        while (i<j) { 
            if (str[i] != str[j]) { 
                return false; 
            }
            ++i; 
            --j; 
        }
        
        return true;
    }    
    
    int countSubstrings(string s) {
        int cnt = 0; 
        
        for (int i=0; i<s.length(); ++i) { 
            for (int j=i ; j<s.length(); ++j) { 
                cnt += ispalindrome(s.substr(i, j-i+1)); 
            }
        }
        
        return cnt; 
    }
