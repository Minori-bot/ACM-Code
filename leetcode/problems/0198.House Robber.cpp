class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.empty()){
            return 0;
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i ++){
            dp[i] = max(dp[i - 1], i - 2 >= 0 ? dp[i - 2] + nums[i] : nums[i]);
        }

        return dp.back();
    }
};