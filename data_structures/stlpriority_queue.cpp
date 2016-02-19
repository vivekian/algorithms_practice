// example showing the usage of the stl priority queue 
#include <queue> 
#include <vector> 
#include <iostream> 
#include <cassert> 

using namespace std; 

int main() 
{ 
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
