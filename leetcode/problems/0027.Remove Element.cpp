class Solution {
public:
    // remove element in place
    int removeElement(vector<int>& nums, int val) {
        
        if(nums.empty()) return 0;
        
        int l = 0, r = nums.size() - 1;
        bool ok = false;

        while(l <= r){
            if(nums[l] != val){
                l ++;
            }
            else{
                while(r > l && nums[r] == val){
                    r --;
                }
                swap(nums[l], nums[r]);
                ok = true;
                if(l == r) break;
            }
        }
        return ok ? r : r + 1;
    }
};