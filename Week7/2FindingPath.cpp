For finding the shortest path here, we will try first by bfs method so that we can map each vertex parents. And after we have done the bfs we can eventually find how to get to certain vertex from another vertex where we will find it by going reversely by look at each of the vertices’ parent (so we actually find it by going y to x when we need to find a way from x to y). There’s actually a problem in this mechanic, the problem is it is only useful if BFS was performed with x as the root of the search. And second, if the graph itself is an unweighted graph. 

//-----------------------------------------------------------------------------
#define MAXV 10000

//Pembantu untuk BFS
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
//Algorithm for Breadth First Search

void initialize_search(graph *g){
	int i;
	
	for (i=1; i<=g->nvertices; i++){
		processed[i] = false;
		discovered[i] = false;
		parent[i] = -1;
	}
}

void process_edge(int v, int y){
}

void process_vertex_early(int v){
}

void process_vertex_late(int v){
}

void bfs(graph *g, int v){
    queue q;
	int v;
	int y;
	edgenode *p;
	
	int start = 
	discovered[start] = true;
	while(empty_queue(&q) == false){
		v=dequeue(&q);
		process_vertex_early(v);
		processed[v] = true;
		p = g->edges[v];
		while (p != NULL) {
			y = p->y;
			if((processed[y] ==false || g->directed)
				process_edge(v,y);
			if(discovered[y] == false){
				enqueue (&q, y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;
		}
		process_vertex_late(v);
	}
}

//---------------------------------------------------------------------------
//Algorithm for finding path

void find_path(int start, int end, int parents[]){
	if ((start == end) || (end == -1))
		print("\n%d", start);
	else {
		find_path(start,parents[end], parents);
		printf"\n%d", end);
}