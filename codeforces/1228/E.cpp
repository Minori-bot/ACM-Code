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
const int N = 300;
const int p = 1000000007;
int n, k;
LL dp[N][N], pk[N], c[N][N], pks[N];
 
void calc(){
    for(int i = 0; i <= n; i ++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j ++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= p;
        }
    }
    pk[0] = pks[0] = 1;
    for(int i = 1; i <= n; i ++){
        pk[i] = pk[i - 1] * k % p;
        pks[i] = pks[i - 1] * (k - 1) % p;
    }
}
 
int main(){
 
    __fastIn;
 
    cin >> n >> k;
    calc();
    dp[0][n] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= n; j ++){
            dp[i][j] = dp[i - 1][j] * pks[j] % p * (pk[n - j] + p - pks[n - j]) % p;
            dp[i][j] %= p;
            for(int t = j + 1; t <= n; t ++){
                dp[i][j] += dp[i - 1][t] * c[t][t - j] % p * pks[j] % p * pk[n - t] % p;
                dp[i][j] %= p;
            }
        }
    }
    cout << dp[n][0] << endl;
 
    return 0;
}