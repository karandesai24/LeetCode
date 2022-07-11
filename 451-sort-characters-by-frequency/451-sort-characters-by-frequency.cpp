class Solution {
public:
    string frequencySort(string s) {
         unordered_map<char, int> characterCount;
        for(auto ch : s) {
           characterCount[ch]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto [ch, frequency] : characterCount) {
           pq.push({frequency, ch});
        } 
        
        string res;
        pair<int, char> curr;
        while(!pq.empty()) {
            curr = pq.top();
            pq.pop();
            res += string(curr.first, curr.second);
        }
        
        return res;
        
    }
};