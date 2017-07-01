#include <iostream> 
#include <vector> 

using namespace std; 
vector<bool> visited;

// if there is a cycle in the graph, we can't complete the schedule. 
// to detect a cycle, we have to find a backward edge(going from descendent to ascendent)
// the way to find the edge is to have a list of courses which are part of the current 
// recursive stack being explored.

// pass currList by value instead of reference, because we want recursive stack list.
vector<int> DFS_Visit(int course, vector<vector<int>>& graph, vector<bool> currList) {
        currList[course] = true;
        vector<int> res; 

        for (auto c: graph[course]) {
				// check if its in the current stack list - then its a cycle. 
                if (currList[c]) {
                    return {};
                }
                
				// only visit if its not been visited. 
                if (!visited[c]) { 
                	visited[c] = true; 
					
                    // each time DFS_Visit has explored a node and its subtree
                    // append its ordering to res. 
                    auto tmp = DFS_Visit(c, graph, currList);
                    
                    // an empty vector means that there is no ordering possible
                    if (tmp.empty()) { 
                        return tmp; 
                    } 

				    res.insert(res.end(), tmp.begin(), tmp.end()); 
				}
        }

        // once all the edges have been explored, then push node 
        // the vector to get the correct order. 
        res.push_back(course); 
        return res;
}

vector<int> DFS(int numCourses, vector<vector<int>>& graph) {
	vector<bool> currList (numCourses, false);
    vector<int> res = {};

	for (int i=0; i<numCourses; ++i) {
		if (!visited[i]) {
			visited[i] = true;

			// if there is a cycle, we can't finish schedule. 
			auto tmp = DFS_Visit(i, graph, currList); 
	        
            if (tmp.empty()) { 
                return tmp; 
            }
            
            res.insert(res.end(), tmp.begin(), tmp.end()); 
		}
	}

	return res;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<vector<int>> graph(numCourses);
	visited.resize(numCourses); 
	fill(visited.begin(), visited.end(), false); 

	for (const auto& p: prerequisites) {
			graph[p.first].push_back(p.second);
	}

	return DFS(numCourses, graph);
}

void print(ostream& os, const vector<int>& vec) 
{ 
    for (const auto&v : vec) { 
        os << v << " "; 
    } 

    os << endl; 
} 

int main()
{
	vector<pair<int, int>> edges = { 
		{1, 0},
		{2, 0}, 
		{3, 1},
        {3, 2}};  
	
	auto order = findOrder(4, edges); 
    print(cout, order); 
    return 0; 
} 
