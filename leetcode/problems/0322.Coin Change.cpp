class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        // for(int i = 0; i <= amount; i ++){
        //     if(i % coins[0] == 0) dp[i] = i / coins[0];
        // }
        for(int i = 0; i < coins.size(); i ++){
            for(int j = coins[i]; j <= amount; j ++){
                if(dp[j] != -1 && dp[j - coins[i]] != -1){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
                else if(dp[j - coins[i]] != -1){
                    dp[j] = dp[j - coins[i]] + 1;
                }
            }
        }

        return dp[amount];
    }
};