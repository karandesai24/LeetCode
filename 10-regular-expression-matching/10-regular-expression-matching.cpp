class Solution {
public:
     int dp[21][31];
    bool func(int i,int j,string &s,string &p){
        if(dp[i][j] != -1) return dp[i][j];
        if(i >= s.size()){
            if(j == p.size()) return dp[i][j] = true;
            if(j + 1 < p.size() && p[j + 1] == '*') return dp[i][j] = func(i,j + 2,s,p);
            return dp[i][j] = false;
        }
        else if(j == p.size()) return dp[i][j] = false;
        bool match = (s[i] == p[j] || p[j] == '.');
        bool ans = false;
        if(match){
            if(j + 1 < p.size() && p[j + 1] == '*') ans = func(i+1,j,s,p);
            if(!ans) ans = func(i + 1,j + 1,s,p);
        }
        if(!ans && j + 1 < p.size() && p[j + 1] == '*') ans = func(i,j + 2,s,p);
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof dp);
        return func(0,0,s,p);
    }
   
    
};
/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=p.size();
        int n=s.size();
        
        bool t[m+1][n+1];
        
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 && j==0){
                   t[i][j]=true;
                }else if(i==0){
                   t[i][j]=false; 
                }else if(j==0){
                   if(p[i-1]=='*'){
                      t[i][j]=t[i-2][j];  
                   }else{
                      t[i][j]=false; 
                   } 
                }else{
                   if(p[i-1]=='*'){
                      t[i][j]=t[i-2][j];
                      
                      if(p[i-2]==s[j-1] || p[i-2]=='.'){
                         t[i][j]=t[i][j]||t[i][j-1]; 
                      }
                   }else if(p[i-1]=='.'){
                      t[i][j]=t[i-1][j-1]; 
                   }else if(s[j-1]==p[i-1]){
                      t[i][j]=t[i-1][j-1]; 
                   }else{
                      t[i][j]=false; 
                   } 
                }
            }
        }
        
        return t[m][n];
    }
};
//
class Solution {
public:
    vector<vector<int>> dp;
    bool fun(string &s,string &p,int i,int j){
        if(i==0 && j==0)
            return true;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if((i>0 && j>0) && (s[i-1]==p[j-1] || p[j-1]=='.'))
            return dp[i][j]=fun(s,p,i-1,j-1);
        if(j>0 && (p[j-1]=='*')){
            if(fun(s,p,i,j-2))
                return dp[i][j]=true;
            if((i>0 && j>0) && (s[i-1]==p[j-2] || p[j-2]=='.')){
                return dp[i][j]=fun(s,p,i-1,j);
        }
            }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return fun(s,p,n,m);
    }
};
//
*/
