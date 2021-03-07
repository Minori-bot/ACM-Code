class Solution {
public:
    int integerBreak(int n) {
        
        vector<int> dp(n + 1, 0);

        dp[2] = 1;
        for(int i = 2; i <= n; i ++){
            for(int j = 1; j <= i - 1; j ++){
                dp[i] = max(max(dp[i], j * dp[i - j]), j * (i - j));
            }
        }

        return dp[n];
    }
};