class Solution {
public:
    int fib(int N) {
         if (N == 0)
         {
             return 0;
         }
          if (N == 1)
         {
             return 1;
         }
        //int ans=fib(N-1)+fib(N-2);
        return fib(N-1)+fib(N-2);
    }
};
/*
        int a = 0, b = 1;
        for(int i=2; i<=N; i++){
            int c = a + b;
            a = b;
            b = c;
        } return b;  
        */