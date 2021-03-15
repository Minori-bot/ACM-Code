class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int u = 0, d = matrix.size();
        int l = 0, r = matrix[0].size();
        vector<int> ret;

        while(true){
            for(int i = l; i < r; i ++){
                ret.push_back(matrix[u][i]);
            }
            if(++ u >= d) break;
            for(int i = u; i < d; i ++){
                ret.push_back(matrix[i][r - 1]);
            }
            if(-- r <= l) break;
            for(int i = r - 1; i >= l; i --){
                ret.push_back(matrix[d - 1][i]);
            }
            if(-- d <= u) break;
            for(int i = d - 1; i >= u; i --){
                ret.push_back(matrix[i][l]);
            }
            if(++ l >= r) break;
        }

        return ret;
    }
};