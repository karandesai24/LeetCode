class Solution {
public:
    int diagonalSum(vector<vector<int>>& A) {
         int n = A.size();
        int ans = 0;
        for(int i =0, j = n-1;i  < n ; i++ , j-- )
           ans += i == j ? A[i][i] : A[i][i] + A[i][j];
        return ans;
    }
};
/*
int diagonalSum(vector<vector<int>> &mat)
{
    int sum = 0;
    int s = mat.size();//size of row/col of matrix , both are equal as it is matrix
    //for iteration through row
    for (int i = 0; i < s; i++)
    {
        //for iteration through col
        for (int j = 0; j < s; j++)
        {
            //i==j is for left to right
            //i+j==s-1 is for right to left
            // using || operator we do not need to remove mid number 
            if (i == j || i + j == s - 1)
            {
                sum = sum + mat[i][j];
            }
        }
    }
    return sum ;
}
*/