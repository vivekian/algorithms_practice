//rudimentary graph representation and BFS solution. 

#include <vector>
#include <random> 
#include <algorithm> 
#include <cstdio> 
#include <queue>
#include <stdint.h> 

namespace { 
    const int MAXV = 500000; 
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

bool DoesEdgeExist(const graph* const g, const int x, const int y) 
{ 
    edgeNode* p = g->nodelist[x]; 

    while(p) { 
        if (p->y == y) 
            return true; 
        p = p->next; 
    }

    return false; 
}

// watch out for the recursive call to make sure there is an edge 
// from y to x as well. IsReverse just links on the other side.
void InsertEdge(graph* g, const int x, const int y, const bool IsReverse)
{
  /*   if (DoesEdgeExist(g, x, y))
    { 
        return; 
    } */ 
    
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
        printf("Q size: %lu\n", q.size());
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

int main() 
{ 
    const int NUM_VERTICES = 100000;
    graph g; 
    Initialize(&g);
    GenerateGraph(&g, NUM_VERTICES, 1000); 
    g.nvertices = NUM_VERTICES; 

    uint32_t d[MAXV]; 
    BFS(&g, d); 


    return 0; 
}
