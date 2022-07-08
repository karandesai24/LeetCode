class Solution {
public:
    int majorityElement(vector<int>& a) {
         map<int, int> mp;
    for (int i = 0;i < a.size();i++) {
        mp[a[i]]++;
    }
    for (auto i : mp) {
        if (i.second > a.size() / 2) {
            return i.first;
        }
    }
    return -1;
        
    }
};