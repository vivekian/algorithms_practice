#include <iostream> 
#include <vector> 

using namespace std; 

void moveZeroes(vector<int>& nums) 
{ 
    int reader=0, writer=0; 

    while (reader < nums.size()) { 

        if (nums[reader] != 0) {
            nums[writer] = nums[reader]; 
            ++writer; 
        } 

        ++reader; 
    }

    while (writer < nums.size()) { 
        nums[writer] = 0; 
        ++writer; 
    } 
}

void print(ostream& out, vector<int>& nums) 
{ 
    for (const auto num: nums) { 
        out << num << ",";
    }

    out << endl; 
}

int main() 
{
    vector<int> nums = {0,0,0,1,2,3}; 
    moveZeroes(nums); 
    print(cout, nums); 
    
    nums = {0,1,0,2,0,3}; 
    moveZeroes(nums); 
    print(cout, nums); 

    nums = {0}; 
    moveZeroes(nums); 
    print(cout, nums); 
    
    nums = {1,2,3,0,0,0}; 
    moveZeroes(nums); 
    print(cout, nums); 



    return 0; 
}
