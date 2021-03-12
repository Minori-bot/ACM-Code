class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int n = nums.size();
        int sum = 0;
        for(auto num: nums){
            sum += num;
        }
        if(S > sum || S < -sum) return 0;

        auto dp = vector<vector<int>>(n, vector<int>(2 * sum + 1, 0));
        dp[0][nums[0] + sum] += 1,
        dp[0][-nums[0] + sum] += 1;
        for(int i = 1; i < n; i ++){
            for(int j = -sum; j <= sum; j ++){
                int x = j - nums[i] + sum;
                int y = j + nums[i] + sum;
                if(x >= 0 && x <= 2 * sum){
                    dp[i][j + sum] += dp[i - 1][x];
                }
                if(y >= 0 && y <= 2 * sum){
                    dp[i][j + sum] += dp[i - 1][y];
                }
            }
        }

        return dp[n - 1][S + sum];
    }
};