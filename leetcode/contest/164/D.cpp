class Solution {
private:
    using LL = long long;
    const static int p = 1000000007;

public:
    int numWays(int steps, int arrLen) {
        if(arrLen > steps) arrLen = steps;
        vector<LL> dp(arrLen);
        dp[0] = 1;

        for(int j = 1; j <= steps; j ++){
            vector<LL> temp(arrLen);
            for(int i = 0; i < arrLen; i ++){
                LL ans = dp[i];
                if(i < arrLen - 1) ans += dp[i + 1], ans %= p;
                if(i > 0) ans += dp[i - 1], ans %= p;
                temp[i] = ans;
            }
            dp = temp;
        }
        return (int)dp[0];
    }
};