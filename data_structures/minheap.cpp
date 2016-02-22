// A fairly simple implementation which assumes int data type, with only 
// positive elements to be stored.  

#include <iostream> 
using namespace std; 

// Maximum size of the priority queue 
static const int MAX_SIZE = 100; 

class PriorityQueue { 
public: 
    PriorityQueue():n(0)                // empty queue 
    {}

    ~PriorityQueue() {}

    void insert(const int x) 
    { 
        if (n >= MAX_SIZE)               
            return; 
        else { 
            ++n; 
            q[n] = x;
            bubble_up(n);               // element should be in the correct place
        }
    }

    int extract_min() 
    {
        if (n == 0) 
           return -1; 

        int min = q[1];                 // remove the top of the heap and move nth position  
        q[1] = q[n];                    // element at the root. 
        --n; 
        
        bubble_down(1);                 // now bubble down to maintain the heap property
        return min; 
    }


    void print() 
    { 
        for (int i=1; i<=n; ++i) 
            cout << q[i] << " "; 
        cout << endl; 
    }

private: 
    int parent(const int child) 
    { 
        // reached the root of the tree, return -1
        if (child == 1) 
            return -1;
        else 
            return static_cast<int>(child/2); 
    }

    int child(const int parent) 
    { 
        return static_cast<int>(parent * 2); 
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

    // compare parent with both children and swap with the smaller child.
    // then recursively call bubble_down with the child index. 
    void bubble_down(int p) 
    { 
        int c = child(p); 
        int min_idx = p; 

        if ((c <= n) && q[min_idx] > q[c])
            min_idx = c; 

        if ((c+1 <= n) && q[min_idx] > q[c+1])
            min_idx = c+1; 

        if (min_idx != p) { 
            swap(p, min_idx);
            bubble_down(min_idx); 
        }
    }


    int n;                  // n is the current size of the heap/priority queue  
    int q[MAX_SIZE];        // int array to hold elements
};


int main() 
{
    PriorityQueue pq; 

    for (auto x: {10, 56, 6, 7, 22, 33, 1}) 
        pq.insert(x); 

    pq.print(); 

    int item; 

    do { 
        item = pq.extract_min(); 
        pq.print(); 
    } while(item != -1); 

    return 0; 
}
