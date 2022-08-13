class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
    const int n = matrix[0].size();
    bool shouldFillFirstRow = false;
    bool shouldFillFirstCol = false;

    for (int j = 0; j < n; ++j)
      if (matrix[0][j] == 0) {
        shouldFillFirstRow = true;
        break;
      }

    for (int i = 0; i < m; ++i)
      if (matrix[i][0] == 0) {
        shouldFillFirstCol = true;
        break;
      }

    // store the information in the 1st row/col
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }

    // fill 0s for the matrix except the 1st row/col
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;

    // fill 0s for the 1st row if needed
    if (shouldFillFirstRow)
      for (int j = 0; j < n; ++j)
        matrix[0][j] = 0;

    // fill 0s for the 1st col if needed
    if (shouldFillFirstCol)
      for (int i = 0; i < m; ++i)
        matrix[i][0] = 0;
    }
};
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         vector<pair<int,int>>zeroIndex;
        
        for(int i=0;i<matrix.size();i++){
             
            for(int j=0;j<matrix[0].size();j++){
                
                if(matrix[i][j]==0){
                    zeroIndex.push_back({i,j});
                }
            }
                
        }
        // now doing the real part
        for(auto x:zeroIndex){
            for(int i=0;i<matrix.size();i++){
                matrix[i][x.second]=0;
            }
            for(int j=0;j<matrix[0].size();j++){
                matrix[x.first][j] = 0;
            }
        }
    }
};
*/
