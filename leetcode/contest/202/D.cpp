class Solution {

private:
    unordered_map<int, int> dp;

    // we should never take more than 2 consecutive -1 operations.
    // great proof: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/discuss/794088/Intuitive-solution-with-Proof
    int dfs(int n){
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n]) return dp[n];

        int res = INT_MAX;
        if(n % 3 == 0) res = min(res, dfs(n / 3) + 1);
        if(n % 2 == 0) res = min(res, dfs(n / 2) + 1);
        if((n - 1) % 2 == 0 || (n - 1) % 3 == 0) res = min(res, dfs(n - 1) + 1);
        if((n - 2) % 3 == 0) res = min(res, dfs(n - 2) + 2);

        dp[n] = res;
        return res;
    }

public:
    int minDays(int n) {

        return dfs(n);
    }
};