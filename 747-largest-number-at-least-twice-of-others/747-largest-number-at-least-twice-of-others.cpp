class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
            int maxi = 0;
            int ind;
            for (int i = 0; i < n; i++)
            {
                if (maxi < nums[i])
                {
                    maxi = nums[i];
                    ind = i;
                }
            }
            sort(nums.begin(), nums.end());
            for (int j = 0; j < n - 1; j++)
            {
                if (nums[j] *2 > maxi)
                    return -1;
            }
            return ind;
    }
};