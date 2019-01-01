We can actually see that the algorithm is a little similar with prim’s algorithm for the minimum spanning tree. The differences are located at the condition for deciding a vertex to be the parents. In this algorithm, we can get a new parent if the distance to reach vertex we observed from the starting vertex is become smaller. We can see from the line which state a condition distance[v] > distance[v] + weight. There’s actually some condition to be avoided if we need to use this method. It’s when we are working with negative-cost edges. 

//-----------------------------------------------------------------------------
//Algorithm for graph structure

//For vertices, what properties do they have


#define MAXV 10000


typedef struct EDGENODE{
    int y;
    int weight;
    struct EDGENODE *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];	//Edges for adjacency list of every vertices
    int degree[MAXV+1];			//Degree
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
//Section for Dijkstra

void dijkstra(graph *g, int start){
	int i;						//Counter
	edgenode *p;				//Temporary pointer 
	bool intree[MAXV+1];		//To state the vertex i already in the tree or not
	int distance[MAXV+1];		//Distance vertex i from start
	int v;						//Current processed vertex
	int w;						//Candidate for the next vertex
	int weight;					
	int dist;					//To see/comparing distance from start
	
	//Initializing the state for vertices
	for(i=1; i<=g->nvertices; i++){
		intree[i] = false;
		distance[i] = MAXINT;
		parent[i] = -1;
	}
	
	//stating the starting vertex
	distance[start] = 0;
	v = start;
	
	while(intree[v] == false){
		intree[v] = true;
		p = g->edges[v];
		while(p != NULL) {
			w = p->y;
			weight = p->weight;
			if(distance[w] > (distance[v]+weight)){
				distance[w] = distance[v]+weight;
				parent[w] = v;
			}
			p = p->next;
		}
		
		v = 1;
		dist = MAXINT;
		for(i=1; i<=g->nvertices; i++){
			if ((intree[i] == false) && (dist > distance[i])){
				dist = distance[i];
				v = i;
			}
		}
		
	}
	
}