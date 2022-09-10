class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &visited, vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        visited[r][c] = 1;
        
        vector<int> newRow {-1, 0, 1, 0};
        vector<int> newCol {0, 1, 0, -1};
        
        for(int i=0;i<4;i++) {
            int nr = r + newRow[i];
            int nc = c + newCol[i];
            
            if(nr >= 0 && nr < row && nc >= 0 && nc < col && visited[nr][nc] == 0 && board[nr][nc] == 'O') {
                dfs(nr, nc, visited, board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<int>> visited(row, vector<int>(col, 0));
        
        for(int i=0;i<col;i++) {
            if(board[0][i] == 'O' && visited[0][i] == 0)
                dfs(0, i, visited, board);
        }
        
        for(int i=0;i<row;i++) {
            if(board[i][0] == 'O' && visited[i][0] == 0)
                dfs(i, 0, visited, board);
        }
        
        for(int i=0;i<col;i++) {
            if(board[row-1][i] == 'O' && visited[row-1][i] == 0)
                dfs(row-1, i, visited, board);
        }
        
        for(int i=0;i<row;i++) {
            if(board[i][col-1] == 'O' && visited[i][col-1] == 0)
                dfs(i, col-1, visited, board);
        }
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(board[i][j] == 'O' && visited[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};