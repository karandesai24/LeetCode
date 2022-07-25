#include<bits/stdc++.h>
void bfs(int v, map<int,set<int>> &edges, vector<int>&visited,
        vector<int>&res)
{
    queue<int>q;
    q.push(v);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (auto nei : edges[cur])
        {
            if (visited[nei] == 0)
            {
                visited[nei] = 1;
                q.push(nei);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int>visited(vertex,0);
    vector<int>res;
    map<int,set<int>>adj_list;
    
    for (int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }
    
    for (int i=0;i<vertex;i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            bfs(i,adj_list,visited,res);
        }
    }
    return res;
}
