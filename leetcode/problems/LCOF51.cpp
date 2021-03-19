class Solution {

private:
    vector<int> c;

    inline int lowbit(int x){
        return x & (-x);
    }

    inline void add(int k){
        for(; k < c.size(); k += lowbit(k)) c[k] += 1; 
    }
    
    inline int query(int k){
        int ret = 0;
        for(; k; k -= lowbit(k)) ret += c[k];

        return ret;
    }
public:
    int reversePairs(vector<int>& nums) {
        
        c = vector<int>(50005);
        vector<int> b(nums.begin(), nums.end());

        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for(int i = 0; i < nums.size(); i ++){
            nums[i] = lower_bound(b.begin(), b.end(), nums[i]) - b.begin() + 1;
        }
        
        int res = 0;
        for(int i = nums.size() - 1; i >= 0; i --){
            res += query(nums[i] - 1);
            add(nums[i]);
        }

        return res;
    }
};