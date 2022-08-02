class Solution {
private:
    bool is_valid(vector<string>& board, int row, int col){
       
        for(int i=row; i>=0; i--)
            if( board[i][col] == 'Q' ) return false;
        for(int i=row, j=col; i>=0 && j>=0; i--, j--)
            if( board[i][j] == 'Q' ) return false;
        for(int i=row, j=col; i>=0 && j<board.size(); i--, j++)
            if( board[i][j] == 'Q' ) return false;
        return true;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& board, int row){
        if( row == board.size() ){ 
            res.push_back(board);  
            return;
        }
        for(int col=0; col<board.size(); col++){
            if( is_valid(board, row, col) ){
                board[row][col] = 'Q';
                dfs(res, board, row+1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(res, board, 0);
        return res;
    }
};