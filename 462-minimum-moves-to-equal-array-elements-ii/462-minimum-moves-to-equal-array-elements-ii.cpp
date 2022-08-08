class Solution {
public:
    int minMoves2(vector<int>& nums) {
         const int n = nums.size();
    nth_element(begin(nums), begin(nums) + n / 2, end(nums));
    const int median = nums[n / 2];
    return accumulate(begin(nums), end(nums), 0,
                      [&](int a, int b) { return a + abs(b - median); });
        
    }
};
/*
  int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2], res = 0;
        for(int i=0; i<nums.size(); i++){
            res += abs(nums[i] - median);
        } return res;
        */
