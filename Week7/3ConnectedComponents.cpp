Connected components a maximal set of vertices such that there is a path between every pair of vertices. and these connected 
components are separate from each other if there is no connection between the pieces.

1-2-3-4		5	6-7  <--- we can indentified it as 3 connected components

Connected components can be found using bfs, since the vertex order does not matter. We start from the first vertex. anything 
we discover during this search must be part of the same connected component. We then repeat the search from any undiscovered 
vertex, because we can indicate that as a different component from its state.

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
	cout<<v<<" ";
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

//-----------------------------------------------------------------
//Connected component Algorithm

void connected_components(graph *g){
	int c;
	int i;
	initialize_search(g);
	
	c = 0;
	for (i = 1; i<=g->nvertices; i++){
		if (discovered[i] == false) {
			c=c+1;
			printf("Component %d:", c);
			bfs(g,i);
			printf("\n");
		}
	}
}
