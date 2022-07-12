class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        
       
        vector<int> heights(n+1);
        int ans = 0;
        
        for(int i = 0; i < m; i++){
          
            stack<int> stk;
           
            for(int j = 0; j < heights.size(); j++){
                
                if(j < n){
                    heights[j] = (matrix[i][j] == '1') ? heights[j]+1 : 0;
                }
                
                while(!stk.empty() && heights[j] < heights[stk.top()]){
                    int cur = stk.top(); stk.pop();
                    ans = max(ans, heights[cur] * (stk.empty() ? j : (j-1-stk.top())));
                }
                stk.push(j);
            }
        }
        
        return ans;
        
    }
};