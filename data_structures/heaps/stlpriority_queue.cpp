// example showing the usage of the stl priority queue 
#include <queue> 
#include <vector> 
#include <iostream> 
#include <cassert> 

using namespace std; 


int main() 
{ 
    // by default, the priority_queue implements std::less which means is a max queue. 
    // to implement a min queue for integers, use std::greater<int> or implement comporator func. 
    // if doing the latter, specify the decltype, and then the lambda name as a parameter to the object. 
    priority_queue<int, vector<int>> pq; 
   
    for (int n: {5, 3, 10, 22, 7, 9}) { 
        pq.push(n); 
    }


    assert(22 == pq.top());
    pq.pop(); 
    assert(10 == pq.top());  
    pq.push(11); 
    assert(11 == pq.top());  
    
    return 0; 
} 
