class Solution {
public:
    int dfs(int i , int j , int r , int c , vector<vector<int>>& matrix , vector<vector<int>>& visited, int p){
        if(i < 0 || j < 0 || i >= r || j >= c || matrix[i][j]<=p){
            return 0;
        }
    if(visited[i][j]!=0){
        return visited[i][j];
    }
    int t = dfs(i-1,j,r,c,matrix,visited,matrix[i][j]);
    int b = dfs(i+1,j,r,c,matrix,visited,matrix[i][j]);
    int le = dfs(i,j-1,r,c,matrix,visited,matrix[i][j]);
    int ri = dfs(i,j+1,r,c,matrix,visited,matrix[i][j]);
    visited[i][j] =  1+max(t,max(b,max(le,ri)));
    return visited[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
         int r = matrix.size();
        int c = matrix[0].size();
         vector<vector<int>> visited(r, vector<int>(c,0)); 
      
        int ans  = 1;
        for(int i = 0 ;  i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                    ans = max (ans,dfs(i,j,r,c,matrix,visited,-1));
            }
        }
        return ans;
    }
};