#include <iostream> 
#include <vector> 

using namespace std; 
vector<bool> visited;

// if there is a cycle in the graph, we can't complete the schedule. 
// to detect a cycle, we have to find a backward edge(going from descendent to ascendent)
// the way to find the edge is to have a list of courses which are part of the current 
// recursive stack being explored.

// pass currList by value instead of reference, because we want recursive stack list.
bool DetectCycle(int course, vector<vector<int>>& graph, vector<bool> currList) {
        currList[course] = true;

        for (auto c: graph[course]) {
				// check if its in the current stack list - then its a cycle. 
                if (currList[c]) {
                    return true;
                }
                
				// only visit if its not been visited. 
                if (!visited[c]) { 
                	visited[c] = true; 
					if (DetectCycle(c, graph, currList)) {
						return true;
					}
				}
        }

        return false;
}

bool DFS(int numCourses, vector<vector<int>>& graph) {
	vector<bool> currList (numCourses, false);

	for (int i=0; i<numCourses; ++i) {
		if (!visited[i]) {
			visited[i] = true;

			// if there is a cycle, we can't finish schedule. 
			if (DetectCycle(i, graph, currList)) {
				return false;
			}
		}
	}

	return true;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<vector<int>> graph(numCourses);
	visited.resize(numCourses); 
	fill(visited.begin(), visited.end(), false); 

	for (const auto& p: prerequisites) {
			graph[p.first].push_back(p.second);
	}

	return DFS(numCourses, graph);
}

int main()
{
	vector<pair<int, int>> edges = { 
		{0, 1},
		{0, 2}, 
		{1, 2}};  
	
	cout << canFinish(3, edges) << endl;  
    return 0; 
} 
