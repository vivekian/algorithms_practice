#include <iostream> 
#include <vector> 

using namespace std; 

bool isPalindrome(int x) {
        
        if (x < 0) { 
            return false; 
        } 
        
        vector<int> vec; 
        
        while (x) { 
            vec.push_back(x%10); 
            x /= 10; 
        } 
        
        int i = vec.size()-1; 
        int j = 0; 
        
        while (i >= j) { 
            if (vec[i] != vec[j]) { 
                return false; 
            }
            i--; 
            j++; 
        }
                
        return true; 
}

int main()
{ 
	cout << isPalindrome(121) << endl;
	return 0; 
} 
