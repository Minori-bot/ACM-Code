class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {

        int n = arr.size();
        int res = -1;
        vector<int> len(n + 2);
        vector<int> count(n + 1);

        for(int j = 0; j < n; j ++){
            int p = arr[j];
            int left = len[p - 1];
            int right = len[p + 1];
            len[p] = len[p - left] = len[p + right] = left + right + 1;

            count[left] --, count[right] --;
            count[len[p]] ++;
            
            if(count[m] > 0) res = j + 1;
        }
        
        return res;
    }
};