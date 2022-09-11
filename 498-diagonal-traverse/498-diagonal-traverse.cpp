class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
          int m=mat.size(),n=mat[0].size(),i=0,j=0,flag=1;
        vector<int> ans;
        while(i!=m-1 || j!=n-1){
            if(flag==1){
                while(i>=0 && j<n){
                    ans.push_back(mat[i][j]);
                    i--;j++;
                }
                if(j==n){
                    i+=2;
                    j--;
                }
                else
                    i++;
                flag=0;
            }
            else{
                while(i<m && j>=0){
                    ans.push_back(mat[i][j]);
                    i++;j--;
                }
                if((i==m && j<0) || i==m){
                    i--;
                    j+=2;
                }
                else
                    j++;
                flag=1;
            }
        }
        ans.push_back(mat[i][j]);
        return ans;
    }
};