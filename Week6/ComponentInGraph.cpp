#define MAXV 10000

//Helper for DFS dan BFS
bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];
bool finished = false;


typedef struct EDGENODE{
    int y;
    int weight;
    struct EDGENODE *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;
} graph;

void initialize_graph(graph *g, bool directed){
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (int i=1; i<MAXV; i++) g->degree[i] = 0;
    for (int i=1; i<MAXV; i++) g->edges[i] = 0;
}

void insert_edge(graph *g, int x, int y, bool directed){
    edgenode *p; //Temporary pointer
    p = (edgenode*)malloc(sizeof(edgenode));
    
    //p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;
    
    g->degree[x] ++;
}

void process_edge(int v, int y){
    //Desired process
}

void dfs(graph *g, int v){
    edgenode *p;
    int y;
    
    if(finished) return;
    
    discovered[v] = true;
    
    p = g->edges[v];
    while (p != NULL) {
        y = p->y;
        if (discovered [y] == false){
            parent[y] = v;
            process_edge(v,y);
            dfs(g,y);
        }
        else if((!processed[y]) || (g->directed))
            process_edge(v,y);
        if (finished) return;
        p = p->next;
    }
    
    processed[v] = true;
}

