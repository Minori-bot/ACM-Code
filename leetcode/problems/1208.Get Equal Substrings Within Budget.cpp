class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        vector<int> cost;
        for(int i = 0; i < s.size(); i ++){
            cost.push_back(abs(s[i] - t[i]));
        }
        
        int sum = 0, res = 0;
        int l = 0, r = -1;
        while(l < s.size()){
            if(r + 1 < s.size() && sum <= maxCost){
                sum += cost[++r];
            }
            else{
                sum -= cost[l++];
            }
            if(sum <= maxCost){
                res = max(res, r - l + 1);
            }
        }
        
        return res;
    }
};