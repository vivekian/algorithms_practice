#include <iostream> 
#include <queue> 
#include <unordered_map> 
#include <vector> 

using namespace std; 

 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
{
	UndirectedGraphNode* start = nullptr; 
	unordered_map<int, UndirectedGraphNode*> visited; 
	queue<UndirectedGraphNode*> q1; 

    // copy the first node of the graph if it exists and push original 
    // node to the queue and mark it visited. 
	if (node) { 
		start = new UndirectedGraphNode(node->label); 
		q1.push(node); 
		visited[start->label] = start; 
	} 

	while (!q1.empty()) { 
		UndirectedGraphNode* n1 = q1.front(); q1.pop(); 
		UndirectedGraphNode* n2 = visited[n1->label];

        // for all the neighbors, if not visited, create new node, mark visited
        // and push original node to queue. 
		for (const auto& n: n1->neighbors) { 
			if (visited.find(n->label) == visited.end()) { 
				visited[n->label] = new UndirectedGraphNode(n->label); 
				q1.push(n); 
			} 
            
            // don't forget to push to the neighbors list. 
			n2->neighbors.push_back(visited[n->label]); 
		} 
	} 

	return start; 
}

void testcases() 
{ 
	if (cloneGraph(nullptr)) { 
		cerr << "test failed\n"; 
	} 
	else { 
		cout << "test passed\n"; 
	}

	UndirectedGraphNode n(1); 
	n.neighbors.push_back(&n);
	
	if (cloneGraph(&n)->label != 1) { 
		cerr << "test failed\n"; 
	} 
	else { 
		cout << "test passed\n"; 
	}

	UndirectedGraphNode n2(2); 
	n2.neighbors.push_back(&n);

	auto res = cloneGraph(&n2); 
	if (res->label == 2 && res->neighbors[0]->label == 1) { 
		cout << "test passed\n"; 
	} 
	else { 
		cerr << "test failed\n";
	}  
}	

int main()
{
	testcases(); 
	return 0;  
} 
