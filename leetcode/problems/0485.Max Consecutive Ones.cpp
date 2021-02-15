class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ret = 0, cnt = 0;
        for(auto e: nums){
            if(e == 1) cnt ++;
            else{
                ret = max(ret, cnt);
                cnt = 0;
            }
        }
        ret = max(ret, cnt);
        
        return ret;
    }
};