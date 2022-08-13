class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int n = nums.size();
        vector<bool> ans(n+1,false);
        
        for(int i=0;i<n;i++)
            if(nums[i]>0 && nums[i]<=n)
                ans[nums[i]]=true;
        
        int count = n+1;
        for(int i=1;i<n+1;i++){
            if(ans[i]==false){
                count = i;
                break;
            }
        }     
        return count;            
    }
};