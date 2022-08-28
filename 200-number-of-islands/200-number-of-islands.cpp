class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int i,int j){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && !visited[i][j] && grid[i][j]=='1'){
            visited[i][j]=1;
            dfs(grid,visited,i,j-1);
            dfs(grid,visited,i,j+1);
            dfs(grid,visited,i-1,j);
            dfs(grid,visited,i+1,j);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    ans++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return ans;
    
    }
};