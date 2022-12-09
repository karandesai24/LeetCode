//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string a, vector<string> &b) {
        //code here
        int dp[a.size()];
        memset(dp,0,sizeof(dp));
        unordered_set<string> dict(b.begin(),b.end());

        for(int i=0;i<a.size();i++){
            for(int j=0;j<=i;j++){
                string s=a.substr(j,i-j+1);
                    if(dict.count(s)){
                        if(j>0)
                        dp[i]+=dp[j-1];
                        else
                        dp[i]=1;
                    }
            }
        }
        
        if(dp[a.size()-1]>0)
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends