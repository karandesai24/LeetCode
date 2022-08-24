vector<int> candyStore(int c[], int N, int K)
   {
       sort(c, c+N);
       int i=0, j=N-1, mini=0, maxi=0;
       while (i<=j){
           mini+=c[i];
           i++;
           j-=K;
       }
       i=0, j=N-1;
       while (j>=i){
           maxi+=c[j];
           j--;
           i+=K;
       }
       return {mini, maxi};
   }
