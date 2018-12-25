So basically it works as follow. In BFS, we need to choose a vertex to works as a root. And then we initialize all of the vertex as undiscovered first except the root as a discovered. Meanwhile to put the vertex which we will process later we use a queue data structure that works FIFO (First in First out) and initialize the queue with the root. After that we begin the iteration which will take a vertex from the queue list (the oldest list) as a v vertex and will process all the adjacent vertex (as u vertex) of the vertex v, the process itself is depend to what we desire but we need to change the state from undiscovered to discovered state and put the vertex u to the queue list and store the parent of u (which is v). After all the adjacent vertex of v have been discovered we mark the state of v as process whereas we have look at every edges and vertices that connected to the vertex v.


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


//Before the bfs process starts, we need to initialize the indicator for every vertices first as undiscovered
void initialize_search(graph *g){
	int i;
	
	for (i=1; i<=g->nvertices; i++){
		processed[i] = false;
		discovered[i] = false;
		parent[i] = -1;
	}
}

void process_edge(int v, int y){
    //Desired process
}

void process_vertex_early(int v){
	//Desired process
}

void process_vertex_late(int v){
	//Desired process
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

