class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        
        if (!n || n==1) { 
            return 0;
        }
        
        int max_profit = 0; 
        
        // start from the last price assuming its the most expensive stock. 
        int max_price = prices[n-1]; 
        vector<int> mp(n); 
        
        // there can't be any profit if you buy and sell on last day. 
        mp[n-1] = 0; 
        
        for (int i=n-2; i>=0; --i) { 
            // either the max profit is already found, or 
            // its computed using the ith entry 
            mp[i] = max(mp[i+1], max_price - prices[i]); 
            
            // if currenty price is the biggest, then update it
            // so all entries before i can use it. 
            if (prices[i] > max_price) { 
                max_price = prices[i]; 
            }
            
            if (mp[i] > max_profit) { 
                max_profit = mp[i];
            }
        }
        
        return max_profit; 
    }
};
