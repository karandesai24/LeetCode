class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
      sort(satisfaction.rbegin(), satisfaction.rend());
        
        int ans = 0, sum = 0;
        for(int i = 0; i < satisfaction.size() && satisfaction[i] + sum > 0; i++)
        {
          
            sum += satisfaction[i];
            ans += sum;
        }
        
        return ans;  
    }
};
/*
int solve(vector<int> & satisfaction,int index,int time,vector<vector <int>>&dp)
   {
      
       if(index==satisfaction.size())ndex
       {
           return 0;
       }
       if(dp[index][time]!=-1){
           return dp[index][time];
       }
         int include=satisfaction[index]*(time+1)+ solve(satisfaction,index+1,time+1,dp);
         int exclude=0+ solve(satisfaction,index+1,time,dp);
         return dp[index][time]=max(include,exclude);
        
     
        
     }
 
      int maxSatisfaction(vector<int>& satisfaction) {
     int n= satisfation.size();
        vector<vector <int>> dp(n+1,vector<int>(n+1,-1));
    
        return solve(satisfaction,0,0,dp);
            
*/