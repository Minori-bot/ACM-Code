class Solution {
public:
    int jump(vector<int>& nums) {

        vector<int> dp(nums.size(), INT_MAX - 5);
        dp[0] = 0;

        for(int i = 1; i < nums.size(); i ++){
            for(int j = 0; j < i; j ++){
                if(i - j <= nums[j]) dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[nums.size() - 1];
    }   
 };