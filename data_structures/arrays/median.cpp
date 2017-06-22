#include <algorithm> 
#include <iostream> 
#include <list> 

using namespace std; 

// 3
// 3, 4  - greater go +1. 
// 2, 3, 4, - number was smaller go -1
// 1, 2, 3, 4 - number was smaller, but even, so
// 1, 2, 3, 4, 5, - number was greater, but odd, so go positive 
// 1, 2, 3, 4, 5, 6 - number was greater, but even , so stay 

/* when a num is added and size is odd and element is smaller, mid remains same. 
 * when a num is added and size is even and element is smaller, mid decreases by 1
 * when a num is added and size is odd and element is greater, mid increases by 1 
 * when a num is added and size is even and element is greater, mid remains the same. */ 

class Median { 
    private: 
        list<int> nums; 
        list<int>::iterator mid_point = nums.end(); 
        double median = 0; 

    public: 
        void addNum(int num) { 
          
            // insert the number in the correct position.
            auto it = ((mid_point == nums.end()) || (num < *mid_point)) ? 
                       nums.begin() : mid_point;
            
            for (; it != nums.end(); ++it) {
                if (num <= *it) { 
                    nums.insert(it, num);
                    break;  
                } 
            } 

            if (it == nums.end()) { 
                nums.push_back(num); 
            } 

            // adjust the iterator correctly
            if (mid_point == nums.end()) { 
                mid_point = nums.begin(); 
            } 
            else { 
                if ((nums.size() & 1) && (num > *mid_point)) { 
                    mid_point++; 
                } 
                else if (!(nums.size() &1) && (num <= *mid_point)){ 
                    mid_point--; 
                } 
            } 

            if (nums.size() % 2) { 
               median = *mid_point; 
            } 
            else { 
                int n1 = *mid_point; ++mid_point; 
                int n2 = *mid_point; --mid_point;
                median = (static_cast<double>(n1 + n2))/2; 
            } 
        }

       double findMedian() 
       {
           return median; 
       } 
}; 

int main() 
{ 
    Median m; 
    cout << m.findMedian() << endl; 
    m.addNum(3); 
    cout << m.findMedian() << endl; 
    m.addNum(2); 
    cout << m.findMedian() << endl; 
    m.addNum(1); 
    cout << m.findMedian() << endl; 
    m.addNum(4); 
    cout << m.findMedian() << endl; 
    m.addNum(0); 
    cout << m.findMedian() << endl; 

}

