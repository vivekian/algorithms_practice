#include <map> 
#include <iostream> 
#include <vector> 

using namespace std; 

int getMaxAreaCurrIdx(vector<int>& height, int curr_idx) 
{ 
    int j=height.size() - 1; 
    int max_area_left = 0, max_area_right = 0; 

    while (j > curr_idx) { 
       if (height[j] >= height[curr_idx]) { 
            max_area_left = height[curr_idx] * (j - curr_idx); 
            break; 
        } 
        --j;
    } 

    j=0;

    while (j < curr_idx) { 
        
        if (height[j] >= height[curr_idx]) { 
            max_area_right = height[curr_idx] * (curr_idx-j); 
            break; 
        } 
        ++j; 
    } 

    return std::max(max_area_right, max_area_left); 
} 

int maxArea(vector<int>& height) {
   
   int max_area = 0; 

   if (height.size() == 1) 
   { 
       return height[0]; 
   } 

   for (int i=0; i<height.size(); ++i) { 
        int curr_area = getMaxAreaCurrIdx(height, i); 
        if (curr_area > max_area) { 
            max_area = curr_area; 
        } 
   } 

   return max_area; 
} 

int main() 
{
	vector<int> nums = {2, 3, 2, 1, 6, 1, 6, 2}; 
	cout << maxArea(nums) << endl;  
	return 0; 
} 
