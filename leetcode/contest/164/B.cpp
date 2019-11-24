class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        bool vis[300];
        fill(vis, vis + 300, false);
        int ret = 0;
        for(int i = 0; i < grid.size(); i ++){
            int num = 0;
            for(int j = 0; j < grid[i].size(); j ++){
                if(grid[i][j] == 1) num ++;
            }
            if(num > 1) ret += num, vis[i] = true;
        }
        
        for(int j = 0; j < grid[0].size(); j ++){
            int num = 0, count = 0;
            for(int i = 0; i < grid.size(); i ++){
                if(grid[i][j] == 1 && !vis[i]) num ++;
                if(grid[i][j] == 1) count ++;
            }
            if(count > 1){
                ret += num;
            }
        }
        return ret;
    }
};