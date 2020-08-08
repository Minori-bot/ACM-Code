class Solution {

private:
    
    int partition(vector<int>& nums, int l, int r){
        
        int e = nums[l];
        
        while(l < r){
            while(l < r && nums[r] >= e) r --;
            nums[l] = nums[r];
            while(l < r && nums[l] <= e) l ++;
            nums[r] = nums[l];
        }
        
        nums[l] = e;
        
        return l;
    }
    
    int find(vector<int>& nums, int l, int r, int k){
        
        if(l == r) return nums[l];
        
        assert(l < r);
        
        int p = partition(nums, l, r);
        
        if(p - l + 1 == k) return nums[p];
        
        if(p - l + 1 < k){
            return find(nums, p + 1, r, k - p + l - 1);
        }
        else return find(nums, l, p - 1, k);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        return find(nums, 0, n - 1, n - k + 1);
    }
};