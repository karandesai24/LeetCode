class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& comp) {
         int n=comp.size();
        vector<int> res;
        
        for(auto &x:comp) sort(x.begin(),x.end());
        
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<n&&!f;j++){
                if(i!=j){
                    f=includes(comp[j].begin(),comp[j].end(),comp[i].begin(),comp[i].end());
                }
            }
            if(!f) res.push_back(i);
        }
        return res;
    
    }
};
/*
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fav) {
        set<string> st;
        for (const vector<string> &x: fav) {
            for (const string &s: x) {
                st.insert(s);
            }
        }
        int id = 1;
        unordered_map<string, int> mp;
        for (const string &s: st) {
            mp[s] = id++;
        }
        int n = fav.size();
        vector<unordered_set<int>> v(n);
        for (int i = 0; i < n; i++) {
            for (const string &s: fav[i]) {
                v[i].insert(mp[s]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool good = true;
            for (int j = 0; j < n; j++) {
                if (i != j) { // is vi subset of vj => is any element in vi not in vj
                    bool ok = true;
                    for (const int &x: v[i]) {
                        if (v[j].count(x) == 0) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        good = false;
                        break;
                    }
                }
            }
            if (good) ans.push_back(i);
        }
        return ans;
    }
};
*/