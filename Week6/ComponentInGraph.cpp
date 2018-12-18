#include<iostream> 
#include<list> 
  
using namespace std; 
    
class Graph { 
	//Vertices 
    int V;    
  
    //Pointer to an array containing adjacency lists and boolean to marking the visited node
    list<int> *adj;    
    bool *visited;

    public: 
	//Fucntion for initializing a graph
    Graph(int V);   
  
    //Adding edge to the graph
    void addEdge(int v, int w);  

	//Function to put in the main body
    void doBFS();
  
    //Method to see how long a node s connected to another
    int BFSlong(int s);   
}; 
  
Graph::Graph(int V) { 
	//initialize
    this->V = V; 
    adj = new list<int>[V+1]; 

    visited = new bool[V+1]; 
    for(int i = 0; i < V; i++){
        visited[i] = false; 
    }
} 
  
void Graph::addEdge(int v, int w) { 
	//add w to the adjacency list of v
    adj[v].push_back(w);  
} 

void Graph::doBFS(){
	//initialize the value of the smallest and the largest connected vertices
    int min = this->V * 2, max = 0, count;

    for (int i = 1; i<=this->V; i++){
		//we dont need to check a node that has visited when trying to checked another node before.
        if (!visited[i]){
            count = BFSlong(i);
            if (count > 1 && count <min) min = count;
            if (count > max) max = count;
        }
    }
    cout<<min<<" "<<max;
}


int Graph::BFSlong(int s) { 
    
	//initialize the counter for node length
    int count = 0;
  
    // Create a queue
    list<int> queue; 
  
    // Mark the current node as visited
    visited[s] = true; 
	//enqueue
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) { 
        // Dequeue from queue list
        s = queue.front(); 
		//count up as the there's more node discovered
        count++;
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued vertex s.
        for (i = adj[s].begin(); i != adj[s].end(); ++i) { 
            if (!visited[*i]) { //checking if the adjacent vertices has yet visited
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
    return count;
} 
  
  
int main() 
{ 
    int N, g, b;
	
    cin>>N;
    Graph gr(2*N); 
    for (int i = 0; i< N; i++){
        cin>>g>>b;
		//vice versa to make undirected edge
        gr.addEdge(g, b); 
        gr.addEdge(b, g);
    }
    
    gr.doBFS();
  
    return 0; 
} 