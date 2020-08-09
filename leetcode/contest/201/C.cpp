class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {

        map<int, int> prefix;
        int sum = 0, index = -1, res = 0;
        prefix[0] = -1;

        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];
            auto it = prefix.find(sum - target);
            if(it != prefix.end() && index <= it->second){
                res ++;
                index = i;
            }
            prefix[sum] = i;
        }
        
        return res;
    }
};