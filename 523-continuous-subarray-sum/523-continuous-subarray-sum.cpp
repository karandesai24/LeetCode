class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         unordered_map<int, int> prefixToIndex{{0, -1}};
    int prefix = 0;

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      if (k != 0)
        prefix %= k;
      if (prefixToIndex.count(prefix)) {
        if (i - prefixToIndex[prefix] > 1)
          return true;
      } else {
        // only add if absent, because the previous index is better
        prefixToIndex[prefix] = i;
      }
    }

    return false;
    }
};
/*
  int curPrefixSum = 0, res = 0;
        // maintain an hashmap to store the prefixSum%k & it's first occurrence index
        unordered_map<int,int> mp{{0,-1}};
        for(int i=0; i<nums.size(); i++){
            curPrefixSum = k != 0 ? ( curPrefixSum + nums[i] ) % k : curPrefixSum + nums[i];
            if( mp.find( curPrefixSum ) != mp.end() ){
                res = std::max( res, i-mp[curPrefixSum]);
                if( res > 1 ) return true;
            } else mp[curPrefixSum] = i;
        } return false;
        */