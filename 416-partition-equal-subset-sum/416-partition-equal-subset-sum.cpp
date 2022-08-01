class Solution {
public:
     bool canPartition(vector<int>& nums) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    if (sum & 1)
      return false;
    return knapsack(nums, sum / 2);
  }

 private:
  bool knapsack(const vector<int>& nums, int subsetSum) {
    // dp[i] := true if i can be formed by nums so far
    vector<bool> dp(subsetSum + 1);
    dp[0] = true;

    for (const int num : nums)
      for (int i = subsetSum; i >= num; --i)
        dp[i] = dp[i] || dp[i - num];

    return dp[subsetSum];

    }
};
/*
GFG
class Solution{
public:
    int solveTab(int arr[],int n,int t){
       vector<vector<int>> dp(n+1,vector<int>(t+1,0));
       
       for(int i=0;i<n;i++) dp[i][0]=1; 
       for(int index=n-1;index>=0;index--){
           
           
           for(int target=1;target<=t;target++){
               
                   int inc=0;
                   if(target-arr[index] >=0)
                       inc = dp[index+1][target-arr[index]];
                   int exc = dp[index+1][target];
                   
                   dp[index][target] = max(inc,exc);
           }
           
       }
       return dp[0][t];
       
   }
    int equalPartition(int N, int arr[])
    {
    int sum = accumulate(arr,arr+N,0);
       if(sum &1) 
       return 0;
       int target = sum/2;

      
       
       return solveTab(arr,N,target);
    }
};
*/