#include <iostream> 
using namespace std; 

static const int MAX_SIZE = 100; 

class PriorityQueue { 
public: 
    PriorityQueue():n(0)
    {}

    ~PriorityQueue() {}

    int parent(const int child) 
    { 
        // reached the root of the tree, return -1
        if (child == 1) 
            return -1;
        else 
            return static_cast<int>(child/2); 
    }

    void swap(int a, int b) 
    { 
        int tmp = q[a]; 
        q[a] = q[b]; 
        q[b] = tmp; 
    }

    // keep recursing till the heap is ordered to the parent
    void bubble_up(int p) 
    { 
        if (parent(p) == -1) 
            return; 

        if (q[parent(p)] > q[p]) { 
            swap(parent(p), p); 
            bubble_up(parent(p)); 
         }
    }

    void insert(const int x) 
    { 
        if (n >= MAX_SIZE) 
            return; 
        else { 
            n++; 
            q[n] = x;
            bubble_up(n);  
        }
    }

    int getmin() 
    { 
        return q[1]; 
    }

    void print() 
    { 
        for (int i=1; i<=n; ++i) 
            cout << q[i] << " "; 
        cout << endl; 
    }

private: 
    int n; 
    int q[MAX_SIZE];
};


int main() 
{
    PriorityQueue pq; 

    for (auto x: {10, 56, 6, 7, 22, 33, 1}) 
        pq.insert(x); 

    pq.print(); 

    return 0; 
}
