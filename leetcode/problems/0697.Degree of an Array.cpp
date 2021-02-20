class Solution {

private:

    int calcDegree(vector<int>& nums){
        map<int, int> map;
        for(auto e: nums) map[e] ++;
        
        int ret = 0;
        for(auto it = map.begin(); it != map.end(); it ++){
            ret = max(ret, it->second);
        }

        return ret;
    }

public:
    int findShortestSubArray(vector<int>& nums) {

        int degree = calcDegree(nums);
        unordered_map<int, int> left, right, map;

        for(int i = 0; i < nums.size(); i ++){
            if(left.find(nums[i]) == left.end()){
                left[nums[i]] = i;
            }
            map[nums[i]] ++;
        }
        for(int i = nums.size() - 1; i >= 0; i --){
            if(right.find(nums[i]) == right.end()){
                right[nums[i]] = i;
            }
        }
        int ret = INT_MAX;
        for(auto e: nums){
            if(map[e] == degree){
                ret = min(ret, right[e] - left[e] + 1);
            }
        }

        return ret;
    }
};