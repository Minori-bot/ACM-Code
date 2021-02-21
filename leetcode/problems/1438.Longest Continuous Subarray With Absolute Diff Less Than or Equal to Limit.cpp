class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int l = 0, r = 0, n = nums.size();
        multiset<int> set;
        int ret = 0;

        while(r < n){
            set.insert(nums[r++]);
            while(*set.rbegin() - *set.begin() > limit){
                int cur = nums[l++];
                set.erase(set.find(cur));
            }
            ret = max(ret, r - l);
        }

        return ret;
    }
};