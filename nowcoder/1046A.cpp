#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define full(a, b) memset(a, b, sizeof a)
#define __fastIn ios::sync_with_stdio(false), cin.tie(0)
#define pb push_back
using namespace std;
using LL = long long;
inline int lowbit(int x){ return x & (-x); }
inline int read(){
    int ret = 0, w = 0; char ch = 0;
    while(!isdigit(ch)){
        w |= ch == '-', ch = getchar();
    }
    while(isdigit(ch)){
        ret = (ret << 3) + (ret << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -ret : ret;
}
template <typename A>
inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C lyd){
    A ans = 1;
    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
    return ans;
}
const int N = 20;
const int M = (1 << 11);
int n, m;
bool vis[M];
LL dp[N][M];

int main(){

    while(cin >> n >> m && n && m){
        for(int i = 0; i < (1 << m); i ++){
            int cnt = 0;
            bool ok = false;
            for(int k = 0; k < m; k ++){
                if(i >> k & 1) ok |= cnt, cnt = 0;
                else cnt ^= 1;
            }
            vis[i] = !(ok | cnt);
        }
        dp[0][0] = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < (1 << m); j ++){
                dp[i][j] = 0;
                for(int k = 0; k < (1 << m); k ++){
                    if(!(j & k) && vis[j | k]) dp[i][j] += dp[i - 1][k];
                }
            }
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}