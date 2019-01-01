Kruskal’s is an alternate approach to finding minimum spanning trees that somehow proves more efficient on sparse graphs. 
It is actually similar to prim’s which is a greedy algorithm, but it doesn’t need to start with a particular vertex. 
The algorithm builds up connected components of vertices, where initially each vertex forms its own separate component
like a tree the algorithm repeatedly considers the lightest remaining edge a will see if the edge connecting a pair of 
vertices in the same component or not, if the vertices already in the same component then the edge will be discarded, 
and if not, then the edge will be assigned as a connector between those components.

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
//Section for Union struct algorithm


typedef struct {
	int P[SET_SIZE+1];		//Parent element
	int size[SET_SIZE+];	//Number of elements in subtree i
	int n;					//number of elements in set
} set_union

//Initialization
void set_union_init(set_union *s, int n){
	int i;
	
	for(i=1; i<=n; i++){
		s->p[i] = i;
		s->size[i] = 1;
	}
	
	s->n = n;
}

int find (set_union *s, int x){
	if(s->p[x] == x) 
		return (x);
	else
		return (find(s,s->p[x]);
}

int union_sets(set_union *s, int s1, int s2){
	int r1, r2; //Roots of sets
	
	r1 = find(s,s1);
	r2 = find(s,s2);
	
	if(r1 == r2) return;	//Already in same set
	
	if(s->size[r1] >= s->size[r2]){
		s->size[r1] = s->size[r1] + s->size[r2];
		s->p[r2] = r1;
	} else {
		s->size[r2] = s->size[r1] + s->size[r2];
		s->p[r1] = r2;
	}
}

bool same_component(set_union *s, int s1, int s2){
	return (find(s, s1) == find(s,s2));
}

//-----------------------------------------------------------------------------
//Section for Kruskal's algorithm for minimum spanning trees

void kruskal(graph *g){
	int i;					//Counter
	set union s;			//Set union data structure
	edge_pair e[MAXV+1];	//Array of edges data structure
	bool weight_compare();
	
	set_union_init(&s, g->nvertices);
	
	to_edge_array(g,e);		//Sort Edges by increasing cost
	qsort(&e, g->nedges, sizeof(edge_pair), weight_compare);
	
	for(i=0; i<(g->nedges); i++){
		if(!same_component(s,e[i].x, e[i].y){
			printf("edge (%d%d) in MST\n", e[i].x, e[i].y);
			union_sets(&s, e[i].x, e[i].y);
		}
	}
}
