class Solution {
public:
    int minOperations(int n) {

        int res = 0;
        vector<int> arr;

        for(int i = 0; i <= n; i ++){
            arr.push_back(2 * i + 1);
        }

        for(int i = 0, j = n - 1; i < j; i ++ , j --){
            res += (arr[j] - arr[i]) / 2;
        }
        return res;
    }
};