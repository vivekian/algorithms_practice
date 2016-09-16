#include <algorithm> 
#include <cassert>
#include <cstdio>
#include <numeric> 
#include <random>
#include <vector>

std::vector<uint32_t> gen_random_items(const uint32_t num_items, const uint32_t max_weight)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<uint32_t> dist(10, max_weight - 10);
    std::vector<uint32_t> rnd_items; 

    for (uint32_t i = 0; i < num_items; ++i) { 
        rnd_items.push_back(dist(mt));
    }

    return rnd_items;
}

// the first fit algorithm sorts the items in non-decreasing order 
// then pack items in the bins as they come along. 
auto first_fit(std::vector<uint32_t> items, const uint32_t capacity)
{ 
    assert(items.size());
    assert(capacity);

    std::sort(items.begin(), items.end(), 
              [](const auto A, const auto B) { return A > B; });

    std::vector<uint32_t> bins(0);
    bins.push_back(0);
    uint32_t index = 0; 

    // open a new bin if the current bin is not big enough
    for (const auto& item: items) { 
        if ((bins[index] + item) > capacity) { 
            bins.push_back(0);
            index++;
        } 
        bins[index] += item; 
    }

    return bins.size();
} 

bool validate_solution(const uint32_t total_weight, const uint32_t num_bins)
{ 
    return (total_weight > ((num_bins - 1)/2 * 100));
}

void solve_bin_packing(const std::vector<uint32_t> &items)
{ 
    uint32_t total_weight = std::accumulate(items.begin(), items.end(), 0);
    uint32_t num_bins = first_fit(items, 100); 

    printf("weight: %4u, num_bins: %3u, valid: %s\n", total_weight, num_bins, 
           validate_solution(total_weight, num_bins)?"true":"false"); 
}


int main()
{
    std::vector<uint32_t> num_items = {20, 30, 10, 40, 50, 22}; 
    
    for (auto x: num_items) {  
        solve_bin_packing(gen_random_items(x, 100));
    }

    return 0;
}  
