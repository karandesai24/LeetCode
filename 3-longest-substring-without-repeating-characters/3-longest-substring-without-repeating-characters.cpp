class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
    vector<int> count(128);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      ++count[s[r]];
      while (count[s[r]] > 1)
        --count[s[l++]];
      ans = max(ans, r - l + 1);
    }

    return ans;
        
    }
};

/*
  int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> position(128, -1);
        int ans = 0;
        
        for(int i = 0, j = 0; j < n; j++){
            if(position[s[j]] != -1){
                i = max(i, position[s[j]]+1);
            }
            ans = max(ans, j-i+1);
            position[s[j]] = j;
        }
        
        return ans;
    }
    */
