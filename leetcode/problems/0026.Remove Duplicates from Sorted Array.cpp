class Solution {
public:
    // remove duplicates in place
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.empty()) return 0;
        
        int res = 1;

        for(int i = 0, j = 1; j < nums.size(); j ++){

            if(nums[i] < nums[j]){
                swap(nums[i + 1], nums[j]);
                i ++;
                res ++;
            }
        }
        return res;
    }
};