#include <iostream> 
#include <vector> 

using namespace std; 

void sort(vector<int>& nums) { 
    int len = nums.size();
    bool swapped = false; 

    do {
        swapped = false;

        for (int i=0; i<len-1; ++i) { 
            if (nums[i] > nums[i+1]) { 
                swap(nums[i], nums[i+1]);
                swapped = true; 
            }
        }

    } while (swapped); 
}

void write(ostream& os, vector<int>& nums) { 
    for (const auto& i: nums) { 
        os << i << " ";  
    }

    os << endl;
}
int main()
{
    vector<int> nums = {4,3,2,1};
    sort(nums);
    write(cout, nums);
    return 0;  
}
