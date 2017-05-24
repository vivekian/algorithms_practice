/* Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/ 

#include <limits> 
#include <string> 
#include <vector> 
#include <iostream> 

using namespace std; 

struct Range { 
    int lo;
    int hi; 

    Range(int l, int h): lo(l), hi(h) {}

    string toString() { 
        if (hi == lo) { 
            return to_string(hi); 
        } 
        else { 
            return to_string(lo) + "->" + to_string(hi); 
        } 
    }
};

vector<string> findMissingRanges(const vector<int>& nums, int lower, int upper) {
	vector<string> res;
    vector<Range> ranges; 

    if (nums.empty()) {
        ranges.emplace_back(Range(lower, upper));  
    } 
    else {  
        // no subtraction here - instead do a comparison to avoid addition overflow. 
        if (nums[0] != lower) { 
            ranges.emplace_back(Range(lower, nums[0]-1)); 
        } 
        
        for (int i=0; i<nums.size()-1; ++i) { 
            if ((nums[i] != nums[i+1]) && (nums[i+1] > (nums[i] + 1))) { 
                ranges.emplace_back(Range(nums[i]+1, nums[i+1]-1)); 
             } 
        } 

        if (upper != nums[nums.size()-1]) { 
            ranges.emplace_back(Range(nums[nums.size()-1]+1, upper)); 
        } 
    } 

    for (auto& r: ranges) { 
        res.emplace_back(r.toString()); 
    } 
		  
	return res; 
}

void print(ostream& os, vector<string>& res) { 

    for (auto& s: res) {
        os << s << ",";
    } 

    os << endl; 
}

struct test { 
    vector<int> nums; 
    int lower; 
    int upper; 
    vector<string> res; 
}; 

namespace { 
    vector<test> tests = { 
        { {0, 1, 3, 50, 75}, 0, 99, { "2", "4->49", "51->74", "76->99" }},
        { {}, 0, 99, {"0->99"}},
        { {}, 0, 0, {"0"}},
        { {}, 0, 0, {"0"}},
        { {}, std::numeric_limits<int>::lowest(), numeric_limits<int>::max(), {"-2147483648->2147483647"}},
        { {0}, std::numeric_limits<int>::lowest(), numeric_limits<int>::max(), {"-2147483648->-1","1->2147483647"}},
        { {-1}, std::numeric_limits<int>::lowest(), 0, {"-2147483648->-2","0"}},
        { {-2147483648,2147483647}, std::numeric_limits<int>::lowest(), numeric_limits<int>::max(), {"-2147483647->2147483646"}},
    }; 
} 

int main() 
{ 
    for (const auto& t: tests) { 
        auto res = findMissingRanges(t.nums, t.lower, t.upper); 
    
        if (res == t.res) { 
            cout << "Passed\n"; 
        }     
        else { 
            cerr << "Failed\n"; 
            print(cout, res); 
        } 
    }

    return 0; 
} 
