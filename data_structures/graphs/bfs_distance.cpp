#include <limits>
#include <iostream> 
#include <queue> 
#include <string> 
#include <unordered_map> 
#include <vector> 

using namespace std; 

// find distance of each node in a graph from source s using BFS. 
//
//   3    5    2
// a -- b -- c -- e 
//   4    6    1
// a -- d -- f -- e

struct edge { 
    char src; 
    char dst; 
    int weight; 
}; 

namespace { 
    vector<edge> graph = { 
        {'a','b', 3}, 
        {'b','c', 5},
        {'b','f', 1}, 
        {'c','e', 2},
        {'a','d', 4},
        {'d','f', 6},
        {'f','e', 1}
    };
}

vector<int> bfs_distance(vector<edge>& e, char src, int num)
{
    unordered_map<char, vector<pair<char, int>>> g; 

    for (const auto& i: e) { 
        g[i.src].push_back({i.dst, i.weight});
    }

    // initialize distance array with infinity.
    vector<int> d(num, numeric_limits<int>::max()); 
    queue<char> q; 

    // push src and distance to src itself is 0. 
    q.push(src); 
    d[src-'a'] = 0; 

    while (!q.empty()) { 
        char node = q.front(); 
        q.pop();

        // for each neighbor update the distance
        // min of either current distance or edge weight + parents distance to src. 
        for (const auto& p: g[node]) {
            auto idx = p.first - 'a'; 
            d[idx] = min(d[idx], d[node-'a'] + p.second); 

            // push neighbor itself so it can be explored.
            q.push(p.first); 
        } 
    }

    return d;  
}

void print(vector<int>& v) { 
    for (const auto& i: v) { 
        cout << i << " "; 
    }

    cout << "\n"; 
}

int main()
{
    auto res = bfs_distance(graph, 'a', 6);  
    print(res); 
    return 0;  
}
