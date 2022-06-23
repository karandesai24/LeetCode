class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int siz = nums.size();
        int i = siz - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) 
        {
            int j = siz - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[j], nums[i]);
        }

    reverse(nums.begin() + i + 1, nums.end());
        
    }
};