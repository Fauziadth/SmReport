To find if there's any cycle within our graph or no we can go check for the back edges. back edges are the key to finding a cycle 
in an undirected graph. if there is no back edge, all edges are tree edges, and no cycle exists in a tree. But any back 
edge going from x to an ancestor y creates a cycle with the tree path from y to x. We can actually find this cycle using DFS.

ancestor: suppose that y is an ancestor in the dfs tree. it means that we must enter y before x. 
//-----------------------------------------------------------------------------

#define MAXV 10000

//Pembantu untuk DFS dan BFS
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

void read_graph(graph *g, bool directed){
	int i;
	int m;		//number of edge
	int x, y;	//Vertices in edge
	
	initialize_graph(g, directed);
	
	//scanf("%d %d", &x, &y);
	cin>>g->nvertices>>m;
	
	for(i = 1; i<=m; i++){
		cin>>x>>y;
		insert_edge(g, x, y, directed);
	}
}

//-----------------------------------------------------------------------------
//Algorithm for Depth First Search and Findign Cycles

bool finished = false;

//-----------------------------------------------------------------------------
//Algorithm for finding cycles

void find_path(int start, int end, int parents[]){
	if ((start == end) || (end == -1))
		print("\n%d", start);
	else {
		find_path(start,parents[end], parents);
		printf"\n%d", end);
}

void process_edge(int v, int y){
    //Desired process
	
	if(parents[x] != y) {
		printf("Cycle from %d to %d: ", y, x);
		find_path(y, x, parent);
		printf("\n\n");
		finished = true;
	}
}

//-----------------------------------------------------------------------------
//Algorithm for Depth First Search

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

