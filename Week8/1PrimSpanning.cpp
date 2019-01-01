The algorithm is start from a set of vertices which are not connected/forming a tree with other and by each step we will pick 
a vertex and try to connect it to the tree. We actually can call this a greedy algorithm whereas where we start from a certain 
vertex and at each iteration we add the lowest-weight edge linking a vertex in the tree to a vertex on the outside.
	
So basically what the algorithm will do is first of all we need to initialize a condition where all the vertices are not in the 
tree body, initial distance value  with max value of int (if we use int type) and parent with none (or -1). After that we will 
start with a certain vertex v as an initial tree node. And after that we will look for every of its edge with its neighbor w. 
we will see for that vertex w, if the weight of edge with the v is become smaller it will set vertex v as a new parents. After 
all of w has been processed we will find a new vertex v by a condition that the vertex is not yet assigned to the tree and it has 
the smallest distance with the vertex v. and so on until all the vertex has been assigned to the tree with minimum weighted edges.

//-----------------------------------------------------------------------------
//Algorithm for graph structure

#define MAXV 10000

//For vertices, what properties do they have
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
//Section for prim's algorithm for minimum spanning trees

void prim(graph *g, int start){
	int i;						//Counter
	edgenode *p;				//Temporary pointer 
	bool intree[MAXV+1];		//To state the vertex i already in the tree or not
	int distance[MAXV+1];		//Cost of adding to tree
	int v;						//Current processed vertex
	int w;						//Candidate for the next vertex
	int weight;					
	int dist;					//To see/comparing distance from start
	
	for (i=1; i<=g->nvertices; i++) {
		intree[i] = false;
		distance[i] = MAXINT;
		parent[i] = -1;
	}
	
	distance[start] = 0;
	v = start;
	
	while (intree[v] == false) {
		intree[v] = true;
		p = g->edges[v];
		while(p != NULL){
			w = p-> y;
			weight = p->weight;
			if ((distance[w] > weight) && (intree[w] == false){
				distance[w] = weight;
				parent[w] = v;
			}
			p = p->next;
		}
		
		v = 1;
		dist = MAXINT;
		for (i=1; i<=g->nvertices; i++){
			if ((intree[i] == false) && (dist > distance[i])){
				dist = distance[i];
				v=i;
			}
		}
	}
}
