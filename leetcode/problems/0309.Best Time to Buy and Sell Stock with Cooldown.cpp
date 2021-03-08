class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        auto dp = vector<vector<int>>(n, vector<int>(3, INT_MIN));

        dp[0][0] = 0, dp[0][2] = -prices[0];
        for(int i = 1; i < n; i ++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][2] + prices[i];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] - prices[i]);
        }

        return max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }
};