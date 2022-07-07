class Solution {
public:
    string reverseWords(string s) {
         vector<string> v;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                ans += s[i];
            }
            else
            {
                if (ans.size() != 0)
                    v.push_back(ans);
                ans = "";
            }
        }
        if (ans.size() != 0)                                                           
            v.push_back(ans);
        ans = "";
        for (int i = v.size() - 1; i > 0; i--)
        {
            ans += (v[i]);
            ans += ' ';
        }
        ans += v[0];
        return ans;
    }
};