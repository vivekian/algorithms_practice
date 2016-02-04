//rudimentary graph representation and BFS solution. 

#include <algorithm> 
#include <cstdio> 
#include <queue>
#include <stdint.h> 

namespace { 
    const int MAXV = 1000; 
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
    std::fill(g->nodelist, g->nodelist + MAXV, nullptr); 
    std::fill(g->degree, g->degree + MAXV, 0); 
    g->nvertices = 0; 
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

int main() 
{ 
    graph g; 
    Initialize(&g);
    g.nvertices = 6; 

    InsertEdge(&g, 0, 1, false);
    InsertEdge(&g, 0, 5, false);
    InsertEdge(&g, 1, 2, false);   
    InsertEdge(&g, 1, 4, false);  
    InsertEdge(&g, 2, 3, false);  
    InsertEdge(&g, 3, 4, false);  
    InsertEdge(&g, 4, 5, false);  
    
    PrintGraph(&g); 

    uint32_t d[MAXV]; 
    BFS(&g, d); 

    for(int i=0; i<g.nvertices; ++i) 
        printf("[%d]: %u\n", i, d[i]); 

    return 0; 
}
