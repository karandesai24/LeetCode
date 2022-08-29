class Solution {
public:
    vector<int> partitionLabels(string s) {
         vector<int> ans;
    int count=0;
    unordered_map<char,int> mp;
    unordered_map<char,int> newMp;
    for(auto it:s)
        mp[it]++;
    for(int i=0;i<s.size();i++){
        newMp[s[i]]++;
        if(mp[s[i]]==newMp[s[i]]){
            count+=mp[s[i]];
            newMp.erase(s[i]);
            if(newMp.size()==0){
                ans.push_back(count);
                count=0;
            }
        }
    }
    return ans;
    }
};