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
const int N = 4005;
const int MOD = 998244353;
int h, w, t, n, row[N], col[N], cntx, cnty;
LL fac[N], f[N][N], g[N][N], C[N][N];
 
void calc(){
    for(int i = 0; i <= n; i ++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j ++){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= MOD;
        }
    }
    fac[0] = fac[1] = 1;
    for(int i = 2; i < N; i ++){
        fac[i] = fac[i - 1] * i % MOD;
    }
}
 
void make(LL dp[][N], int y[], int len){
    for(int i = 0; i <= len; i ++) dp[i][0] = 1;
    for(int i = 2; i <= len; i ++){
        for(int j = 1; j <= n; j ++){
            if(y[i] == 1 || y[i - 1] == 1){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
}
 
int main(){
 
    h = read(), w = read(), t = read();
    n = max(h, w);
    calc();
    for(int i = 1; i <= t; i ++){
        int a = read(), b = read(), c = read(), d = read();
        row[a] = row[c] = 1;
        col[b] = col[d] = 1;
    }
    make(f, row, h);
    make(g, col, w);
    for(int i = 1; i <= h; i ++) cntx += row[i];
    for(int i = 1; i <= w; i ++) cnty += col[i];
    LL ans = 0;
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= n; j ++){
            if(j + 2 * i <= h - cntx && i + 2 * j <= w - cnty){
                ans += f[h][i] * C[h - cntx - 2 * i][j] % MOD * g[w][j] % MOD * C[w - cnty - 2 * j][i] % MOD * fac[i] % MOD * fac[j] % MOD;
                ans %= MOD;
            }
        }
    }
    printf("%lld\n", ans);
 
    return 0;
}