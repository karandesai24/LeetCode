class Solution {
public:
    int solve(int index,vector<int>& slices,int n,int end,vector<vector <int>>&dp)
   {
      
       if(n==0|| index>end)
       {
           return 0;
       }
       if(dp[index][n]!=-1){
           return dp[index][n];
       }
         int take=slices[index]+ solve(index+2,slices,n-1,end,dp);
         int nottake=0+ solve(index+1,slices,n,end,dp);
         return dp[index][n]=max(take,nottake);
        
     
        
     }
 
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector <int>> dp1(k,vector<int>(k,-1));
       
        int case1=solve(0,slices,k/3,k-2,dp1);
          vector<vector <int>> dp2(k,vector<int>(k,-1));
        int case2=solve(1,slices,k/3,k-1,dp2);
            return max(case1,case2);
        
    }
};