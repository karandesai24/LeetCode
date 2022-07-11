class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> data;
        for (auto &n: s) {
            data[n] ++;
        }
        unordered_set<int> d;
        for (auto &[a, b]: data) {
            d.insert(b);
            if (d.size() > 1)
                return false;
        }
        return true;
    }
};