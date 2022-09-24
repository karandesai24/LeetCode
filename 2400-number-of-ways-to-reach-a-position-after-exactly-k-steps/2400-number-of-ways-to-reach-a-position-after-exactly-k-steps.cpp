class Solution {
	public:
		int mod=1e9+7;
		int find(int i,int k,int e,vector<vector<int>>& dp){
			if(!k){
				if(i==e) return 1;
				return 0;
			}
			if(dp[i+1000][k]!=-1) return dp[i+1000][k];
			int pos=find(i+1,k-1,e,dp);
			int neg=find(i-1,k-1,e,dp);
			return dp[i+1000][k]=(pos+neg)%mod;
		}

		int numberOfWays(int s, int e, int k) {
			vector<vector<int>> dp(3000,vector<int>(k+1,-1));
			return find(s,k,e,dp)%mod;
		}
	};