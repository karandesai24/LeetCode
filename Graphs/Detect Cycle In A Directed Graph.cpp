#DFS
bool isCycleDFS(int node, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
    
    visited[node]=true;
    dfsVisited[node]=true;
    
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            if(isCycleDFS(neighbour, adj, visited, dfsVisited)){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, vector<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(isCycleDFS(i, adj, visited, dfsVisited)){
                return true;
            }
        }
    }
    return false;
    
}

#BFS

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first - 1;
        int v=edges[i].second - 1;
        
        adj[u].push_back(v);//directed graph
    }
    //finding indegree
    vector<int> indegree(n);
    
    for(auto i : adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    
    
//puhing in queue
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
        
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            cnt++;
            
            //indegree uptade

            
            for(auto i:adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
    if(cnt == n){
        return false;
        
    }else{
        return true;
    }

}
