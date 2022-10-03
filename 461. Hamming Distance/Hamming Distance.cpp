class Solution {
public:
    int hammingDistance(int x, int y) {
         int num = x ^ y;
        // traverse over the bits ans cout setbits
        int ans = 0;
        for(int i=0;i<32;i++){
            if(((num >> i) & 1) == 1){
                ans++;
            }
        }
        return ans;
    }
};
