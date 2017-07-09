ass Solution {
private: 
	// given a start index e, find the next point where to stop 
    inline int findnextelevation(int e, vector<int>& height) {  
		
		/* start from the next bar and make sure that if its bigger
		   than just stop and return -1 because no water can be trapped */ 
        int curr = e+1; 
        
        if (height[curr] >= height[e]) { 
            return -1; 
        }
        
		/* there are two scenarios: 
			- find a bar which is equal to start bar or greater than start bar
			- find the bar which is the greatest height less than start bar 
			- mad_idx tracks the second case while curr tracks the first case */ 
        int max_idx = curr; 
        
		/* continue iterating till we find a bar which is greater than or equal to 
		   start bar height. record max_idx in case curr reaches end of array */ 
        while (curr < height.size() && height[curr] < height[e])  { 
            
            if (height[curr] > height[max_idx]) { 
                max_idx = curr; 
            }
            
            ++curr; 
        }
        
		// reached end of array and max_idx never changed 
		// this implies a downward slope from start to end, so return -1 since no water
		// can be stored. 
        if (curr == height.size()) {
            return (max_idx == curr) ? -1 : max_idx; 
        }
        else {
            return curr; 
        }
    }
    
    inline int compute_sum(int e, int m, vector<int>& height) { 
        int sum = 0;
		
		// take min height between start and end point, since 
		// water storage is limited to the min of these two  
        int min_height = min(height[e], height[m]);
        
        for (int i=e+1; i<m; ++i) { 
            sum += min_height - height[i];
        }
        
        return sum; 
    }
    
public:
	// time complexity in worst case is O(n^2) because if its a completely 
	// downward slope we will end up iterating the entire array for each point.

	// idea is: for each point in the array, set it as start point, then iterate
	// array till next point is found where to stop. If a point is found, then 
	// compute sum and continue from the ending point. if no such point is found, 
	// then increment by 1 and continue on the next point. 
    int trap(vector<int>& height) {
        int e = 0; 
        const int len = height.size();
        int sum = 0; 
        
        while (e < len-1) { 
			// skip if bar height is 0 as it can't be a starting point.
            if (height[e] == 0) { 
                ++e; 
                continue; 
            }
           
			// find if there is a bar where water will be trapped. 
            auto nxt = findnextelevation(e, height);
            
			// if no such point exists, start again from the next bar. 
            if (nxt == -1){ 
                ++e; 
                continue; 
            }
            
			// point does exist then compute the sum between start and end point
			// to get the water stored. 
            sum += compute_sum(e, nxt, height); 
			
			// now start again from the end point of the previous sum iteration. 
            e = nxt; 
        }
        
        return sum; 
    }
};
