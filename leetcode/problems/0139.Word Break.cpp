class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        set<string> set;
        for(auto& word: wordDict){
            set.insert(word);
        }
        vector<int> dp(s.size() + 1, 0);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i ++){
            for(int j = 0; j < i; j ++){
                if(dp[j] && set.find(s.substr(j, i - j)) != set.end()) dp[i] = true;
            }
        }

        return dp[s.size()];
    }
};