class Solution {
public:
   int dp[50001];
    static bool cmp(vector<int>a,vector<int>b){
        if(a[0]<b[0]){ 
            return true;
        }
        return false;
    }
    int solve(vector<int>& start,vector<int>& End,vector<int>& profit,int i){
        if(i >= start.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int tempIdx;
        tempIdx = lower_bound(start.begin()+i,start.end(),End[i]) - start.begin(); 
		
        int choose = profit[i] + solve(start,End,profit,tempIdx);
        
        int notChoose = solve(start,End,profit,i+1);
        
        return dp[i] = max(choose,notChoose);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        int n = startTime.size();
        vector<vector<int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i = 0; i<v.size(); i++){ 
            startTime[i] = v[i][0];
            endTime[i] = v[i][1];
            profit[i] = v[i][2];
        }
        
        return solve(startTime,endTime,profit,0);
        
    }
};