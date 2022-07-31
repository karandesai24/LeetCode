class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    int maxLength = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0 || matrix[i][j] == '0')
          dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
        else
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        maxLength = max(maxLength, dp[i][j]);
      }

    return maxLength * maxLength;
    }
};

/*GFG

  int solve(vector<vector<char>>& mat,int i,int j,int & maxi,vector<vector <int>>&dp)
   {
      
       if(i>=mat.size() || j>=mat[0].size())
       {
           return 0;
       }
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
         int right=solve(mat,i,j+1,maxi,dp);
         int bottom=solve(mat,i+1,j,maxi,dp);
         int diagonal=solve(mat,i+1,j+1,maxi,dp);
         if(dp[i][j])
         {
            dp[i][j]=1+min(right,min(bottom,diagonal));
            maxi=max(maxi,dp[i][j]);
             return dp[i][j];
         }
         else
         {
             return dp[i][j]=0;
         }
     }
 
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        int n = matrix.size();
        int m=matrix[0].size();
        vector<vector <int>> dp(n,vector<int>(m,-1));
        solve(matrix,0,0,maxi,dp);
        return maxi;
            
        
    }
};
*/