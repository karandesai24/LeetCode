class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       long size = arr.size(), res = 0;
        vector<vector<int>> dp( size+1, vector<int>(2,0)); 
        // dp[i][0] for odd, dp[i][1] for even
        constexpr int modulo = 1e9 + 7;
        for(int i=1; i<=size; i++){
            if( arr[i-1] % 2 == 1 ){ // new number is odd
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = dp[i-1][0];
            } else { // new number is even
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
            } res += dp[i][0];
        } return res % modulo;
    }
};