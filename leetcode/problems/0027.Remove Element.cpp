class Solution {
public:
    // remove element in place
    // naive solution
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


    int removeElement2(vector<int>& nums, int val) {
        
        if(nums.empty()) return 0;
        
        int i = 0;
        for(int j = 0; j < nums.size(); j ++){
            if(nums[j] != val){
                nums[i++] = nums[j];
            }
        }
        return i;
    }

};