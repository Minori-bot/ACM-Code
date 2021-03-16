class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        auto g = vector<vector<int>>(n, vector<int>(n, 0));
        int u = 0, d = n - 1;
        int l = 0, r = n - 1;
        int cur = 1;
        
        while(true){
            for(int i = l; i <= r; i ++) g[u][i] = cur ++;
            if(++ u > d) break;
            for(int i = u; i <= d; i ++) g[i][r] = cur ++;
            if(-- r < l) break;
            for(int i = r; i >= l; i --) g[d][i] = cur ++;
            if(-- d < u) break;
            for(int i = d; i >= u; i --) g[i][l] = cur ++;
            if(++ l > r) break;
        }
        
        return g;
    }
};