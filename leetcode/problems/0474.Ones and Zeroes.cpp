class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<int> zeros, ones;
        zeros.resize(strs.size());
        ones.resize(strs.size());
        for(int i = 0; i < strs.size(); i ++){
            for(auto& c: strs[i]){
                c == '0' ? zeros[i] ++ : ones[i] ++;
            }
        }
        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; i ++){
            for(int j = 0; j <= n; j ++){
                if(i >= zeros[0] && j >= ones[0]) dp[i][j] ++;
            }
        }
        for(int k = 1; k < strs.size(); k ++){
            for(int i = m; i >= zeros[k]; i --){
                for(int j = n; j >= ones[k]; j --){
                    dp[i][j] = max(dp[i][j], dp[i - zeros[k]][j - ones[k]] + 1);
                }
            }
        }

        return dp[m][n];
    }
};