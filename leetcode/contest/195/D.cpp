class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        deque<vector<int>> dq;

        int res = INT_MIN;

        for(auto &p: points){
            if(dq.empty()){
                dq.push_back(p);
                continue;
            }
            while(!dq.empty() && p[0] - dq.front()[0] > k){
                dq.pop_front();
            }
            if(!dq.empty()){
                res = max(res, p[0] + p[1] + dq.front()[1] - dq.front()[0]);
                while(!dq.empty() && dq.back()[1] - dq.back()[0] < p[1] - p[0]){
                    dq.pop_back();
                }
            }
            dq.push_back(p);
        }

        return res;
    }
};