class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0, j = 0;
        long long a = 0, b = 0, res = 0, mod = 1e9 + 7;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                a += nums1[i ++];
            }
            else if(nums1[i] > nums2[j]){
                b += nums2[j ++];
            }
            else{
                res += max(a, b) % mod + nums1[i];
                res %= mod;
                a = 0, b = 0;
                i ++, j ++;
            }
        }
        
        while(i < nums1.size()) a += nums1[i ++];
        while(j < nums2.size()) b += nums2[j ++];
        
        res += max(a, b);
        
        return res % mod;
    }
};