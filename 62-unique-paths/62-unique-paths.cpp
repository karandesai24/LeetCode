class Solution {
public:
     long long int dp[101][101];
  long long int solve(int m,int n,int i,int j){
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = (solve(m,n,i+1,j)+solve(m,n,i,j+1))%2000000000;
    }
  
    int uniquePaths(int m, int n) {
         memset(dp,-1,sizeof(dp));
        return solve(m,n,0,0);
    }
};