#include <iostream> 
#include <queue> 
#include <vector> 

using namespace std; 

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) 
{
    queue<int> q; 
    q.push(start);    

    while (!q.empty()) { 

        int item = q.front(); 
        q.pop(); 
        visited[item] = true; 

        for (const auto& i: graph[item]) { 
            if (!visited[i]) { 
                 q.push(i); 
            }
        } 
    }
}

int countComponents(int n, vector<pair<int, int>>& edges) {
    int cnt = 0; 
 
    vector<vector<int>> graph(n); 
    vector<bool> visited(n, false); 

    // its important to push a single edge on both the neighbor lists. 
    for (const auto& e: edges) {
            graph[e.first].push_back(e.second); 
            graph[e.second].push_back(e.first); 
    } 

    for (int i=0; i<n; ++i) { 
        if (!visited[i]) { 
            bfs(i, graph, visited); 
            ++cnt; 
        }
    }

    return cnt; 
}

int main()
{
    vector<pair<int, int>> items = {{0, 1}, {1, 2}, {3, 4}};
    cout << countComponents(5,  items) << endl;  

    items = {};
    cout << countComponents(1,  items) << endl;  

    items = {};
    cout << countComponents(2,  items) << endl;  
    cout << countComponents(0,  items) << endl;  

    items = {{0, 1}, {1, 2}, {2,3}, {3, 4}};
    cout << countComponents(5, items) << endl; 

    items = {{1, 0}}; 
    cout << countComponents(2, items) << endl; 

    items = {{2,0}, {2,1}}; 
    cout << countComponents(3, items) << endl; 
    return 0; 
} 
