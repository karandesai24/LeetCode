class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX;
    
    for(auto &x: nums)
    {
     if(abs(x) < abs(ans))
     {
         ans = x;
     }
        
     else if(abs(x) == abs(ans))
     {
         ans = max(ans,x)    ;
     }
             
    }
    
   return ans;
    }
};