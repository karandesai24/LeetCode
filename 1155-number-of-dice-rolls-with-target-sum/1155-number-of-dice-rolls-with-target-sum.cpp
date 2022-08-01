class Solution {
public:
    long long solvemem(int dices,int faces,int target,
   vector<vector<long long> > &dp)
   {
          constexpr int kMod = 1e9 + 7;
       if(target<0)
           return 0;
       if(dices ==0 && target!=0)
           return 0;
       if(dices==0 && target==0)
           return 1;
       
       
       if(dp[dices][target]!=-1)
           return dp[dices][target];
           
       long long ans = 0;
       for(int i=1;i<=faces;i++)
       {
           ans = (ans%1000000007 + solvemem(dices-1,faces,target-i,dp)%1000000007)%1000000007;
          
       }
       
       return dp[dices][target] = ans;
   }
    
    int numRollsToTarget(int N, int M, int X) {
         vector<vector<long long> >dp(N+1,vector<long long>(X+1,-1));
       return solvemem(N,M,X,dp);
        
    }
};
/*
vector<vector<long long>> dp;
    long long fn(int sum,int M,int i,int N){
        if(i==N)
            return sum==0;
        if(sum<=0)
            return 0;
        if(dp[i][sum]==-1){
            long long ans=0;
            for(int j=1;j<=M;j++)
                ans+=fn(sum-j,M,i+1,N);
            dp[i][sum]=ans;
        }
        return dp[i][sum];
        
    }
  
    long long noOfWays(int M , int N , int X) {
          dp.resize(N,vector<long long>(X+1,-1));
        return fn(X,M,0,N);
    }
    */