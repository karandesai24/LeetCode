class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        vector<char> roman{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        vector<int> value{1000, 500, 100, 50, 10, 5, 1};
        unordered_map<char,int> mp;
        for(int i=0; i<7; i++) mp[roman[i]] = value[i];
        for(int i=0; i<s.length(); i++){
            if( i<s.length()-1 && mp[s[i]] < mp[s[i+1]] ){
                // cases: IV, IX, XL, XC, CD, CM
                res -= mp[s[i]];
            } else { // general cases
                res += mp[s[i]];
            }
        } return res;
        
    }
};