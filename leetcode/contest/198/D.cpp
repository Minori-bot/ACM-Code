class Solution {
public:
    // O(n^2) Solution
    int closestToTarget(vector<int>& arr, int target) {

        int res = INT_MAX;

        for(int i = 0; i < arr.size(); i ++){
            int sum = arr[i];
            for(int j = i; j < arr.size(); j ++){
                sum = sum & arr[j];
                res = min(res, abs(sum - target));
                if(res == 0) return res;
                if(sum <= target) break;
            }
            if(sum >= target) break;
        }

        return res;
    }
};