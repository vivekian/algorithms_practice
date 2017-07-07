class Vector2D {
private: 
    vector<vector<int>> vec; 
    int rows = 0; 
    int r = 0; 
    int c = 0; 

public:
    Vector2D(vector<vector<int>>& vec2d) {
        vec = vec2d; 
        rows = vec2d.size(); 
    }

    int next() {
        int res = vec[r][c];
       
		// if row has been traversed, then jump to next row
		// otherwise just increment column.  
        if (c == vec[r].size()-1) { 
            c = 0; 
            ++r; 
        }
        else { 
            ++c; 
        }
        
        return res; 
    }

    bool hasNext() {
	   // keep iterating through rows to make sure you skip over 
	   // empty rows.  
       while (r < rows) { 
            if (c < vec[r].size()) { 
                return true; 
            }
            
            c = 0; 
            ++r; 
        }
        
        return false; 
    }
};
