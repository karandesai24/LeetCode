class Solution {
public:
    string longestPalindrome(string s) {
                if(s == "" || s.size() == 0){
            return "";
        }

        int maxLength = 1;
        int i, j;
        int low, high;
        int start = 0;

        for(i = 1; i < s.size(); i++){
            // check for even length palindrome substring
            low = i - 1;
            high = i;

            while(low >= 0 && high < s.size() && s[low] == s[high]){
                if(high - low + 1 > maxLength) {
                    start = low;
                    maxLength = high - low + 1;
                }
                low--;
                high++;
            }

            // check for odd length palindrome substring
            low = i - 1;
            high = i + 1;

            while(low >= 0 && high < s.size() && s[low] == s[high]){
                if(high - low + 1 > maxLength) {
                    start = low;
                    maxLength = high - low + 1;
                }
                low--;
                high++;
            }
        }

        return s.substr(start, maxLength);
    }
};