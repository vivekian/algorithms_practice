#include <numeric> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

// this problem is explained at https://leetcode.com/problems/zigzag-conversion/ where it 
// requires the string to be printed in zig zag formation. 

class Solution {
private: 
    int getNextRow(int currRow, int numRows, bool& isDown)
    { 
        if (isDown) { 
            if (currRow < numRows-1) { 
                ++currRow; 
            } 
            else { 
                --currRow;
                isDown = false; 
            } 
        } 
        else { 
            if (currRow > 0) { 
                --currRow; 
            } 
            else { 
                ++currRow; 
                isDown = true; 
            } 
        } 
        
        return currRow; 
    } 
    
public:
    string convert(string s, int numRows) {
        
        vector<string> rowchars(numRows); 
        int currRow = 0; 
        bool isDown = true; 
        
        if (numRows == 1) { 
            return s; 
        } 
        
        for (int i=0; i<s.size(); ++i) {
            rowchars[currRow] += s[i]; 
            currRow = getNextRow(currRow, numRows, isDown); 
        }
        
        return std::accumulate(rowchars.begin(), rowchars.end(), string("")); 
    }
};

int main() 
{
	Solution s; 
	cout << s.convert ("PAYPALISHIRING", 3) << endl; 
	return 0; 
} 
