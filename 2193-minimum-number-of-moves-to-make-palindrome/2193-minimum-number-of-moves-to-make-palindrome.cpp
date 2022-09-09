class Solution {
public:
    int minMovesToMakePalindrome(string s) {
          int i = 0, j = s.size()-1, ans = 0;
        while(i < j)
        {
            while(s[i] == s[j])
            {
                if(i >= j)
                    return ans;
                i++;
                j--;
            }
            int indx = -1;
            for(int k = j-1; k > i; k--)
            {
                if(s[i] != s[k])
                    continue;
                indx = k;
                break;
            }
            if(indx != -1)
            {
                for(int k = indx; k < j; k++)
                {
                    swap(s[k], s[k+1]);
                    ans++;
                }
                i++;
                j--;
            }
            else
            {
                swap(s[i], s[i+1]);
                ans++;
            }
        }
        return ans;
    }
};