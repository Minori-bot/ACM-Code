class Solution {
private:
    vector<int> calc(const vector<int>& nums){
        int n = nums.size();
        auto ret = vector<int>(1 << n);
        for(int i = 0; i < nums.size(); i ++){
            for(int j = 0; j < (1 << i); j ++){
                ret[j + (1 << i)] = nums[i] + ret[j];
            }
        }
        return ret;
    }

public:
    int minAbsDifference(vector<int>& nums, int goal) {

        int n = nums.size();
        auto left = calc(vector<int>(nums.begin(), nums.begin() + n / 2));
        auto right = calc(vector<int>(nums.begin() + n / 2, nums.end()));

        sort(left.begin(), left.end());
        sort(right.rbegin(), right.rend());

        int l = 0, r = 0;
        int res = INT_MAX;
        while(l < left.size() && r < right.size()){
            int sum = left[l] + right[r];
            res = min(res, abs(sum - goal));
            if(sum > goal){
                r ++;
            }
            else if(sum < goal){
                l ++;
            }
            else{
                res = 0;
                break;
            }
        }

        return res;
    }
};