class Solution {
public:
    bool detectCapitalUse(string word) {
         int upper = 0;
        for(char ch: word)
        {
            if( isupper(ch) )
                upper++;
        } 
        return upper == 0 || upper == word.length() || ( upper == 1 && isupper(word[0]));
    }
};