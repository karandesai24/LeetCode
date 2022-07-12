class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, st1;
         int sc = 0; 
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(' || s[i] == '*')
                st.push(s[i]);
            else
                if (st.empty())
                    return false;
                else {
                    while (!st.empty() && st.top() == '*') { 
                        st1.push(st.top());
                        st.pop();
                    }
                    
                    if (st.empty()) 
                        st1.pop();
                    else 
                        st.pop();
                    
                    while (!st1.empty()) { 
                        st.push(st1.top());
                        st1.pop();
                    }
                }
        }
        
       
        char c;
        
        while (!st.empty()) {
            c = st.top();
            st.pop();
            
            if (c=='*')
                sc++;
            else {
                if (sc>=1) 
                    sc--;
                else 
                    return false;
            }
        }
        
        return true;
    }
};