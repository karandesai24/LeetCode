class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
         unordered_map<string,int> w1,w2;
        int c=0;
        for(auto i:words1)
            w1[i]++;
        for(auto i:words2)
            w2[i]++;
        for(auto i:w1)
            if(i.second==1&&w2[i.first]==1)
                c++;
        return c;
    }
};