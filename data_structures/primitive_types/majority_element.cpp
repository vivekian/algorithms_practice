#include <unordered_map> 
#include <vector> 
#include <iostream> 

using namespace std; 

int majorityElement(vector<int> items) 
{ 
    if (items.empty()) { 
        return 0; 
    } 

    unordered_map<int, int> freq_count; 
    auto half_length = items.size()/2; 
    int majority_element = 0; 

    for (const auto& item: items) { 
        freq_count[item]++; 

        if (freq_count[item] > half_length) { 
            majority_element = item; 
            break; 
        } 
    } 

    return majority_element; 
} 

int main()
{ 
    cout << majorityElement({2, 3, 5, 1, 2, 6, 2, 2, 2}) << endl; 
    cout << majorityElement({6}) << endl; 
    cout << majorityElement({}) << endl; 
    cout << majorityElement({2,2,2,2,2,4,5,6,7,8}) << endl; 
    return 0; 
} 
