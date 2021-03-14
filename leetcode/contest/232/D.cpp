class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        stack<int> stack;
        vector<int> l, r;
        l.resize(n), r.resize(n);
        for(int i = 0; i < n; i ++){
            l[i] = r[i] = i;
        }
        for(int i = 0; i < n; i ++){
            while(!stack.empty() && nums[stack.top()] >= nums[i]){
                stack.pop();
            }
            if(stack.empty()) l[i] = -1;
            else l[i] = stack.top();
            stack.push(i);
        }
        while(!stack.empty()) stack.pop();
        for(int i = n - 1; i >= 0; i --){
            while(!stack.empty() && nums[stack.top()] >= nums[i]){
                stack.pop();
            }
            if(stack.empty()) r[i] = n;
            else r[i] = stack.top();
            stack.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i ++){
            l[i] ++, r[i] --;
            if(l[i] <= k && r[i] >= k){
                res = max(res, (r[i] - l[i] + 1) * nums[i]);
            }
        }

        return res;
    }
};