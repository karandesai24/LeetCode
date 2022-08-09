class Solution {
public:
    int countVowelStrings(int n) {
         int a=1, e=1, i=1, o=1, u=1;
        
        while(--n){
            o += u;
            i += o;
            e += i;
            a += e;
        }
        
        return a+e+i+o+u;
        
    }
};
/*
vector<char> vowels = {'a','e','i','o','u'};
        int res = 0;
        string tmp;
        backtrack(vowels, res, n, tmp);
        return res;
    }
private:
    void backtrack(vector<char>& vowels, int& res, int& length, string& tmp){
        if( tmp.length() == length ){
            res++;
            return;
        }
        char base = tmp.back();
        for(const char& vowel : vowels){
            if( vowel < base ) continue;
            tmp += vowel;
            backtrack(vowels, res, length, tmp);
            tmp.pop_back();
        }
        */