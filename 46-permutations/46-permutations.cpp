class Solution {
public:
       void traversal(vector<int>& nums, vector<int>& cur, 
                   vector<bool>& used, vector<vector<int>>& res){
        if( cur.size() == nums.size() ){
            res.push_back(cur);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if( used[i] ) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            traversal(nums, cur, used, res);
            cur.pop_back();
            used[i] = false;
        }   
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if( nums.size() == 0 ) return res;
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        traversal(nums, cur, used, res);
        return res;
    }

};