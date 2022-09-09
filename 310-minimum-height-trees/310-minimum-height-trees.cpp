class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         if(n == 1)
            return {0};
        
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
            
            indegree[u]++;
            
            indegree[v]++;
        }
        
         queue<int> q;
        
        for(int u = 0; u < n; u++)
        {
            if(indegree[u] == 1)
            {
               q.push(u);
            }
        }
        
      
        while(n > 2)
        {
            int size = q.size();
            
          
            n = n - size;
            
            for(int i = 0; i < size; i++)
            {
                // take the front node
                
                int u = q.front();
                
                q.pop();
                
              
                
                for(auto v : adj[u])
                {
                    indegree[v]--;
                    
                   
                    
                    if(indegree[v] == 1)
                    {
                        q.push(v);
                    }
                }
            }
        }
        
       
        
        vector<int> res;
        
        while(!q.empty())
        {
            res.push_back(q.front());
            
            q.pop();
        }
        
        return res;
    }
};