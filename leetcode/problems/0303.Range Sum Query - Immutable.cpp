class NumArray {

private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        for(int i = 1; i <= nums.size(); i ++){
            prefix[i] += prefix[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        
        return prefix[j + 1] - prefix[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */