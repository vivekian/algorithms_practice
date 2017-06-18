#include <iostream> 
#include <algorithm> 
#include <string> 
#include <vector> 
#include <cstdlib> 
#include <limits> 

using namespace std; 

int maxDistance(vector<vector<int>>& arrays) {

    vector<pair<int,int>> min_items; 
    vector<pair<int,int>> max_items; 

    for (int i=0; i<arrays.size(); ++i) { 
        auto min_item = min_element(arrays[i].begin(), arrays[i].end()); 
        auto max_item = max_element(arrays[i].begin(), arrays[i].end()); 

        min_items.push_back({i, *min_item}); 
        max_items.push_back({i, *max_item}); 
    }  

    int max_dist = 0; 

    auto cmp = [] (pair<int,int>& a, pair<int,int>& b) { return a.second < b.second; }; 

    sort(min_items.begin(), min_items.end(), cmp); 
    sort(max_items.begin(), max_items.end(), cmp); 
   
    for (int i=0, j=max_items.size()-1; i<min_items.size() && j>=0;) { 
        if (min_items[i].first != max_items[j].first) { 
            return abs(max_items[j].second - min_items[i].second); 
        } 
        
        if (abs(min_items[i].second - max_items[j-1].second) > 
            abs(min_items[i+1].second - max_items[j].second)) {
                --j; 
        }
        else { 
                ++i; 
        }  
    } 

    return 0; 
}

int main()
{
   vector<vector<int>> in = 
		{{1,2,3},
		 {4,5},
 		 {1,2,3}}; 

	cout << maxDistance(in) << endl; 
	
	in = {{1},{1}}; 
	cout << maxDistance(in) << endl; 


	in = {{-1,-2,-3},{-1,-2,-3}}; 
	cout << maxDistance(in) << endl; 
    return 0; 
    }
