class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = (int)min(matrix.size(), matrix[0].size());
        int m[500][500], dp[500][500];
        for(int i = 1; i <= matrix.size(); i ++){
            for(int j = 1; j <= matrix[0].size(); j ++){
                m[i][j] = matrix[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= matrix.size(); i ++){
            for(int j = 1; j <= matrix[0].size(); j ++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + m[i][j];
            }
        }
        int ret = 0;
        for(int k = 1; k <= n; k ++){
            for(int i = 1; i + k - 1 <= matrix.size(); i ++){
                for(int j = 1; j + k - 1 <= matrix[0].size(); j ++){
                    int x1, y1, x2, y2;
                    x1 = i, y1 = j;
                    x2 = i + k - 1, y2 = j + k - 1;
                    int sum = dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1];
                    if(sum == k * k) ret ++;
                }
            }
        }
        return ret;
    }
};