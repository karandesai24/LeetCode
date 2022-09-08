class Solution {
public:
    bool isPerfectSquare(int n) {
      for(long long i=1;i*i<=n;i++){
           if(i*i==n)
               return 1;
       }
       return 0;

  
    }
};