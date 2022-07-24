class Solution {
public:
      
    map<string,vector<string>> m;
    vector<vector<string>> ans;
    map<string,bool> vis;
    
    void dfs(string val,vector<string> &v){
        if(vis[val])
            return;
        v.push_back(val);
        vis[val] = true;
        for(auto it:m[val]){
            if(!vis[it])
                dfs(it,v);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i=0;i<accounts.size();i++){
            for(int j=2;j<accounts[i].size();j++){
                m[accounts[i][1]].push_back(accounts[i][j]);
                m[accounts[i][j]].push_back(accounts[i][1]);
            }
        }
        for(int i=0;i<accounts.size();i++){
            vector<string> res;
            res.push_back(accounts[i][0]);
            dfs(accounts[i][1],res);
            if(res.size()>1){
                sort(res.begin()+1,res.end());
                ans.push_back(res);
            }
        }
        return ans;
    }
};