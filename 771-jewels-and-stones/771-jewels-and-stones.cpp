class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int sum = 0;
        unordered_map<char,int> dict;
        for(auto j: jewels) 
            dict[j]++;
        for(auto s: stones) 
            if( dict.count(s))
                sum++;
        return sum;
    }
};