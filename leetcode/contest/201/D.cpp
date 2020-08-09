class Solution {

    const int INF = INT_MAX;

private:

    vector<vector<int>> dp;

    int dfs(vector<int>& cuts, int i, int j){

        if(j - i == 1){
            return 0;
        }
        if(dp[i][j] != INF){
            return dp[i][j];
        }
        for(int k = i + 1; k < j; k ++){
            dp[i][j] = min(dp[i][j], dfs(cuts, i, k) + dfs(cuts, k, j) + cuts[j] - cuts[i]);
        }
        return dp[i][j];
    }

public:
    int minCost(int n, vector<int>& cuts) {


        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        dp = vector<vector<int>>(m, vector<int>(m, INF));

        sort(cuts.begin(), cuts.end());
        
        return dfs(cuts, 0, m - 1);

    }
};