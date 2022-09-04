class Solution {
public:
    int findMin(vector<int>& nums) {
      int s=0; int e=nums.size()-1;
    int mini=INT_MAX;
    while(s<=e)
    {
        int mid=(s+e)/2;
        mini=min(mini,nums[mid]);
        if(nums[s]<=nums[mid])
        {
            if(nums[s]<=nums[e])
                e=mid-1;
            else 
                s=mid+1;
        }
        else
        {
            e=mid-1;  
        }
    }
    return mini;  
    }
};