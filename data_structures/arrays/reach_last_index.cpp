// This is the solution to the problem 6.4 of EPI (ELements of Programming Interviews) 
// which tries to determine if the last index of an array can be reached by jumping upto
// a[i] positions from index i. 

#include <iostream> 
#include <vector> 

using namespace std; 

bool reach_last_index(const vector<int>& items, int curr_idx) 
{
    // reached the last index, success.  
    if (items.size()-1 == curr_idx) { 
        return true; 
    } 

    // value is 0, can't proceed further. 
    if (items[curr_idx] == 0) { 
        return false; 
    } 

    // iterate from 1 to the value of the item, till success. 
    for (int i=1; i<=items[curr_idx]; ++i) { 

        if (reach_last_index(items, curr_idx+i)) { 
            return true; 
        } 
    } 

    // tried all possibilities, but no success. 
    return false; 
} 

bool solve_last_index_reached(const vector<int>& items) 
{ 
    return reach_last_index(items, 0); 
} 

int main() 
{ 
    vector<int> testcase1 = {3,3,1,0,2,0,1}; 
    cout << solve_last_index_reached(testcase1) << endl; 
    return 0; 
} 
