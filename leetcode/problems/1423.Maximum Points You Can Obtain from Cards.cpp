class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int l = 0, r = -1;
        int sum = 0, p = cardPoints.size() - k;
        int val = INT_MAX;
        auto res = make_pair(0, -1);
        
        while(r + 1 < (int)cardPoints.size()){
            sum += cardPoints[++r];
            if(r - l + 1 == p){
                if(val > sum){
                    res.first = l;
                    res.second = r;
                    val = sum;
                }
                sum -= cardPoints[l++];
            }
        }
        int ret = 0;
        for(int i = 0; i < res.first; i ++) ret += cardPoints[i];
        for(int i = res.second + 1; i < cardPoints.size(); i ++) ret += cardPoints[i];
        
        return ret;
    }
};