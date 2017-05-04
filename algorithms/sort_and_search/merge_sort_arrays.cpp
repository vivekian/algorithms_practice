#include <iostream> 
#include <vector> 

using namespace std; 

vector<int> merge(vector<int> v1, vector<int> v2)
{ 
    const int M = v1.size(); 
    const int N = v2.size(); 

    int i=0, j=0, k=0;
    vector<int> res (M+N); 

    while (k < M+N) { 
        if (i == M) { 
            res[k] = v2[j++]; 
        }
        else if (j == N) { 
            res[k] = v1[i++]; 
        }
        else { 
           if (v1[i] < v2[j]) { 
              res[k] = v1[i++]; 
           }
           else { 
              res[k] = v2[j++]; 
           }
        }
        ++k; 
    }

    return res; 
} 

void print(ostream& out, vector<int>& input) 
{ 
    for (const auto& i: input) { 
        out << i << ",";
    }

    out << endl; 
}

int main() 
{ 
    auto res = merge({1,3,5,7}, {2,4,6,8,10,12,23,25}); 
    print(cout, res); 
    res = merge({}, {2,4,6,8,10,12,23,25}); 
    print(cout, res); 
    res = merge({1,3,5,7}, {}); 
    print(cout, res); 
 
    return 0; 
}
