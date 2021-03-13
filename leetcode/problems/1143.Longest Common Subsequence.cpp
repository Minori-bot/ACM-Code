class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size(), n = text2.size();
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));


        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(text1[i] == text2[j]){
                    dp[i][j] = i >= 1 && j >= 1 ? dp[i - 1][j - 1] + 1 : 1;
                }
                else{
                    if(i >= 1) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    if(j >= 1) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};