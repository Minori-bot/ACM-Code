class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> s;
        vector<int> ret(nums.size(), -1);

        int n = nums.size();
        for(int i = 0; i < n; i ++){
            nums.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i ++){
            while(!s.empty() && nums[s.top() % n] < nums[i]){
                ret[s.top() % n] = nums[i];
                s.pop();
            }
            s.push(i);
        }

        return ret;
    }
};