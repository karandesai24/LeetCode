class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        auto &inp = newInterval;
        for(auto &val : intervals){
            if(val[1]<inp[0]) temp.push_back(val);
            else if(val[0]>inp[1]) {
                temp.push_back(inp);
                inp = val;
            }
            else{
                inp[0] = min(inp[0],val[0]);
                inp[1] = max(inp[1],val[1]);
            }
        }
        temp.push_back(inp);
        return temp;
    }
};