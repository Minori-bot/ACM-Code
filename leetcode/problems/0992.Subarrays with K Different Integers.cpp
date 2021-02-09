class Solution {

private:
    int solve(vector<int> &v, int k){

        int l = 0, r = -1;
        int ret = 0, cur = 0;
        int *freq = new int[v.size() + 1];
        fill(freq, freq + v.size() + 1, 0);

        while(r < (int)v.size()){
            if(r + 1 < v.size() && freq[v[r + 1]] && cur <= k){
                freq[v[++r]] ++;
            }
            else if(r + 1 < v.size() && cur <= k){
                freq[v[++r]] ++;
                cur ++;
            }
            else{
                freq[v[l]] --;
                if(!freq[v[l++]]) cur --;
                if(l == v.size()) break;
            }
            if(cur <= k){
                ret += r - l + 1;
                if(r == v.size() - 1) break;
            }
        }
        cout << ret << endl;
        return ret;
    }

public:
    int subarraysWithKDistinct(vector<int>& A, int K) {

        return solve(A, K) - solve(A, K - 1);
    }
};