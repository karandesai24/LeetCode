class Solution {
public:
    int minWays(int i,int j,int m,vector<vector<int>>& tri,vector<vector<int>>& dp){
        if(i==m-1)
            return tri[m-1][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int d=tri[i][j]+minWays(i+1,j,m,tri,dp);
        int dg=tri[i][j]+minWays(i+1,j+1,m,tri,dp);
        return dp[i][j]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int m=tri.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return minWays(0,0,m,tri,dp);
    }
};