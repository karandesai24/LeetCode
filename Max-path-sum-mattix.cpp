int dp[510][510];

   int solve(int N, vector<vector<int>> &Matrix,int dp[510][510],int i,int j){
       
       if(i==N || j==N || j<0 || i<0) return 0;
       
       if(dp[i][j]!=-1) return dp[i][j];
       
       int a= solve(N,Matrix,dp,i+1,j)   +Matrix[i][j];
       int b= solve(N,Matrix,dp,i+1,j-1) +Matrix[i][j];
       int c= solve(N,Matrix,dp,i+1,j+1) +Matrix[i][j];
       
       return dp[i][j]=max(a,max(b,c));
   }
   
   int maximumPath(int N, vector<vector<int>> Matrix)//main function
   {
       memset(dp,-1,sizeof(dp));
       int ans=0;
       int i=0;
       for(int j=0;j<N;j++){
           ans=max(ans,solve(N,Matrix,dp,i,j));
       }
       return ans;
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
