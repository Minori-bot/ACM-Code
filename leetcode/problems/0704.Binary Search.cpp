class Solution {

private:

    // binary search the target in [l...r)
    int binarySearch(const vector<int>& nums, int l, int r, int t){

        if(l >= r) return -1;

        int mid = l + (r - l) / 2;
        if(t == nums[mid]) return mid;
        return t < nums[mid] ? binarySearch(nums, l, mid, t) : binarySearch(nums, mid + 1, r, t);
    }

public:
    int search(vector<int>& nums, int target) {

        return binarySearch(nums, 0, nums.size(), target);
    }
};
