class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> subresults(n+1, vector<int>(m+1, 0));
        for(auto& str : strs){
            int n_ones = count(str.begin(), str.end(), '1');
            int n_zeroes = count(str.begin(), str.end(), '0');
            for(int i=n; i>=n_ones; i--){
                for(int j=m; j>=n_zeroes; j--){
                    subresults[i][j] = max( subresults[i][j], 
                                            subresults[i-n_ones][j-n_zeroes] + 1);
                }
            }
        } return subresults[n][m];
    }
};
/*
class Solution {
private:
    int subproblem(vector<pair<int,int>> mp, int cur_idx, int nZeros, int nOnes){
        
        if( cur_idx == mp.size() || ( nZeros == 0 && nOnes == 0 ) ) 
        return 0;
        if( mp[cur_idx].first > nZeros || mp[cur_idx].second > nOnes )  
            return subproblem(mp, cur_idx+1, nZeros, nOnes);
       
        int include = 1 + subproblem(mp, cur_idx+1,nZeros - mp[cur_idx].first, 
                                     nOnes - mp[cur_idx].second);
        int exclude = subproblem(mp, cur_idx+1, nZeros, nOnes);
        return max(include, exclude);
    }
public:
    int findMaxForm(vector<string>& strs, int nZeros, int nOnes) {
       
       
        vector<pair<int,int>> mp;
        for(auto& str : strs){
            int zeros = count(str.begin(), str.end(), '0');
            int ones = count(str.begin(), str.end(), '1');
            mp.push_back({zeros, ones});
        } return subproblem(mp, 0, nZeros, nOnes);
    }
};
*/