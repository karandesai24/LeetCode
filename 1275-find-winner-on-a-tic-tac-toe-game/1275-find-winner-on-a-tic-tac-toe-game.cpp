class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
       vector<vector<char>>res(3,vector<char>(3,'-1'));
        for(int i=0;i<moves.size();i++){
            if(i%2==0){
                res[moves[i][0]][moves[i][1]]='X';
            }
            else{
                res[moves[i][0]][moves[i][1]]='O';
            }
        }
        for(int i=0;i<3;i++){
            if(res[i][0]=='X' && res[i][1]=='X' && res[i][2]=='X')return "A";
        }
        for(int i=0;i<3;i++){
            if(res[0][i]=='X' && res[1][i]=='X' && res[2][i]=='X')return "A";
        }
        if(res[0][0]=='X' && res[1][1]=='X' && res[2][2]=='X')return "A";
        else if(res[0][2]=='X' && res[1][1]=='X' && res[2][0]=='X')return "A";
        
        for(int i=0;i<3;i++){
            if(res[i][0]=='O' && res[i][1]=='O' && res[i][2]=='O')return "B";
        }
        for(int i=0;i<3;i++){
            if(res[0][i]=='O' && res[1][i]=='O' && res[2][i]=='O')return "B";
        }
        if(res[0][0]=='O' && res[1][1]=='O' && res[2][2]=='O')return "B";
        else if(res[0][2]=='O' && res[1][1]=='O' && res[2][0]=='O')return "B";
        int n=moves.size();
        if(n<9)return "Pending";
        return "Draw";  
    }
};