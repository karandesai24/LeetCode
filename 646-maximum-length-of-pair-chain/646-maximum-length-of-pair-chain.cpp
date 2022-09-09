class Solution {
public:
    int solve(int i,int prev,int n,vector<vector<int>>& nums,vector<vector<int>> &dp){
        if(i==n) 
            return 0;
        if(dp[i][prev+1] !=-1) 
            return dp[i][prev+1];
        
        int take=0;
        if(prev==-1 || nums[i][0] > nums[prev][1])
        {
            take = 1 + solve(i+1,i,n,nums,dp);
        }
        int ntk = solve(i+1,prev,n,nums,dp);
        return dp[i][prev+1] =max(take,ntk);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>> dp(pairs.size(),vector<int>(2005,-1));
        sort(pairs.begin(),pairs.end());
        return solve(0,-1,pairs.size(),pairs,dp);
    }
};