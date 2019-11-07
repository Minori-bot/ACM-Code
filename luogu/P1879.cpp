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
const int p = 100000000;
int s[N], n, m;
LL dp[N][1 << 12];

int main(){

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            int x;
            cin >> x;
            s[i] += ((x == 0) << (j - 1));
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < (1 << m); j ++){
            if(!(j & s[i]) && !((j << 1) & j)){
                for(int k = 0; k < (1 << m); k ++){
                    if((j & k) == 0){
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= p;
                    }
                }
            }
        }
    }
    LL ans = 0;
    for(int i = 0; i < (1 << m); i ++){
        ans += dp[n][i];
        ans %= p;
    }
    cout << ans << endl;

    return 0;
}