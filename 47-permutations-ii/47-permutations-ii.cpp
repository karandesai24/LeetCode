class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do{
            res.push_back(nums);
        } while (next_permutation( nums.begin(), nums.end() ) );
        return res;
    }
};
/*
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        if( nums.size() == 0 ) return res;
        vector<int> tmp;
        dfs(res, nums, used, tmp);
        return res;
    }
private: 
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<bool> used, vector<int> tmp){
        if( tmp.size() == nums.size() ){
            if( std::find(res.begin(), res.end(), tmp) == res.end() ) res.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if( !used[i] ){
                used[i] = true; tmp.push_back(nums[i]);
                dfs(res, nums, used, tmp);
                used[i] = false; tmp.pop_back();
            }
        }
    }
*/