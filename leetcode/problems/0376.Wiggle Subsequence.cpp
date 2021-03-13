class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        auto dp = vector<vector<int>>(n, vector<int>(2, 0));

        int ret = 0;
        dp[0][0] = dp[0][1] = 1;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < i; j ++){
                if(nums[j] < nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                else if(nums[j] > nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                else dp[i][0] = dp[j][0], dp[i][1] = dp[j][1];
            }
            ret = max(ret, max(dp[i][0], dp[i][1]));
        }

        return ret;
    }
};