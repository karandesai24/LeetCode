class Solution {
public:
    int numDecodings(string s) {
        
        vector<int> dp(s.size(), -1);
        return helper(s, 0, dp);
    }
     
    int helper(string &s, int i, vector<int> &dp)
    {
        if(i >= s.size())
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int tmp = helper(s, i + 1, dp); // Considering only one digit
        
        if(i < s.size() - 1 && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)
            tmp += helper(s, i + 2, dp); // Considering first two digits;
            
        return dp[i] = tmp;
    }
};
