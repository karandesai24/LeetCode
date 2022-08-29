class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s; int count;
        for(auto i: nums) s.insert(i);
        int maxi=0;
        for(auto i: nums) {
            count = 1;
            if(s.count(i-1)) {
                continue;
            } else {
                int count=1;
                int temp = i+1;
                while(s.count(temp)) {
                    count++;
                    temp++;
                }
                maxi = max(count, maxi);
            }
        }
        return maxi;
    }
};