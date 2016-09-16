// enumerate all subsets of a specific size k for input n where n forms the set {1,2,...n}.
// return a vector of subsets. 

// for further description of the problem look at 16.6 in elements of programming interviews.

#include <deque>
#include <iostream> 
#include <vector>

void PrintQueue(const std::deque<int>& Q)
{ 
    for (auto& x: Q) { 
        std::cout << x << " "; 
    } 

    std::cout << std::endl; 
}

void SubsetsKSize(std::deque<int> sofar, std::deque<int> rest, const int k, std::vector<std::deque<int>>& V) 
{ 
    if (sofar.size() == k) { 
        V.push_back(sofar); 
        return; 
    }

    if (rest.empty()) 
        return; 

    std::deque<int> next = sofar; 
    next.push_back(rest.front());
    rest.pop_front(); 

    SubsetsKSize(next, rest, k, V);
    SubsetsKSize(sofar, rest, k, V);
} 

void ListSubsets(const int n, const int k) 
{ 
    // the reason to use deque here is that it offers a pop_front() method which vector does not. 
    std::deque<int> sofar; 
    std::deque<int> rest;
    std::vector<std::deque<int>> V; 

    sofar.clear();

    for (int i=1; i<=n; ++i) 
        rest.push_back(i);

    SubsetsKSize(sofar, rest, k, V);

    for (auto& v: V) { 
        PrintQueue(v); 
    }

}

int main() 
{
    ListSubsets(5, 2); 
    return 0; 
}
