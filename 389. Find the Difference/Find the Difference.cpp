class Solution {
public:
    char findTheDifference(string s, string t) {
        
             for(int i=0;i<s.size();i++)
		t[i+1]+=t[i]-s[i]; 
      return t[t.size()-1]; 

    
    }
};

  char findTheDifference(string s, string t) {
        int n = s.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<n; i++) if(s[i]!=t[i]) return t[i];
        return t[n];
    }

char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(auto& c:s) mp[c]+=1;
        for(auto& c:t) if(--mp[c]<0) return c;
        return '\0';
    }
