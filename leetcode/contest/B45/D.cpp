class Solution {
private:
    vector<vector<int>> dp;

    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end(), cmp);
        dp = vector<vector<int>>(events.size(), vector<int>(k + 1, 0));
        dp[0][1] = events[0][2];

        for(int i = 1; i < events.size(); i ++){
            for(int j = 1; j <= min(i + 1, k); j ++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
            int l = 0, r = i - 1;
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(events[mid][1] >= events[i][0]){
                    r = mid - 1;
                }
                else{
                    l = mid;
                }
            }
            if(events[l][1] < events[i][0]) {
                for(int j = 1; j <= min(i + 1, k); j ++){
                    dp[i][j] = max(dp[i][j], dp[l][j - 1] + events[i][2]);
                }
            }
            else{
                dp[i][1] = max(dp[i][1], dp[i][0] + events[i][2]);
            }
        }

        int n = events.size() - 1;
        return *max_element(dp[n].begin(), dp[n].end());
    }
};