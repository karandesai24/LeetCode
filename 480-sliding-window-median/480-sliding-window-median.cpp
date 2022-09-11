class Solution {
    double medianSlidingWindowUtil(set<pair<int,int>>& se,int k){
        auto it=se.begin();
        if(k & 1){
            advance(it, k/2);
            return (double)it->first;
        }else{
            double s=0;
            advance(it, k/2-1);
            s += it->first;
            advance(it, 1);
            s += it->first;
            return s/2;
        }
     }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        set<pair<int,int>> se;
        
        int n = nums.size();
        for(int i=0;i<k;++i){
            se.insert({nums[i], i});
        }
        
        res.push_back(medianSlidingWindowUtil(se, k));
        
        for(int i=k;i<n;++i){
            se.erase({nums[i-k], i-k});
            se.insert({nums[i], i});
            res.push_back(medianSlidingWindowUtil(se, k));
        }
        return res;
    }
};