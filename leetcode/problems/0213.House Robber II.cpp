class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }

        int ret = 0;
        vector<int> dp(nums.size(), 0);
        dp[1] = nums[1];
        for(int i = 2; i < nums.size(); i ++){
            dp[i] = max(dp[i - 1], i - 2 >= 0 ? dp[i - 2] + nums[i] : nums[i]);
        }
        ret = max(ret, dp.back());
        fill(dp.begin(), dp.end(), 0);
        dp[0] = nums[0], dp[1] = dp[0];
        for(int i = 2; i < nums.size() - 1; i ++){
            dp[i] = max(dp[i - 1], i - 2 >= 0 ? dp[i - 2] + nums[i] : nums[i]);
        }
        ret = max(ret, *(dp.end() - 2));

        return ret;
    }
};