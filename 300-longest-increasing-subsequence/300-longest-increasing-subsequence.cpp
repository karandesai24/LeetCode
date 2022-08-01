class Solution {
public:
    int solve(vector<int>& nums,int n)
        
    {
        if(n==0)
            return 0;
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else 
            {
                int index= lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        return solve(nums,n);
      
    }
};
/*
GFG
class Solution
{
    public:
    int solve(int n, int a[],int curr,int prev, vector <vector<int>>& dp)
    {
        if(curr==n)
        return 0;
        
        if(dp[curr][prev+1]!=-1)
        {
            return dp[curr][prev+1];
        }
        
        int take=0;
        if(prev==-1 || a[curr]>a[prev])
      
            take=1+solve(n,a,curr+1,curr,dp);
    
        int notTake=0+solve(n,a,curr+1,prev,dp);
        return dp[curr][prev+1]=max(take,notTake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
     vector <vector<int>> dp(n,vector<int>(n+1,-1));
     return solve(n,a,0,-1,dp);
    }
};
*/