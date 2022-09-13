class Solution {
public:
    
    int fun(vector<int>&nums,int index, int curr,vector<int>&dp){
        if(index==nums.size()){
            return 0;
        }
        if(__gcd(curr,nums[index])==1){
            return dp[index]=1;
        }
        if(dp[index]!=-1)return dp[index];
        return dp[index]=fun(nums,index+1,__gcd(curr,nums[index]),dp)|fun(nums,index+1,curr,dp);
    }
    bool isGoodArray(vector<int>& nums) {
        if(nums.size()==1 and nums[0]==1)return 1;
        if(nums.size()==1)return 0;
        vector<int>dp(nums.size()+1,-1);
        return fun(nums,1,nums[0],dp);
       
    }
};
/*
int gcd(int a , int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int gcd_arr(vector<int> & v1)
{
    int ans=v1[0];
    for (int i=0;i<v1.size();i++)
    {
        ans=gcd(v1[i],ans);
    }
    return ans;
}
bool isGoodArray(vector<int>& nums) 
{
    return gcd_arr(nums)==1 ? true:false;
}
*/