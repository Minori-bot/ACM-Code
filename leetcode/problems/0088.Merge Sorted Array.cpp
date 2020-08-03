class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        
        int i = 0, j = 0;
        vector<int> ret;
        
        while(i < m && j < n){
            if(a[i] < b[j]){
                ret.push_back(a[i ++]);
            }
            else if(a[i] >= b[j]){
                ret.push_back(b[j ++]);
            }
        }
        while(i < m) ret.push_back(a[i ++]);
        while(j < n) ret.push_back(b[j ++]);
        
        a = ret;
    }
};