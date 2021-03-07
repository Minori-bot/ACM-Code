class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<string>> ret;

    void dfs(const string& s, int index, int len, vector<string>& cur){
        if(len == s.size()){
            ret.push_back(cur);
            return;
        }

        for(int i = index; i < s.size(); i ++){
            if(dp[index][i]){
                cur.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1, len + i - index + 1, cur);
                cur.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {

        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, 0));

        for(int i = 0; i < n; i ++){
            for(int j = 0; j <= i; j ++){
                if(s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])){
                    dp[j][i] = 1;
                }
            }
        }
        vector<string> cur;
        dfs(s, 0, 0, cur);

        return ret;
    }
};