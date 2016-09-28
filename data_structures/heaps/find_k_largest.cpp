#include <iostream> 
#include <queue> 
#include <vector> 
#include <functional> 

using namespace std; 

// find the kth largest element in an array. 
// we use a priority queue and store the first k elements of the array
// in it. as we iterate the rest of the array, we compare with the min
// element. if the item is greater, we remove the top and and push the 
// item. This way we maintain the k largest elements in the array. 
// in the end we just need the topmost element in the pq as the kth 
// largest element since its a min priority queue. 
int find_k_largest(vector<int>& items, int k) 
{ 
    if (items.empty()) { 
        return 0; 
    } 

    if (k < 1 || k > items.size()) { 
        return 0; 
    } 

    priority_queue<int, vector<int>, std::greater<int>> pq; 

    for (auto i: items) { 
        
        if (pq.size() < k) { 
            pq.push(i); 
        } 
        else { 
            if (i > pq.top()) { 
                pq.pop(); 
                pq.push(i); 
            } 
        } 
    } 
   
    return pq.top(); 
} 

int main()
{ 
    vector<int> items = {2, 5, 1, -1, 7, 11, 14, 0, 46}; 
    cout << find_k_largest(items, 2) << endl; 
    return 0; 
} 
