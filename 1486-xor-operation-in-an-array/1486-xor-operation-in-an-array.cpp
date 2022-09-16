class Solution {
public:
    int xorOperation(int n, int start) {
      
        int x=start+2*0;
        for(int i=1;i<n;i++){
            x=x^start+2*i;
        }
        return x; 
    }
};