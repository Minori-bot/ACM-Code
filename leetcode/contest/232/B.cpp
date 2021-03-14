class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        int n = edges.size();
        n += 1;
        vector<int> g(n + 1, 0);
        for(auto& edge: edges){
            int u = edge[0], v = edge[1];
            g[u] ++, g[v] ++;
        }
        for(int i = 1; i <= n; i ++){
            if(g[i] == n - 1) return i;
        }

        return -1;
    }
};