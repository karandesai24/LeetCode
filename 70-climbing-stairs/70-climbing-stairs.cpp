class Solution {
public:
    int climbStairs(int n) {
         vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
        
    }
};
/*
class Solution { // Space Optimized
public:
    int climbStairs(int n) {
        if( n < 2 ) return 1;
        int dp = 0, dp_1 = 1, dp_2 = 1;
        for(int i=2; i<=n; i++){
            dp = dp_1 + dp_2;
            dp_2 = dp_1;
            dp_1 = dp;
        } return dp_1;
    }
};

*/
/*
int countDistinctWayToClimbStair(long long nStairs)
{
    //base case
    if(nStairs < 0)
        return 0;
    
    if(nStairs == 0)
        return 1;
    
    //R.C
    int ans = countDistinctWayToClimbStair(nStairs-1) 
        + countDistinctWayToClimbStair(nStairs-2);
    
    return ans;
}*/
