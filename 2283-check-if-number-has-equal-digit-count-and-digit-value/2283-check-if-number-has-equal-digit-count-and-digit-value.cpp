class Solution {
public:
    bool digitCount(string A) {
        map<int , int>g;
        for (char i : A)
            g[i - '0']++;
        for (int i = 0 ; i < A.size() ; i++)
        {
            if (g[i] != A[i] - '0') 
                return false;
        };
        return true;
    }
};
/*
bool ct = true;
        for(int i = 0; i < num.length(); i++){
            if(num[i]-'0' != count(num.begin(),num.end(), '0'+i))
                ct = false;
        }
        return ct;
        */