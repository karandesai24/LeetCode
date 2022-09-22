class Solution {
public:
    int fUtils(vector<int> &arr, int start, int end, vector<vector<int>> &dp)
    {
        if(start > end)
        {
            return 0;
        }
        
        int max_val = 0;
         if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        
         for(int i=start;i<=end;i++)
        {
            int currCost = (arr[start-1] * arr[i] * arr[end+1]) + fUtils(arr, start, i-1, dp) + fUtils(arr, i+1, end, dp); 
            
            max_val = max(max_val, currCost);
        }
        
        return dp[start][end] = max_val;
    }
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        
        return fUtils(nums, 1, n, dp);
    }
};