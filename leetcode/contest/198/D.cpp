public:

    // O(nlogn) Solution
    int closestToTarget(vector<int>& arr, int target) {

        vector<vector<int>> pos(30);
        for(int i = 0; i < arr.size(); i ++){
            for(int j = 0; j < 30; j ++){
                if((arr[i] >> j) & 1) pos[j].push_back(i);
            }
        }

        int n = (int)arr.size();
        vector<int> dp(n);
        int ans = INT_MAX;
        for(int i = n - 1; i >= 0; i --){
            for(int j = 0; j < 30; j ++){
                if(!((arr[i] >> j) & 1)){
                    while(!pos[j].empty() && pos[j].back() > i){
                        dp[pos[j].back()] -= (1 << j);
                        pos[j].pop_back();
                    }
                }
            }
            dp[i] = arr[i];

            auto it = lower_bound(dp.begin() + i, dp.end(), target, greater<int>());
            if(it == dp.begin() + i){
                ans = min(ans, abs(*it - target));
            }
            else if(it == dp.end()){
                ans = min(ans, abs(*(it - 1) - target));
            }
            else{
                ans = min(ans, min(abs(*it - target), abs(*(it - 1) - target)));
            }
        }
        return ans;
    }
};


// O(n^2) Solution
int closestToTarget(vector<int>& arr, int target) {

    int res = INT_MAX;

    for(int i = 0; i < arr.size(); i ++){
        int sum = arr[i];
        for(int j = i; j < arr.size(); j ++){
            sum = sum & arr[j];
            res = min(res, abs(sum - target));
            if(res == 0) return res;
            if(sum <= target) break;
        }
        if(sum >= target) break;
    }

    return res;
}
