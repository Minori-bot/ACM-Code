class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int subr = arr[1] - arr[0];
        for(int i = 2; i < arr.size(); i ++){
            int t = arr[i] - arr[i - 1];
            if(t != subr) return false;
            subr = t;
        }
        return true;
    }
};