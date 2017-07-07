#include <iostream> 
using namespace std; 

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
private: 
	int peek_idx = 0; 
	int next_idx = 0; 
	int peek_item = 0; 
    bool has_next = false; 

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

// Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (peek_idx <= next_idx) {
            peek_idx = next_idx + 1;
            has_next = Iterator::hasNext(); 
            
            if (has_next) { 
                peek_item = Iterator::next();
            }
        }
        
        return peek_item;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int res =  (next_idx < peek_idx) ? peek_item : Iterator::next();
        ++next_idx; 
        return res; 
    }

    bool hasNext() const {
        return (peek_idx > next_idx) ? has_next : Iterator::hasNext(); 
    }
};
