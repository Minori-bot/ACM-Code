class Solution {
private:
#define INF 0x3f3f3f3f
    int dp[105][105];
    unordered_map<string, int> record;
    int calc(string str){
        if(str.size() == 0) return 0;
        if(record[str]) return record[str];

        int res = 0;
        for(int i = 0; i < str.size(); i ++){
            if(str[i] != str[str.size() - i - 1]) res ++;
        }
        res /= 2;
        record[str] = res;
        return res;
    }
public:
    int palindromePartition(string s, int k) {

        for(int i = 0; i < s.size(); i ++){
            dp[0][i + 1] = calc(s.substr(0, i + 1));
        }
        for(int i = 1; i < k; i ++){
            for(int j = i; j <= s.size(); j ++){
                int cur = INF;
                for(int p = i - 1; p <= j - 1; p ++){
                    cur = min(cur, dp[i - 1][p] + calc(s.substr(p, j - p)));
                }
                dp[i][j] = cur;
            }
        }
        return dp[k - 1][s.size()];
    }
};