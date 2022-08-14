class Solution {
public:
    int cal(vector<vector<int>> &dp,vector<int> &cuts, int st, int en, int left, int right)
    {
        int mn=INT_MAX;
        if(st>en)
            return 0;
        if(dp[st][en]!=-1)
            return dp[st][en];
        
        for(int i=st;i<=en;i++)
        {
            mn=min(mn, right-left+cal(dp,cuts, i+1, en, cuts[i], right)+cal(dp,cuts, st, i-1, left, cuts[i]));
        }
        
        return dp[st][en] = mn;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1));
        return cal(dp,cuts,0,cuts.size()-1,0,n);
    }
};