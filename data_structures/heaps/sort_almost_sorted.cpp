#include <iostream> 
#include <vector>
#include <queue> 

using std::vector; 
using std::priority_queue; 
using std::cout; 
using std::endl; 

// sort an almost sorted array where each element is no more than k elements away 
// from its correctly sorted position. 
//
// use a priority queue and push in the first k elements. now start popping one element
// which is the min and insert it into the new array. as you pop off one element, insert
// a new element from the original array to the priority queue. once all elements are 
// exhausted from the original array, then pop off all the remaining elements from the 
// priority queue. 
// 
// time complexity On(lg k) where every remove is O(lg K) and we iterate n items. 

vector<uint32_t> sort_almost_sorted(const vector<uint32_t> & nums, const int k) 
{ 
    // implement a min pq. 
    priority_queue<uint32_t, vector<uint32_t>, std::greater<uint32_t>> pq; 
    vector<uint32_t> sorted_array; 
  
    for (auto i=0; i<k; ++i) { 
        pq.emplace(nums[i]); 
    } 

    for (auto i=k; i<nums.size(); ++i) { 
        sorted_array.push_back(pq.top()); 
        pq.pop(); 
        pq.emplace(nums[i]); 
    }

    while (!pq.empty()) { 
        sorted_array.push_back(pq.top()); 
        pq.pop(); 
    } 

    return sorted_array; 
} 

int main() 
{ 
    vector<uint32_t> input = {2,4,3,2,5,9,7,8}; 
    auto sorted_array = sort_almost_sorted(input, 3); 

    for (const auto& x: sorted_array) { 
        cout << x << endl; 
    } 

    return 0; 
} 
