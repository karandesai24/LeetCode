void dfs(int node, int parent, int &timer,vector<int> &disc, vector<int> &low,unordered_map<int,list<int>> &adj, vector<vector<int>> &result,unordered_map<int,bool> &visited){
    visited[node]=1;
    disc[node]=low[node]=timer++;
    for(auto nbr:adj[node]){
        if(parent==nbr){
            continue;}
        if(!visited[nbr]){
                    dfs(nbr,node,timer,disc,low,adj,result,visited);
            low[node]=min(low[node],low[nbr]);
// check edge is bridge
            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else {
            // back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer=0;
    unordered_map<int,bool> visited;
    int parent=-1;
    vector<int> disc(v);
    vector<int> low(v);
    for(int i=0; i<v; i++){
        disc[i]=-1;
        low[i]=-1;
    }
    vector<vector<int>> result;
    // dfs
    for(int i=0; i<v;i++){
        if(!visited[i])
            dfs(i,parent,timer,disc,low,adj,result,visited);
    }
    return result;
    
}
