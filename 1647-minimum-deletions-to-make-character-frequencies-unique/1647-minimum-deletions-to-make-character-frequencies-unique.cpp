class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26);
        for (const auto& c : s) {
            ++count[c - 'a'];
        }
        int result = 0;
        unordered_set<int> lookup;
        for (int i = 0; i < 26; ++i) {
            for (int c = count[i]; c > 0; --c, ++result) {
                if (!lookup.count(c)) {
                    lookup.emplace(c);
                    break;
                }
            }
        }
        return result;
        
    }
};


/*
class Solution {
public:
    int minDeletions(string s) {
         unordered_map<char, int> umap;
        unordered_set<int> visited;
        
        for(auto c : s) 
            umap[c]++;
        int ans = 0;
        for(auto m : umap)
        {
            while(visited.count(m.second))
            {
                m.second--;
                ans++;
            }
            if(m.second) visited.insert(m.second);
        }
        return ans;
       
    }
};
/*
 int res = 0;
        unordered_map<char,int> char_mp;
        for(char ch : s) 
            char_mp[ch]++;
        unordered_map<int,int> freq_mp;
        for(auto iter = char_mp.begin(); iter != char_mp.end(); iter++){
          
            while( freq_mp.find(iter->second) != freq_mp.end() ){
                iter->second--;
                res++;
            } if( iter->second ) freq_mp[iter->second]++;
        } return res;
    

 int minDeletions(string s) {
    vector<int> freq(26);
    for (char c : s) ++freq[c - 'a'];    
    unordered_set<int> seen;
    int ans = 0;
    for (int f : freq) {
      while (f && !seen.insert(f).second) {        
        --f;
        ++ans;
      }
    }
    return ans;
  }
  
  */
