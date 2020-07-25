class Solution {

private:

    int solve(const vector<int>& nums, int l, int r){

        if(l == r) return nums[l];

        int mid = (l + r) >> 1;
        int lResult = solve(nums, l, mid);
        int rResult = solve(nums, mid + 1, r);

        int maxi = INT_MIN, maxj = INT_MIN;
        int sumi = 0, sumj = 0;
        for(int i = mid; i >= l; i --){
            sumi += nums[i];
            maxi = max(maxi, sumi);
        }
        for(int j = mid; j <= r; j ++){
            sumj += nums[j];
            maxj = max(maxj, sumj);
        }

        return max(maxi + maxj - nums[mid], max(lResult, rResult));
    }

public:
    int maxSubArray(vector<int>& nums) {

        return solve(nums, 0, nums.size() - 1);
    }
};