class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, 1);

        int ret = 1;
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};