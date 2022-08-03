class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:mp)
        {
            pq.push(make_pair(i.second,i.first));
        }
        for(int i=0;i<k;i++)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};
/*
  vector<int> res;
        unordered_map<int,int> freqs;
        priority_queue<pair<int,int>> pq;
        for(int num : nums) freqs[num]++;
        for(auto iter = freqs.begin(); iter != freqs.end(); iter++)
            pq.push({iter->second, iter->first});
        while( !pq.empty() && k>0 ){
            pair<int,int> tmp = pq.top(); pq.pop();
            res.push_back(tmp.second);
            k--;
        } return res;
        */