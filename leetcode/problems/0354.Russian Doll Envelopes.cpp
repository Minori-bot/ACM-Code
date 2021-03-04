class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int ret = 1;
        vector<int> dp(envelopes.size(), 1);
        for(int i = 0; i < envelopes.size(); i ++){
            for(int j = 0; j < i; j ++){
                if(envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};