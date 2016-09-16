// this problem requires forming a dynamic programming table 
// to solve for 
#include <algorithm> 
#include <cstdio> 
#include <stdint.h>
#include <utility> 
#include <vector>

namespace { 
    using indexpair = std::pair<int32_t, int32_t>;
}

void kadane_solution(const std::vector<int32_t>& nums) 
{ 
    int max_at_index = 0; 
    int max_so_far = 0; 
    int sum = 0; 

    for (auto &x: nums) { 
        max_at_index = sum; 
        sum += x; 
        max_so_far = std::max(max_at_index, sum); 
    }

    printf("%d\n", max_so_far); 
}

indexpair solve_maximal_subarray(const std::vector<int32_t>& nums)
{ 
    if (nums.empty()) { 
        return std::make_pair<int32_t, int32_t>(0,0);
    } 

    int32_t dptable[nums.size()][nums.size()];

    for (int i=0; i<nums.size(); ++i) { 
        for (int j=0; j<nums.size(); ++j) { 
            dptable[i][j] = -1; 
        }
    }

    for (int i=0; i<nums.size(); ++i) { 
        dptable[i][i] = nums[i]; 
    }

    // solve dynamic programming table 
    for (int i=0; i<nums.size(); ++i) { 
        for (int j=i+1; j<nums.size(); ++j) { 
            dptable[i][j] = dptable[i][j-1] + nums[j]; 
        } 
    }

    indexpair indices = {0,0}; 
    int32_t maxvalue = dptable[0][0]; 

    for (int i=0; i<nums.size(); ++i) { 
        for (int j=i; j<nums.size(); ++j) { 
            if (dptable[i][j] > maxvalue) { 
                maxvalue = dptable[i][j];
                indices = {i,j}; 
            }      
        }
    } 
    printf("%d\n", maxvalue); 
    return indices;  
} 

int main()
{
    std::vector<int32_t> nums = { 10, -15, -10, 8, 24, -2 };
    std::pair<uint32_t, uint32_t> mypair = solve_maximal_subarray(nums);   
    printf("maximal indices are %u and %u\n", mypair.first, mypair.second);
    kadane_solution(nums); 
    return 0; 
} 
