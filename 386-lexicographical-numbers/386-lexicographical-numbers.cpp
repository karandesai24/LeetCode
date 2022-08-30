class Solution {
 
    static bool mycomp(int n1,int n2)
    {
        string a=to_string(n1);
        string b=to_string(n2);
        if(a<b)
            return true;
        else
            return false;
        
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++)
            ans.push_back(i);
        sort(ans.begin(),ans.end(),mycomp);
        return ans;
        
    }
};