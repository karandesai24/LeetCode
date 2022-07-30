class Solution {
public:
    int rob(vector<int>& nums) {
          vector<int> dp(nums.size(),-1);
        return rob_ornot(nums, nums.size()-1, dp);
    }
private:
    int rob_ornot(vector<int>& nums, int i, vector<int>& dp){
        if( i < 0 ) return 0;
        if( dp[i] >= 0 ) return dp[i]; // recorded
        return dp[i] = max( rob_ornot( nums, i-2, dp) + nums[i], 
                            rob_ornot(nums, i-1, dp));
    }
};