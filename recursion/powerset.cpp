// this is the solution to problem 16.5. 
// enumerate the power set of a given set of all elements. 
// 
// the key idea is to make two choices - one with a specific element, and one without it. 
// lets say you have a collection of 3 items - {1,2,3}. To enumerate the collection, 
// first we will make 2 calls - one with 1 and one without 1. 
//      {1},{2,3}       {},{2,3}
// the first call will generate two more recursive calls - one which chooses 2 and one without 2. 
//      {1,2},{3]       {1},{3} 
// this results in four recursive calls - {1,2,3},{} - {1,2}{} - {1,3},{} - {1}. 


#include <algorithm> 
#include <iostream>
#include <vector>

using namespace std; 

namespace { 
    vector<vector<int>> powerset; 
}

void write(ostream& os) 
{ 
    for (const auto& items: powerset) { 
        for (const auto &i: items) { 
            os << i << " "; 
        }
        os << endl; 
    } 
} 

void enumerate_powerset(vector<int>& sofar, vector<int>& rest) 
{
   if (rest.empty()) { 
        powerset.emplace_back(sofar); 
   }
   else { 
       auto next = sofar; 
       next.emplace_back(rest[0]); 
       auto remaining = rest; 
       remaining.erase(remaining.begin()); 

       enumerate_powerset(next, remaining); 
       enumerate_powerset(sofar, remaining); 
   }  
} 

void solve_powerset(vector<int>& items) 
{ 
    vector<int> sofar = {}; 
    enumerate_powerset(sofar, items); 
} 

int main() 
{
    vector<int> items = {1,2,3,4,5};
    solve_powerset(items); 
    write(cout); 
    return 0; 
} 
