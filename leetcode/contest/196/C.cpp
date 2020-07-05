//    Time Complexity: O(n^2m)
//class Solution {
//public:
//    int numSubmat(vector<vector<int>>& mat) {
//
//        int n = mat.size(), m = mat[0].size();
//        int res = 0;
//
//        for(int i = 0; i < n; i ++){
//            for(int j = 1; j < m; j ++){
//                mat[i][j] = mat[i][j] ? mat[i][j - 1] + 1 : 0;
//            }
//        }
//        for(int i = 0; i < n; i ++){
//            for(int j = 0; j < m; j ++){
//                int ths = mat[i][j];
//                res += ths;
//                for(int k = i + 1; k < n; k ++){
//                    ths = min(ths, mat[k][j]);
//                    res += ths;
//                }
//            }
//        }
//
//        return res;
//    }
//};

class Solution {
public:
    // Time Complexity: O(nm)
    int numSubmat(vector<vector<int>>& mat) {

        int n = (int)mat.size(), m = (int)mat[0].size();
        vector<vector<int>> h(n, vector<int>(m, 0));
        vector<vector<int>> sum(n, vector<int>(m, 0));

        for(int j = 0; j < m; j ++) h[0][j] = mat[0][j];
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < m; j ++){
                h[i][j] = mat[i][j] == 0 ? 0 : h[i - 1][j] + 1;
            }
        }

        for(int i = 0; i < n; i ++){
            // mono-stack
            stack<int> ms;

            for(int j = 0; j < m; j ++){
                while(!ms.empty() && h[i][ms.top()] >= h[i][j]){
                    ms.pop();
                }
                if(!ms.empty()){
                    int prior = ms.top();
                    sum[i][j] = sum[i][prior];
                    sum[i][j] += h[i][j] * (j - prior);
                }
                else{
                    sum[i][j] = h[i][j] * (j + 1);
                }
                ms.push(j);
            }
        }

        int res = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++) res += sum[i][j];
        }

        return res;
    }
};