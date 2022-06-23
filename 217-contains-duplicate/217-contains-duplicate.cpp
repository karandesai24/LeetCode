class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>  count_map;
        for(int i:nums)
            count_map[i]++;
            for(int i:nums)
            {
                if(count_map[i]>=2) return true;
            }
        return false;
        
        
    }
};