// this solves problem 6.1 (dutch flag partition problem) of 
// EPI (Elements of Programming Interviews) 

#include <algorithm> 
#include <iostream> 
#include <vector> 

using namespace std; 

void three_way_partition(vector<int>& items, const int mid) 
{
  int i=0; // i is the boundary of numbers less than mid 
  int j=0; // j is the number being considered 
  int n = items.size()-1;  // n is the boundary of numbers greater than mid 

  while (j < n) { 

      // if item is less than mid, then move it below i 
      if (items[j] < mid) { 
          swap(items[i], items[j]); 
          ++i; 
          ++j; 
      } 
      // if item is greater than mid, then move it above n
      else if (items[j] > mid) { 
          swap(items[j], items[n]); 
          --n; 
      }
      // if item is equal to mid, then do nothing and move to the next item.
      else { 
          ++j; 
      } 
  }
}

void write(ostream& os, const vector<int>& items) 
{ 
    for (int i=0; i<items.size(); ++i) { 
        os << items[i] << " "; 
    } 

    os << endl; 
} 

int main() 
{ 
    vector<int> items = {10,9,8,7,6}; 
    three_way_partition(items, 8); 
    write(cout, items); 

    items = {10, 8, 9, 8, 3, 22, 77};
    three_way_partition(items, 10); 
    write(cout, items);  
    return 0; 
} 
