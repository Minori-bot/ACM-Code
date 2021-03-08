class Solution {
public:
    int minCut(string s) {
        
        int n = s.size();
        auto pal = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j <= i; j ++){
                if(s[i] == s[j] && (i - j <= 2 || pal[j + 1][i - 1])){
                    pal[j][i] = 1;
                }
            }
        }
        auto dp = vector<int>(n, 0);
        for(int i = 0; i < n; i ++){
            if(!pal[0][i]){
                dp[i] = dp[i - 1] + 1;
                for(int j = 0; j < i; j ++){
                    if(pal[j][i]){
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};