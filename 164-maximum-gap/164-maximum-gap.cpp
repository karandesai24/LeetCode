class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
           
                if(nums[i+1]-nums[i]>count)
                    count=nums[i+1]-nums[i];
            
        }
        return count;
    }
};
/*
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long int maxdif = INT_MIN;
        
        if(nums.size() < 2)
            return 0;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            
            long long int gap = nums[i + 1] - nums[i];
            maxdif = max(maxdif, gap);
        }
        return maxdif;
    }
};
    */