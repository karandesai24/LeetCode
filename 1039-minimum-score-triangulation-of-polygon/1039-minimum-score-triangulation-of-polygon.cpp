class Solution {
public:
    int solve(vector<int>& v,int i,int j,vector<vector <int>>&dp)
   {
      
       if(i+1==j)
       {
           return 0;
       }
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
      
        int ans= INT_MAX;
           for(int k=i+1; k<j;k++)
           {
               ans = min(ans,v[i]*v[j]*v[k]+solve(v,i,k,dp)+solve(v,k,j,dp));
           }
            dp[i][j]=ans;
            return dp[i][j];
           
       
       
   }
    int minScoreTriangulation(vector<int>& values) {
        int n= values.size();
           vector<vector <int>> dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
        
    }
};

/*
 vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));

    for (int j = 2; j < A.size(); ++j)
      for (int i = j - 2; i >= 0; --i) {
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k < j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
      }

    return dp[0][A.size() - 1];
    */