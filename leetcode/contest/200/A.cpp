class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        
        int n = arr.size();
        int res = 0;
        
        for(int i = 0; i < n; i ++){
            for(int j = i; j < n; j ++){
                for(int k = j; k < n; k ++){
                    if(i != j && j != k){
                        if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            res ++;
                    }
                }
            }
        }
        return res;
    }
};