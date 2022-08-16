class Solution {
public:
    vector<string> findWords(vector<string>& words) {
         unordered_map<char, int> mp;
        for(char c : "qwertyuiop") mp[c] = 1;
        for(char c : "asdfghjkl") mp[c] = 2;
        for(char c : "zxcvbnm") mp[c] = 3;
        vector<string> res;
        for(string word : words){
            string w = word; 
            transform(w.begin(), w.end(), w.begin(), ::tolower);
            int ok = mp[w[0]];
            for(char c : w){
                if(mp[c] != ok){
                    ok = 0;
                    break;
                }
            }
            if(ok) res.push_back(word);
        }
        return res;
    }
};