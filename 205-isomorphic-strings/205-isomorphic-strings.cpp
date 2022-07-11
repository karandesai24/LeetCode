class Solution {
public:
    bool isIsomorphic(string s, string t) {
         vector<int> char_s(128);
        vector<int> char_t(128);

    for (int i = 0; i < s.length(); ++i) {
      if (char_s[s[i]] != char_t[t[i]])
        return false;
      char_s[s[i]] = i + 1;
      char_t[t[i]] = i + 1;
    }

    return true;
        
    }
};