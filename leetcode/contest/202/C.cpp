class Solution {

private:

    bool check(vector<int>& p, int x, int m){

        int left = p[0];
        int k = 1;

        for(int i = 1; i < p.size(); i ++){
            if(p[i] - left >= x){
                k ++;
                left = p[i];
            }
        }
        return k >= m;
    }
public:
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());

        int l = 0, r = position.back() - position[0];
        int res = 0;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(check(position, mid, m)){
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return res;
    }
};