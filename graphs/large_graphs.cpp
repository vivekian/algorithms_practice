//rudimentary graph representation and BFS solution. 

#include <algorithm> 
#include <chrono> 
#include <cstdio> 
#include <queue>
#include <random> 
#include <stdint.h> 
#include <vector>
#include <iostream> 

using namespace std::chrono;

namespace { 
    const uint32_t MAXV = 500000; 
}

typedef struct edgeNode { 
    uint32_t y; 
    edgeNode* next; 
} edgeNode;

typedef struct graph { 
    edgeNode* nodelist[MAXV]; 
    uint32_t degree[MAXV]; 
    uint32_t nvertices; 
} graph; 

void Initialize(graph* g) 
{ 
    std::fill(g->nodelist, g->nodelist + MAXV-1, nullptr); 
    std::fill(g->degree, g->degree + MAXV-1, 0); 
    g->nvertices = 0; 
}

void CleanGraph(graph* g) 
{ 
    for (int i=0; i<g->nvertices; ++i) { 
        edgeNode* p = g->nodelist[i]; 
        while (p) { 
            edgeNode* tmp = p;
            p = p->next; 
            if (tmp) 
                delete tmp; 
        }
    }
}

// watch out for the recursive call to make sure there is an edge 
// from y to x as well. IsReverse just links on the other side.
void InsertEdge(graph* g, const int x, const int y, const bool IsReverse)
{
    edgeNode* node = new edgeNode; 
    node->y = y; 
    node->next = g->nodelist[x]; 
    g->nodelist[x] = node; 
    g->degree[x]++; 

    if (!IsReverse)
        InsertEdge(g, y, x, true);  
}

void PrintGraph(const graph* const g) 
{ 
    for (int i=0; i<g->nvertices; ++i) { 
        printf("%d -> ", i); 
        edgeNode* p = g->nodelist[i]; 
        while (p) { 
            printf("%d -> ", p->y);
            p = p->next;
        }
        printf("\n"); 
    }
}

void BFS(const graph* g, uint32_t d[])
{
    std::queue<int> q;
    
    for (int i=0; i<g->nvertices; ++i) 
        d[i] = UINT32_MAX; 

    q.push(0); 
    d[0] = 0; 

    while (!q.empty()) { 
        
        int node = q.front();
        q.pop();
        edgeNode* p = g->nodelist[node]; 
        
        while(p) {
          if (d[p->y] == UINT32_MAX) { 
                d[p->y] = d[node] + 1; 
                q.push(p->y); 
          } 
          p=p->next; 
        }
    }

    return; 
}

void GenerateGraph(graph* g, const int vertices, const int edgesPerNode) 
{ 
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<uint32_t> dist(0, vertices-1);


    for (int i=0; i<vertices; ++i) { 
        int j=0; 
        std::vector<bool> track(vertices, false);
       
        while (j < edgesPerNode) { 
            uint32_t vertex = dist(mt);
            // dont create a self loop
            if (vertex != i && !track[vertex]) { 
                InsertEdge(g, i, vertex, false); 
                track[vertex] = true; 
                ++j;  
            }
        }
    }

} 
 
namespace { 
    const int vertices_edges [6][2] = 
    { 
        {10,      1    }, 
        {100,     10   }, 
        {1000,    100  }, 
        {10000,   1000 },
        {100000,  1000 }, 
        {9999999, 1000 }
    };
}
 
int main() 
{ 
    for (int i=0; i<5; ++i) { 
        graph g; 
        Initialize(&g);
        GenerateGraph(&g, vertices_edges[i][0], vertices_edges[i][1]); 
        g.nvertices = vertices_edges[i][0]; 

        uint32_t d[MAXV]; 
        high_resolution_clock::time_point t1 = high_resolution_clock::now();    
        BFS(&g, d);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();    

        auto duration = duration_cast<microseconds>(t2 - t1).count();
        std::cout << duration << std::endl; 
 
        CleanGraph(&g); 
    }
    return 0; 
}
