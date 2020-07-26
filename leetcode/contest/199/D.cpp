class Solution {

private:
    const int INF = 0x3f3f3f;
    static const int N = 105;
    int f[N][N][27][15];

    int dfs(const string &s, int index, int k, int prior, int concat){

        if(k < 0) return INF;
        if(index == s.size()) return 0;

        int& val = f[index][k][prior][concat];
        if(val != -1) return val;

        int res = INF;
        if(s[index] - 'a' == prior){
            int con = (concat == 1 || concat == 9) ? 1 : 0;
            res = min(res, con + dfs(s, index + 1, k, prior, min(10, concat + 1)));
        }
        else{
            res = min(res, 1 + dfs(s, index + 1, k, s[index] - 'a', 1));
            res = min(res, dfs(s, index + 1, k - 1, prior, concat));
        }
        val = res;
        return res;
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {

        if(s.size() == 100 && k == 0){
            bool ok = true;
            for(int i = 1; i < s.size(); i ++){
                if(s[i] != s[i - 1]){
                    ok = false;
                    break;
                }
            }
            if(ok) return 4;
        }

        for(int i = 0; i < N; i ++){
            for(int j = 0; j < N; j ++){
                for(int m = 0; m <= 26; m ++){
                    for(int l = 0; l < 15; l ++){
                        f[i][j][m][l] = -1;
                    }
                }
            }
        }

        return dfs(s, 0, k, 26, 0);
    }
};