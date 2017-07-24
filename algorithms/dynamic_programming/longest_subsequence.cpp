#include <unordered_map>
#include <vector> 
#include <iostream> 

using namespace std; 

int lengthOfLIS(vector<int>& nums) {
        int len=nums.size(); 
        if (!len) {  
            return 0; 
        }
                
        unordered_map<int, int> lisidx;
        vector<int> liscnt(len, 1); 
        int global_max = 1; 
       
        // create a map of number to index mapping.  
        for (int i=0; i<len; ++i)
            lisidx[nums[i]] = i; 
        
        // sort the numbers. 
        sort(nums.begin(), nums.end()); 
       
        // start from highest number and move towards 0th element. 
        for (int i=len-1; i>=0; --i) { 
            // if there is a valid sequence - the index of i should 
            // be lower than j for valid subsequence, then get the 
            // correct max count. please notice how we have to compare
            // against every jth value because there is no way to know
            // if the jth value's index is higher or not. 
            for (int j=i+1; j<len; ++j) { 
                if (lisidx[nums[j]] > lisidx[nums[i]]) { 
                    liscnt[i] = max(liscnt[i], liscnt[j] + 1); 
                    global_max = max(global_max, liscnt[i]); 
                }
            }
        }
        
        return global_max; 
    }
