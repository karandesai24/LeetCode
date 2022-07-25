#EASY PIZZY
// V represents number of Vertices, present 
// in the given DAG.
int V;
// INF means infinity, which is taken
// as largest possible value of 32-bit integer.
int INF=INT_MAX;

// Node class
class Node{
public:
    // v is the vertex, 
    // and wt is the weight.
    int v;
    int wt;
    Node(int _v,int _wt){
        v=_v;
        wt=_wt;
    }
};
vector<vector<Node>> adj;
// Function to add edge u->v of weigth wt.
void addEdge(int u,int v,int wt){
    adj[u].push_back(Node(v,wt));
}

// Adjacency list. 

// Function to find topological Sort which is always possible
// as the given graph is a DAG.
void topologicalSort(int v, bool *visited,
                                stack<int> &st){
    // Marking v as visited.
    
    visited[v]=true;
    // Iterating for all the adjacent nodes of v.
    for(Node node:adj[v]){
        
        // If any adjacent node to v is not 
        // visited, call topologicalSort function on it.
        if(!visited[node.v]){
            topologicalSort(node.v, visited, st);
        }
    }
    // Push v into Stack
    
    st.push(v);
}

// Function to compute the shortest path 
// to all other vertices starting from src.
void shortestPath(int src){
    
    // Declare a Stack (st) which is used to find 
    // the topological sort of the given DAG.
    stack<int> st;

    // Declare a dist array where dist[i] denotes
    // shortest distance of src from i. 
    // Initialize all it's entries with INF and 
    // dist[src] with 0.
    int dist[V];
    for(int i=0;i<V;i++)
        dist[i]=INF;

    dist[src]=0;

    // Create boolean visited array to keep track 
    // of visited elements.
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    // Iterate for all the V vertices.
    for(int i=0;i<V;i++){
        // If 'i' found to unvisited call 
        // topoplogicalSort from there.
        if(!visited[i]){
            topologicalSort(i,visited,st);
        }
    }
    
    // Iterate till the stack is not empty.
    while(!st.empty()){
        // Pop element from stack and store it in u.
        int u=st.top();
        st.pop();

        // If shortest distance from src to u is 
        // not infinity i.e. it is reachable.
        
        if(dist[u]!=INF){
            // Iterate for all the adjacent vertices 
            // of u.
            for(Node node:adj[u]){
                // If distance of src->v is greater than
                // distance of src->u + u->v then update
                // the value as shown.
                if(dist[node.v]>dist[u]+node.wt)
                    dist[node.v]=dist[u]+node.wt;
            }
        }
    }
    
    // Print the distances.
    for(int i=0;i<V;i++){
        if(dist[i]==INF)
            cout<<"INF ";
        else
            cout<<dist[i]<<" ";
    }
    
}
// Main function
int main(){
    V=6;
    // Initialize Adjacency List.
    // adj=new ArrayList<>();
    for(int i=0;i<V;i++)
        adj.push_back(vector<Node>());

    // Add edges.
    addEdge(0, 2, 4);
    addEdge(1, 0, 3);
    addEdge(2, 3,-3);
    addEdge(2, 4, 2);
    addEdge(1, 2, 2);
    addEdge(1, 3, 5);
    addEdge(4, 3, 2);
    // Find the shortest path from a 
    // vertex (here 0).
    shortestPath(0);
    
    return 0;
}




#GFG SOLUTION
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};
 
// Class to represent a graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices'
 
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;
 
    // A function used by shortestPath
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
 
    // Finds shortest paths from given source vertex
    void shortestPath(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}
 
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
 
    // Push current vertex to stack which stores topological sort
    Stack.push(v);
}
 
// The function to find shortest paths from given vertex.
// It uses recursive topologicalSortUtil() to get topological
// sorting of given graph.
void Graph::shortestPath(int s)
{
    stack<int> Stack;
    int dist[V];
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to store
    // Topological Sort starting from all vertices
    // one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Initialize distances to all vertices as
    // infinite and distance to source as 0
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[s] = 0;
 
    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();
 
        // Update distances of all adjacent vertices
        list<AdjListNode>::iterator i;
        if (dist[u] != INF)
        {
          for (i = adj[u].begin(); i != adj[u].end(); ++i)
             if (dist[i->getV()] > dist[u] + i->getWeight())
                dist[i->getV()] = dist[u] + i->getWeight();
        }
    }
 
    // Print the calculated shortest distances
    for (int i = 0; i < V; i++)
        (dist[i] == INF)? cout << "INF ": cout << dist[i] << " ";
}
 
// Driver program to test above functions
int main()
{
  
    // Here vertex numbers are 0, 1, 2, 3, 4, 5 with
    // following mappings: 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
 
    int s = 1;
    cout << "Following are shortest distances from source " << s <<" n";
    g.shortestPath(s);
 
    return 0;
}
