class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));

        dp[0][0] = !(obstacleGrid[0][0]);
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(obstacleGrid[i][j] == 1) continue;
                if(i - 1 >= 0 && obstacleGrid[i - 1][j] != 1){
                    dp[i][j] += dp[i - 1][j];
                }
                if(j - 1 >= 0 && obstacleGrid[i][j - 1] != 1){
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};