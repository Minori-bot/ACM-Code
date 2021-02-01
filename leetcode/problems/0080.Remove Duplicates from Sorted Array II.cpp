class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int prior = 10001;
        int k = 0, freq = 0, del = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i ++) {
            if(nums[i] == prior) freq ++;
            else {
                prior = nums[i];
                freq = 1;
            }
            if(freq > 2) {
                del ++;
            }
            else {
                nums[k++] = nums[i];
            }
        }
        
        return n - del;
    }
};