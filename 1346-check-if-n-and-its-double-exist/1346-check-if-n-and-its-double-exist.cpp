class Solution {
public:
    bool checkIfExist(vector<int>& a) {
       int n=a.size();
		unordered_map<int,int> mp;
		for(int i=0;i<n;i++) mp[a[i]]++;
		if(mp[0]>1) return true;
		for(int i=0;i<n;i++) {
			if(a[i]&&mp.count(2*a[i])) return true;
		}
		return false; 
    }
};