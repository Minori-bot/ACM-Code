class Solution {
public:
    int maxCoins(vector<int>& piles) {

        sort(piles.begin(), piles.end());
        deque<int> dq(piles.begin(), piles.end());
        int res = 0;
        
        while(!dq.empty()){
            int a = dq.back();
            dq.pop_back();
            int b = dq.back();
            dq.pop_back();
            int c = dq.front();
            dq.pop_front();
            res += b;
        }
        return res;
    }
};