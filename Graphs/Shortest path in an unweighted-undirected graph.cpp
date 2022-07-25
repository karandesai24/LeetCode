vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){

//     Adj List
    unordered_map<int, list<int>> adj;
    for(int i =0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	
//     BFS
    unordered_map<int, bool> visited;
    unordered_map<int , int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto i : adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    
//     Shortest Path
    vector<int> ans;
    ans.push_back(t);
    int currNode = t;
    while(currNode != s){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
