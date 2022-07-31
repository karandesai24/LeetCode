class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, res);
        return res;
    }
private:
    void dfs(vector<int>& candidates, int target_now, int idx, vector<int>& cur, vector<vector<int>>& res){
        if( target_now == 0 ){ 
            // found
            res.push_back(cur);
            return;
        }
        // find next
        for(int i=idx; i<candidates.size(); i++){
            if( candidates[i] > target_now ) return; // pruning
            cur.push_back( candidates[i] );
            dfs( candidates, target_now - candidates[i], i, cur, res);
            cur.pop_back();
        }
    }
};