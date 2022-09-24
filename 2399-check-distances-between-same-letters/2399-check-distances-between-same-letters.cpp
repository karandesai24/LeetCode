class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
      unordered_map<char,vector<int>> mp;
        int size=s.size();
        for(int i=0;i<size;i++)
            mp[s[i]].push_back(i);
        for(auto it:mp){
            int ind=it.first - 'a',diff=it.second[1]-it.second[0]-1;
            if(distance[ind]!=diff)
                return false;
        }
        return true;
        
        
    }
};