class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n = nums.size();
        
        deque<int>dp;        
        vector<int>res;
        
        for(int i=0; i<n; i++){
            if(!dp.empty() && dp.front()+k <= i) dp.pop_front();
            while(!dp.empty() && nums[dp.back()] < nums[i]) dp.pop_back();
            
            dp.push_back(i);
            if(i >= k-1) res.push_back(nums[dp.front()]);
        }
        
        return res;
    }
};