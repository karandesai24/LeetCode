class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n = nums.size() ;
        int ans = nums[0], prodfromLeft = 1, prodfromRight = 1 ;
        
        for(int i = 0; i<n ; i++){
            prodfromLeft *= nums[i] ;
            prodfromRight *= nums[n-1-i] ;
			
            ans = max({prodfromLeft, prodfromRight, ans}) ;
            
            if(prodfromLeft == 0) prodfromLeft = 1 ;
            if(prodfromRight == 0) prodfromRight = 1 ;
        }
        return ans ;
    }
};