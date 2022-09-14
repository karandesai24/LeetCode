class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      unordered_map<int,int>mp; 
        vector<int>vec=arr; 
        int count=1;
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<arr.size();i++)
    {
        if(mp[arr[i]]) 
            continue;
        mp[arr[i]]=count++;
    }
    
    for(int i=0;i<vec.size();i++)
        vec[i]=mp[vec[i]];
    
	return vec;  
    }
};