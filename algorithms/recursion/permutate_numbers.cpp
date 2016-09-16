#include <algorithm> 
#include <iostream> 
#include <vector> 

using std::vector; 
using std::cout; 
using std::endl; 
using std::ostream; 

// consider the example with {1,2,3}. 
// this will result in iterating over each element and choosing one. 
//                          {1}, {2,3} 
// next we choose 2 from the second set to form {1,2}, {3}. Now we 
// choose 3 from the second set to form {1,2,3}. Now the second set is
// empty so we print the first vector. As we backtrack, we now choose 3 instead 
// of 2 as we have to choose every element once, so we get: 
//                          {1,3} {2} 
// in the next recursive call, we choose 2, to get {1,3,2} and print it as second 
// set is empty. As we further step back to the root of the tree, we now pick up 
// 2 as the first element and leave {1,3} in the second set. 
//                          {2} {1,3} 
// This will eventually result in printing {2,1,3} and {2,3,1}. Last we will choose 
// 3 as the first element in the first set and leave {1,2} in the second set resulting
// in the final prints of {3,1,2} and {3,2,1}. 

void write(ostream& os, vector<int>& items) 
{ 
    for (const auto& i: items) { 
        os << i << " "; 
    } 

    os << endl; 
} 

void permutate_helper(vector<int>& sofar, vector<int>& rest) 
{ 
    // once rest is empty, we have picked up all the elements. 
    if (rest.empty()) { 
        write(cout, sofar);         
    }
    else { 
        // choose one element i and add it to the sofar list and remove it 
        // from the remaining list. as we iterate through the list, we always
        // pick up an element atleast once in a unique position.  
        for (int i=0; i<rest.size(); ++i) {

            // notice how we create new vectors. This is so that state is maintained
            // once permutate_helper returns from recursion down the tree.  
            auto next = sofar; 
            auto remaining = rest;  
            next.push_back(rest[i]); 
            remaining.erase(remaining.begin() + i); 
            permutate_helper(next, remaining); 
        } 
    } 
}

void permutate(vector<int>& items) 
{
    vector<int> sofar = {};  
    permutate_helper(sofar, items); 
} 

int main() 
{ 
    vector<int> items = {1,2,3,4,5,6}; 
    permutate(items);  
    return 0; 
} 
