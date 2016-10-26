// 1, 2, 3, 5, 5, 9, 22, 34
// 2, 4, 5, 22, 44, 66 
//
// output: 2, 5, 22 

#include <iostream> 
#include <vector> 

using namespace std;

void write(ostream& os, vector<int>& v) 
{ 
    for (auto & item: v) {
       os << item << " "; 
    } 
    os << endl; 
} 

vector<int> intersection_lists(vector<int>& l1, vector<int>& l2)
{
    int i=0, j=0; 
    vector<int> out; 

    while ((i < l1.size()) && (j < l2.size())) { 
        
        if (l1[i] == l2[j]) { 

            if (!out.size() || (out.back() != l1[i])) { 
                out.emplace_back(l1[i]); 
            }

            ++i; 
            ++j;
        } 
        else if (l1[i] < l2[j]) { 
            ++i; 
        } 
        else { 
            ++j; 
        } 

    }

    return out; 
}

int main() 
{ 
    vector<int> list1 = {1, 2, 3, 5, 5, 9, 22, 34}; 
    vector<int> list2 = {2, 4, 5, 5, 22, 44, 66}; 
    auto out = intersection_lists(list1, list2); 

    write(cout, out); 

    return 0; 
} 
