class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
          if( envelopes.size() < 2 ) 
              return envelopes.size();
     sort(envelopes.begin(), envelopes.end(),[](const vector<int>& a, const vector<int>& b)
          {
            if( a[0] < b[0] ) 
                return true;
            else if ( a[0] == b[0] ) 
                return a[1] > b[1];
            return false;
        });
        
         vector<int> res;
        for(auto& envelope : envelopes){
           
            auto iter = lower_bound(res.begin(), res.end(), envelope[1]);
           
            if( iter == res.end() ) 
                res.push_back(envelope[1]);
            else if ( *iter > envelope[1] ) 
                *iter = envelope[1];
        } 
        return res.size();
    }
};