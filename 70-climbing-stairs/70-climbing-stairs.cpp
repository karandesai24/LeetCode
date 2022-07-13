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