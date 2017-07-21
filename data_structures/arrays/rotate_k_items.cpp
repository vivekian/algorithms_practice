#include <iostream> 
#include <utility> 
#include <vector> 

using namespace std; 

void reverse(vector<int>& items, int start, int end) 
{
    int i=start; 
    int j=end; 

    while (i < j) { 
        swap(items[i], items[j]);
        ++i; 
        --j; 
    }
}

void rotate(vector<int>& items, int k) { 
    int len = items.size();
    k = k % len; 
    reverse(items, 0, len-1-k);  
    reverse(items, len-k, len-1);  
    reverse(items, 0, len-1); 
}

void write(ostream& os, const vector<int>& items) 
{
    for (const auto& x: items) { 
        os << x << " "; 
    }

    os << endl; 
}


int main()
{
    vector<int> items = {1,2,3,4};
    rotate(items, 3); 
    write(cout, items);  
    return 0; 
}
