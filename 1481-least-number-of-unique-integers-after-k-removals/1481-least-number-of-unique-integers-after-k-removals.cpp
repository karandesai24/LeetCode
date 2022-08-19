class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();

		unordered_map<int,int> m;

		for(auto it : arr) m[it]++;

		vector<int> v;
		// storing the frequency of number
		for(auto it : m) v.push_back(it.second);

		// sorting to least to most frequent
		sort(v.begin(),v.end());

		for(int i = 0; i < v.size(); i++){
			if(k <= 0) break;
			int mn = min(k,v[i]);
			k -= mn;
			v[i] -= mn;
		}

		int ans = 0;

		for(int i = 0; i < v.size(); i++){
			if(v[i] > 0) ans++;
		}

		return ans;
    }
};
/*
 unordered_map<int,int> mp;
        for(int num : arr) mp[num]++;
        
        priority_queue<pair<int,int>, 
            vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto iter = mp.begin(); iter != mp.end(); iter++)
            pq.push(make_pair(iter->second, iter->first));
      
        while( k-- > 0 ){
            pair<int,int> cur = pq.top(); pq.pop();
            int cur_freq = cur.first, cur_num = cur.second;
            if( cur_freq > 1 ) pq.push(make_pair(cur_freq - 1, cur_num));
        }
        
        return pq.size();
	*/
