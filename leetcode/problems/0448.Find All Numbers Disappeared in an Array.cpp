class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        　for(auto e: nums){
            int index = (e - 1) % nums.size();
            nums[index] += nums.size();
        }

        vector<int> ret;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] <= nums.size()){
                ret.push_back(i + 1);
            }
        }

        return ret;
    }
};