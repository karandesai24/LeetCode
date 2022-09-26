class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
         size_t n = arr.size();
        
        vector<int> smallest_geq(n, -1);
        vector<int> largest_leq(n, -1);
        
        map<int,int> mp;
        for(int i = n - 1; i >= 0; i --)
        {
            auto it = mp.lower_bound(arr[i]);
            if(it != mp.end())
            {
                smallest_geq[i] = it->second;
                if(it->first == arr[i])
                {
                    largest_leq[i] = it->second;
                }
            }
            if(largest_leq[i] == -1 && it != mp.begin())
            {
                it--;
                largest_leq[i] = it->second;
            }
            mp[arr[i]] = i;
        }
        
        vector<vector<char>> dp(n, vector<char>(2, 0));
        dp[n-1] = {1, 1};
        
        int ans = 1;
        for(int i = n - 2; i >= 0; i --)
        {
            //odd_numbered
            {
                int j = smallest_geq[i];
                dp[i][0] = j == -1 ? 0 : dp[j][1];
            }
            
            //even_numbered
            {
                int j = largest_leq[i];
                dp[i][1] = j == -1 ? 0 : dp[j][0];
            }
            
            ans += dp[i][0];
        }
        
        return ans;
    }
};