class Solution {
private: 
    struct range { 
        int lo; 
        int hi; 
        
        string to_string() { 
            return (lo == hi) ? std::to_string(lo): 
                                std::to_string(lo) + "->" + std::to_string(hi);
        }
        
        range (int l, int h): lo(l), hi(h) {}
    }; 
    
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res; 
        int len=nums.size(); 
        
        if (!len) { 
            return res;  
        }
        
        int start = nums[0];
        
        for (int i=1; i<len; ++i) { 
            if (nums[i] - nums[i-1] != 1) { 
                range r(start, nums[i-1]); 
                res.emplace_back(r.to_string());  
                start = nums[i]; 
            }
        }
        
        range r(start, nums[len-1]); 
        res.emplace_back(r.to_string());
        
        return res; 
    }
};
