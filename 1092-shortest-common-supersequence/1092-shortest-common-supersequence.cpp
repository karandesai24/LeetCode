class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
         int m = X.size(),n = Y.size();
         int L[m + 1][n + 1];
    
        
         for (int i = 0; i <= m; i++) 
         {
             for (int j = 0; j <= n; j++)
             {
                 if (i == 0 || j == 0)
                     L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
        string s = "";
    int i = m , j = n;
    while(i>0 && j>0){
        
        if(X[i-1]==Y[j-1]){
            s+=X[i-1];
            i-- , j--;
        }
        else if(L[i-1][j]>L[i][j-1]){
                s+=X[i-1];
                i--;
            }
        else{
                 s+=Y[j-1];
                 j--;
        } 
    }
    
    while(i>0){
        s+=X[i-1];
        i--;
    }
    while(j>0){
        s+=Y[j-1];
        j--;
    }
    reverse(s.begin() , s.end());
    return s;
    

       
    }
};