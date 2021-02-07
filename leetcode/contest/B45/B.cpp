class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        vector<int> prefix(nums.size() + 1);
        prefix[0] = 0;
        for(int i = 1; i < nums.size() + 1; i ++){
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }

        int res = INT_MIN;
        int maximum = 0, minimum = 0;
        for(int i = 0; i < nums.size(); i ++){
            res = max(res, abs(prefix[i + 1] - maximum));
            res = max(res, abs(prefix[i + 1] - minimum));
            maximum = max(prefix[i + 1], maximum);
            minimum = min(prefix[i + 1], minimum);
        }
        
        return res;
    }
};