class Solution {
public:
  void dfs(vector<int>& nums, int idx, int target, int& res){
        if( target == 0 && idx == nums.size() ){
            res++;
            return;
        } if( idx >= nums.size() ) return;
        dfs(nums, idx + 1, target + nums[idx], res);
        dfs(nums, idx + 1, target - nums[idx], res);
    }
    

    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        dfs(nums, 0, target, res);
        return res;
        
    }
};