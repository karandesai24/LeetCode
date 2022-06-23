class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    int max_sum=INT_MIN;
    int cur=0;
    for(auto x:nums)
    {
        if(cur<0) cur=0;
        cur += x;
        max_sum =  max(max_sum , cur);
    }
    return max_sum;
        
        
    }
};