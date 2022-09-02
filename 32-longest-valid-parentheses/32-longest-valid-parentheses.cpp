class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> brackets;
        stack<int> index;
        index.push(-1);
        
        int len=0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                brackets.push(s[i]);
                index.push(i);
            }else{ // closing bracket
                if(!brackets.empty() && brackets.top() == '('){
                    brackets.pop();
                    index.pop();
                    len = max(len, i-index.top());
                }else{ // rougue closing bracket
                    brackets.push(s[i]);
                    index.push(i);
                }
            }
        }
        
        return len;
    }
};