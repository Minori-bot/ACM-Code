class Solution {

private:
    char grid[3][3];
    bool vis[3][3];
    int cnt = 0;

    string check(){
        for(int i = 0; i < 3; i ++){
            if(vis[i][0]){
                if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){
                    return grid[i][0] == 'X' ? "A" : "B";
                }
            }
        }
        for(int j = 0; j < 3; j ++){
            if(vis[0][j]){
                if(grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]){
                    return grid[1][j] == 'X' ? "A" : "B";
                }
            }
        }
        if(vis[0][0]){
            if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
                return grid[0][0] == 'X' ? "A" : "B";
            }
        }
        if(vis[0][2]){
            if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
                return grid[0][2] == 'X' ? "A" : "B";
            }
        }
        if(cnt == 9) return "Draw";
        return "Pending";
    }

public:
    string tictactoe(vector<vector<int>>& moves) {

        for(int i = 0; i < moves.size(); i ++){
            int x = moves[i][0], y = moves[i][1];
            grid[x][y] = (i & 1) ? 'O' : 'X';
            vis[x][y] = true;
            cnt ++;
        }
        return check();
    }
};