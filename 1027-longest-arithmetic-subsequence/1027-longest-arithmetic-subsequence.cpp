class Solution {
public:
     int dp[1002][1002];
    int solve(vector<int>& arr, int n){
        int ans = 0;
       for(int i=1; i<n; ++i){
           for(int j=i-1; j>=0; --j){
               int dif = arr[i]-arr[j]+500; //converting negative(-ve) difference to positive
               //example 1 (-ve dif) :- dif = -251, we convert -251 to -251+500 = 249
               //example 2 (+ve dif) :- dif = 251, we convert 251 to 251+500 = 751
               dp[i][dif] = max(dp[i][dif], 1+dp[j][dif]);
               ans = max(ans, dp[i][dif]);
           }
       }
       return ans+1;
    }
    int longestArithSeqLength(vector<int>& nums) {
          memset(dp,0,sizeof(dp));
        int n = nums.size();
        return solve(nums,n);
    }
};