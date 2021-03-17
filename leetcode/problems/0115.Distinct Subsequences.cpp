class Solution {

private:
    vector<vector<int>> dp;
    int dfs(const string& s, const string& t, int i, int j){
        if(j == -1 && i != -1) return 1;
        if(i < j || i == -1) return 0;
        if(i == 0 && j == 0) return s[i] == t[j];
        if(dp[i][j] != -1) return dp[i][j];

        int res = dfs(s, t, i - 1, j);
        if(s[i] == t[j]) res += dfs(s, t, i - 1, j - 1);
        dp[i][j] = res;
        return res;
    }

public:
    int numDistinct(string s, string t) {

        int n = s.size(), m = t.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        return dfs(s, t, n - 1, m - 1);
    }
};