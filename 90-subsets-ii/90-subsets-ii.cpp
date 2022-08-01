class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(begin(nums), end(nums));
    dfs(nums, 0, temp, ans);
    return ans;
  }

 private:
  void dfs(const vector<int>& nums, int s, vector<int>& temp,
           vector<vector<int>>& ans) {
    ans.push_back(temp);

    for (int i = s; i < nums.size(); ++i) {
      if (i > s && nums[i] == nums[i - 1])
        continue;
      temp.push_back(nums[i]);
      dfs(nums, i + 1, temp, ans);
      temp.pop_back();
    }  
    }
};