#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int ans = INF;
        int n = (int)mat.size(), m = (int)mat[0].size();
        for(int k = 0; k < (1 << (n * m)); k ++){
            vector<vector<int>> g = mat;
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++){
                    if(1 << (i * m + j) & k){
                        g[i][j] ^= 1;
                        for(int p = 0; p < 4; p ++){
                            int nx = i + dx[p];
                            int ny = j + dy[p];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            g[nx][ny] ^= 1;
                        }
                    }
                }
            }
            int cur = 0;
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < m; j ++) cur += g[i][j];
            }
            if(cur == 0) ans = min(ans, __builtin_popcount(k));
        }
        return ans == INF ? -1 : ans;
    }
};
