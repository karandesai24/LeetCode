class Solution {
public:
    int solve(vector<vector<int>>& c,int i,int prev,vector<vector<int>>& dp){
        if(i>=c.size()) 
            return 0;
        if(dp[i][prev+1]!=-1) 
            return dp[i][prev+1];
        int notTake = solve(c,i+1,prev,dp);
        int take = 0;
        if(prev==-1 || (c[i][0]>=c[prev][0]&& c[i][1]>=c[prev][1]&&c[i][2]>=c[prev][2]))
        {
            take = c[i][2] + solve(c,i+1,i,dp);
        }
        return dp[i][prev+1] = max(take,notTake);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        vector<vector<int>> dp(cuboids.size()+1,vector<int>(cuboids.size()+1,-1));
        for(auto &a: cuboids){
            sort(a.begin(),a.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return solve(cuboids,0,-1,dp);
    
    }
};