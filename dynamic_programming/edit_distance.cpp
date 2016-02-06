// the idea is to find the minimum cost of transforming string x 
// to string y. There are 3 operations possible for each character - addition
// deletion or substitution. substitution has a cost of 2 as opposed to the cost
// of 1 for addition or deletion. 

// if one of the strings is empty, then the result is the size of the other string 
// best resource: https://class.coursera.org/nlp/lecture/7

#include <stdint.h> 
#include <string>
#include <cstdio>
#include <algorithm> 
#include <vector> 
#include <utility>

using namespace std; 

uint32_t edit_distance(const string& x, const string& y) 
{ 
    if (x.empty()) 
        return y.size(); 

    if (y.empty()) 
        return x.size(); 
    
    uint32_t cost[x.size()][y.size()]; 


    for (int i=0; i<x.size(); ++i) 
        cost[i][0] = i; 

    for (int j=0; j<y.size(); ++j) 
        cost[0][j] = j; 

    for (int i=1; i<x.size(); ++i) { 
        for (int j=1; j<y.size(); ++j) { 
            cost[i][j] = std::min(std::min(cost[i-1][j] + 1, 
                                           cost[i][j-1] + 1), 
                                  cost[i-1][j-1] + 
                                           ((x[i] == y[j]) ? 0:2));
        }
    }

    return cost[x.size()-1][y.size()-1]; 
}

int main() 
{ 
    vector<pair<string, string>> testcases = { 
        {"alpha", "ansha"},
        {"alpha", " "},
        {"alpha", "peter"}, 
        {"algorithm", "altruistic"},
        {"a", "altruistic"}
    }; 
    
    for (auto &test: testcases) { 
        printf("%s %s: %u\n", test.first.c_str(), test.second.c_str(), 
                              edit_distance(test.first, test.second));
    }

    return 0; 
}
