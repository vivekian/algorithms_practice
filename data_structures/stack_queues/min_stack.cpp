/* 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack. 

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2. */

#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std; 

class MinStack {
    private: 
        vector<int> _stack;
        int _idx = -1; 
        priority_queue<int, std::vector<int>, std::greater<int>> pq; 
public:
   /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
       _stack.emplace_back(x); 
       ++_idx;
       pq.push(x);  
    }
    
    void pop() {
        if (!_stack.empty()) {
            if (pq.top() == _stack.back()) { 
               pq.pop();
            }

            _stack.pop_back();
            _idx--; 
        }
    }
    
    int top() {
        if (!_stack.empty()) { 
            return _stack.back();   
        } 

        return 0; 
    }
    
    int getMin() {
       return pq.top(); 
    }
};

int main()
{ 
    MinStack ms; 
    ms.push(3); 
    cout << ms.top() << " " << ms.getMin() << endl; 
    ms.push(2); 
    ms.push(4); 
    ms.pop();
    cout << ms.top() << " " << ms.getMin() << endl; 
    ms.pop(); 
    cout << ms.top() << " " << ms.getMin() << endl; 
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */ 

