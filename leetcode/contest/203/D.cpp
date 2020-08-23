int dp[505][505];
class Solution {

private:
    int dfs(const vector<int>& value, int i, int j){
        
        if(i == j || dp[i][j]) return dp[i][j];

        for(int k = i; k < j; k ++){
            int left = value[k] - (i > 0 ? value[i - 1] : 0);
            int right = value[j] - value[k];
            if(left <= right){
                dp[i][j] = max(dp[i][j], left + dfs(value, i, k));
            }
            if(right <= left){
                dp[i][j] = max(dp[i][j], right + dfs(value, k + 1, j));
            }
        }
        return dp[i][j];
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        
        // can't run fill(dp[0], dp[0]+ 505*505, 0);
        for(int i = 0; i < 505; i ++){
            for(int j = 0; j < 505; j ++) dp[i][j] = 0;
        }
        vector<int> value(stoneValue.size());
        partial_sum(stoneValue.begin(), stoneValue.end(), value.begin());

        return dfs(value, 0, stoneValue.size() - 1);
    }
};