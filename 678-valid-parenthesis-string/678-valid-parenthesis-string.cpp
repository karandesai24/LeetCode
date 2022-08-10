class Solution {
public:
    bool checkValidString(string s) {
         int maxdiff = 0, mindiff = 0;
        // diff means left - right
        for(int i=0; i<s.length(); i++){
            maxdiff += ( s[i] == '(' || s[i] == '*' ) ? 1 : -1;
            mindiff += ( s[i] == ')' || s[i] == '*' ) ? -1 : 1;
            if( maxdiff < 0 ) return false;
            mindiff = std::max( 0, mindiff);
        } return mindiff == 0;
        
    }
};