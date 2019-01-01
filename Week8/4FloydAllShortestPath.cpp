what we are doing here is like testing a connection between vertices I and j and try to connected them both through a certain vertex k (all vertices one by one), until we get the smallest possible weight to connected I and j, and of course we need to set the I and j to all possible pairs as well. We can see that the algorithm runs in triple iteration so it is will run in O(n3) time, which is not really better if we use Prim’s which is run in O(n2) but we need to test it to all the vertices.

//-----------------------------------------------------------------------------
//Section for Floyd

#define MAXV 10000


//Struct for the adjacency matrix
typedef struct {
		int weight[MAXV+1][MAXV+1];
		int nvertices
} adjacency_matrix;

floyd(adjacency_matrix *g){
	int i,j;			//For dimension of adjacency matrix
	int k;				//Intermediate vertex counter
	int through_k;		//Distance through vertex k
	
	for(k=1; k<=g->nvertices; k++){
		for (i=1; i<=g->nvertices; i++){
			for (j=1; j<=g->nvertices; j++){
				through_k = g->weight[i][k]+g->weight[k][j];
				if(through_k < g->weight[i][j]) g->weight[i][k] = through_k;
			}
		}
	}
}