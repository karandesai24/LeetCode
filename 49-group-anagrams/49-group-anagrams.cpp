class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;
        for(string& str : strs){
            string tmp = str;
            std::sort(tmp.begin(), tmp.end());
            anagram_map[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for(unordered_map<string, vector<string>>::iterator 
            iter = anagram_map.begin(); 
            iter != anagram_map.end(); iter++){
            res.push_back(iter->second);
        } return res;
    }
};