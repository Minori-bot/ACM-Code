class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int l = 0, r = -1;
        int sum = 0;
        double res = INT_MIN;

        while(r + 1 < nums.size()){
            sum += nums[++r];
            if(r - l + 1 == k){
                res = max(res, sum * 1.0 / k);
                sum -= nums[l++];
            }
        }
        
        return res;
    }
};