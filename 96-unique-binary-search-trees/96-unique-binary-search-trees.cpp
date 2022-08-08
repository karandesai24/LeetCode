class Solution {
public:
    int numTrees(int n) {
        vector<int> arr(n+1, 0);
        arr[0] = 1, arr[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; ++j) 
                arr[i] += arr[j-1] * arr[i-j];
        } 
        return arr[n];
        
    }
};
/*
class Solution {
    map<int,int> mp;
public:
    int numTrees(int n) {
        if(mp.count(n)) return mp[n];
        if(n <= 0) return 1;
        if(n <= 2) return n;
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            ans += (numTrees(i-1)*numTrees(n-i));
        }
        return mp[n] = ans;
    }
};
*/
