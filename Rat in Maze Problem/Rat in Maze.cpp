bool isSafe(int x,int y,vector<vector<int>> arr,vector<vector<bool>> &vis,int n)

{

    if((x>=0 && x<n) && (y>=0 && y<n) && vis[x][y]!=1 && arr[x][y]==1)

        return true;

    else

        return false;

}

void solve(int x,int y,vector<vector<int>> arr,vector<vector<bool>> &vis,int n,string path,vector<string> &ans)

{

    if(x==n-1 && y==n-1)

    {

        ans.push_back(path);

        return;

    }

   

    //4 movements D L R U

   vis[x][y]=1;

   

    if(isSafe(x+1,y,arr,vis,n))

    {

        solve(x+1,y,arr,vis,n,path+'D',ans);

    }

    if(isSafe(x,y-1,arr,vis,n))

    {  

        solve(x,y-1,arr,vis,n,path+'L',ans);  

    }

   

    if(isSafe(x,y+1,arr,vis,n))

    {

      solve(x,y+1,arr,vis,n,path+'R',ans);  

    }

   

    if(isSafe(x-1,y,arr,vis,n))

    {      

        solve(x-1,y,arr,vis,n,path+'U',ans);      

    }

     vis[x][y]=0;

}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {

    // Write your code here.

    vector < vector < bool >> vis(n,vector<bool> (n,0));

    vector<string> ans;

    string path = "";

    if(arr[0][0]==0)

      return ans;

    solve(0,0,arr,vis,n,path,ans);

    return ans;

}
