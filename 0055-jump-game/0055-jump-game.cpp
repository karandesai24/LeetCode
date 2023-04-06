class Solution {
public:
    bool canJump(vector<int>& nums) {
        int close = nums.size()-1;
        for(int i=close;i>=0;i--){
            if(i+nums[i] >= close) close = i;
        }

        return close == 0;
    }
};
/*
bool canJump(vector<int>& nums) {
        int maxReachablePosition = 0;
        for(int i=0;i<nums.size();i++){
            // This Implies I can't reach the current Index
            if(maxReachablePosition < i)
                return false;
            maxReachablePosition = max(maxReachablePosition, i+nums[i]);
            // If I can reach last Index
            if(maxReachablePosition > nums.size() - 2)
                return true;
        }
        return true;
    }*/