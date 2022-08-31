class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        map<char,int> mp;
        
        for(int i=0 ; i<n ; ++i) mp[s[i]] = i;
        stack<char> st;
        set<char> t;
        
        for(int i=0 ; i<n ; ++i){
            if(t.find(s[i]) != t.end()) continue;
          
            while(!st.empty() && s[i] < st.top() && mp[st.top()] > i){
                t.erase(st.top());
                st.pop();
            }
            st.push(s[i]);
            t.insert(s[i]);
            
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};