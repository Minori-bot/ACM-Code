class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = 0;
        for(auto num: nums){
            n += num;
        }
        if(n & 1) return false;
        n /= 2;
        vector<int> dp(n + 1, 0);

        if(nums[0] <= n){
            dp[nums[0]] = 1;
        }
        for(int i = 1; i < nums.size(); i ++){
            for(int j = n; j >= nums[i]; j --){
                dp[j] = (dp[j] || dp[j - nums[i]]);
            }
        }

        return dp[n];
    }
};