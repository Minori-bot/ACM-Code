class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        
        int sum = 0, n = customers.size();
        for(int i = 0; i < n; i ++){
            if(!grumpy[i]) sum += customers[i];
        }
        
        int l = 0, r = 0, extra = 0, res = INT_MIN;
        while(r < n){
            if(grumpy[r]) extra += customers[r];
            r ++;
            while(r - l > X){
                if(grumpy[l]) extra -= customers[l];
                l ++;
            }
            res = max(res, extra);
        }
        
        return sum + res;
    }
};