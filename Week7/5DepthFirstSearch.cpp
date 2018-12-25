The algorithm of this depth first search is actually not much different than the BFS mechanics. The main thing that differentiate DFS from BFS is in DFS we actually use a structure stacks when the BFS use a queue structure. In DFS it’s applied LIFO (Last in First out) principle. By using this type, in DFS the order in which they explore vertices is by lurching along a path, visiting a new neighbor if one is available, and backing up when we only have previously discovered vertices. 
Interestingly in DFS we don’t need to really implement with the stack structure instead we can use a recursion to eliminate the need to keep an explicit stack. In DFS as well is introduced two classes for an edges of an undirected graph, they are tree edges and back edges. Tree edges is the edges that discover new vertices, and are those encoded in the parent relation. And back edges are those whose other endpoint is an ancestor of the vertex being expanded so like going back into the tree.


//-----------------------------------------------------------------------------
#define MAXV 10000

//Pembantu untuk DFS
bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];
bool finished = false;

//-----------------------------------------------------------------------------
//Algorithm for graph structure

//For vertices, what properties do they have
typedef struct EDGENODE{
    int y;
    int weight;
    struct EDGENODE *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];	//Edges for adjacency list of every vertices
    int degree[1000+1];			//Degree
    int nvertices;				//Number of vertices
    int nedges;					//Number of edges
    bool directed;				//Is this directed?
} graph;

//Initializing value for graph
void initialize_graph(graph *g){
    int i;
    
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    for (i=1; i<10; i++) g->degree[i] = 0;
	for (i=1; i<10; i++) g->edges[i] = NULL;
}

//Inserting edge
void insert_edge(graph *g, int x, int y, bool directed){
    edgenode *p; //Temporary pointer
    p = (edgenode*)malloc(sizeof(edgenode));
    
    p->weight = NULL;
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;
    
    g->degree[x] ++;
	
	if (directed == false){
		insert_edge(g,y,x,true); // if undirected edge then we need to make the vice versa of the edge
	} else {
		g->nedges++;
	}
}

//Read to input edges to the graph
void read_graph(graph *g, bool directed){
	int i;
	int m;		//number of edge
	int x, y;	//Vertices in edge
	
	initialize_graph(g, directed);

	
	cin>>g->nvertices>>m;
	
	for(i = 1; i<=m; i++){
		cin>>x>>y;
		insert_edge(g, x, y, directed);
	}
}

//-----------------------------------------------------------------------------
//Algorithm for Depth First Search

void process_vertex_early(int v){
	//Desired process
}

void process_edge(int v, int y){
    //Desired process
}

void process_vertex_late(int v){
	//Desired process
}

void dfs(graph *g, int v){
    edgenode *p;
    int y;
    
    if(finished) return;
    
    discovered[v] = true;
	
	process_vertex_early(v);
    
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
    process_vertex_late(v);
	
    processed[v] = true;
}

