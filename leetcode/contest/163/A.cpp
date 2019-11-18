class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size(), m = grid[0].size();

        map<pair<int, int>, int> change;

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                int y = (j + k) % m;
                int x = ((j + k) / m + i) % n;
                cout << x << " " << y << endl;
                change[make_pair(x, y)] = grid[i][j];
            }
        }
        vector<vector<int>> ret = grid;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                ret[i][j] = change[make_pair(i, j)];
            }
        }

        return ret;
    }
};