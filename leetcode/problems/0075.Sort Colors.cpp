class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int zero = -1, two = n;

        int i = 0;
        while(i < two){
            if(nums[i] == 0){
                swap(nums[++zero], nums[i++]);
            }
            else if(nums[i] == 1){
                i ++;
            }
            else{
                swap(nums[i], nums[--two]);
            }
        }
    }
};