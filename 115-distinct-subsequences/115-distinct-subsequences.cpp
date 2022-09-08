class Solution {
public:
    int numDistinct(string s, string t) {
      int n = s.size();
	int m = t.size();

	vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
	
	for (int i = 0; i <= n; i++) 
        dp[i][0] = 1;
	for (int j = 1; j <= m; j++)
        dp[0][j] = 0; 

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) 
            { 
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]%1000000007;
			}
			else 
            {
				dp[i][j] = dp[i - 1][j]%1000000007;
			}
		}
	}
	return dp[n][m];  
    }
};
/*
class Solution {
public:
	int solve(string& s,string& t,int i,int j,vector<vector<int>>& dp){
		if(i>=s.length()&&j<t.length()){
			return 0;
		}
		if(j>=t.length())return 1;
		if(dp[i][j]!=-1)return dp[i][j];
		int ans = 0;
		if(s[i]==t[j]){
		// there are 2 possibilities 1. take it 2. not take it
			ans += solve(s,t,i+1,j+1,dp); 
			ans += solve(s,t,i+1,j,dp);
		}
		else{
			ans += solve(s,t,i+1,j,dp);
		}
		return dp[i][j] = ans;
	}
	int numDistinct(string s, string t) {
		vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
		return solve(s,t,0,0,dp);
	}
};
*/
