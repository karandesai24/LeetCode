class Solution {
public:
    int longestPalindromeSubseq(string s) {
         int n= s.size();
        string s1=s;
        reverse(s1.begin(),s1.end());
        int dp[1001][1001];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
         
                else if(s[i-1]==s1[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
          
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
};