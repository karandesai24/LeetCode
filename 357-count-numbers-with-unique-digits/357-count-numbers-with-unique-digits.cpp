class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    if(n == 0) 
        return 1;
		n = min(10,n);
		vector<int> dp(n+1);
		dp[0] = 1;
		dp[1] = 10;
		for(int i = 2 ; i <= n ; i++){
			dp[i] = (dp[i-1] - dp[i-2]) * (11 - i) + dp[i-1];
		}
		return dp[n];

    }
};
/*

     int vis[10];
    int dp[9][2];
    int helper(int n , int starting)
    {
        if(n == 0)
            return 0;
        else if(dp[n][starting]!=-1)
            return dp[n][starting];
        int ans = 0;
        for(int i = 0 ; i<10 ;i++)
        {
            if(i == 0 and starting)
                continue;
            if(vis[i])continue;
            vis[i] = 1;
            ans = ans +  helper(n-1 , 0) + 1;
            vis[i] = 0;
            
        }
        return dp[n][starting] = ans;
    }
    int countNumbersWithUniqueDigits(int n) {
          memset(vis , 0 , sizeof vis);
        memset(dp , -1 , sizeof dp);

        return helper(n , 1)+1;
*/