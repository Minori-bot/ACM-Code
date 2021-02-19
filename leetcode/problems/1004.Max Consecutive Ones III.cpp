class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        
        int l = 0, r = 0;
        int n = A.size();
        int tot = 0, ret = 0;
        
        while(r < n){
            tot += A[r++] == 0;
            while(tot > K){
                tot -= A[l++] == 0;
            }
            ret = max(ret, r - l);
        }
        
        return ret;
    }
};