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
const int N = 110;
int n, m;
int s[N], cnt[1 << 10];
LL dp[2][1 << 10][1 << 10];

inline int calc(int val){
    int ret = 0;
    while(val) ret += (val & 1), val >>= 1;
    return ret;
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            char c;
            cin >> c;
            s[i] += ((c == 'H') << j);
        }
    }
    for(int i = 0; i < (1 << m); i ++){
        cnt[i] = calc(i);
    }
    for(int i = 0; i < (1 << m); i ++){
        if((i & s[0]) || ((i << 1) & i) || ((i << 2) & i)) continue;
        dp[0][0][i] = cnt[i];
        for(int j = 0; j < (1 << m); j ++){
            if((j & i) || (j & s[1]) || ((j << 1) & j) || ((j << 2) & j)) continue;
            dp[1][i][j] = cnt[i] + cnt[j];
        }
    }
    for(int i = 2; i < n; i ++){
        for(int j = 0; j < (1 << m); j ++){
            if((j & s[i - 2]) || ((j << 1) & j) || ((j << 2) & j)) continue;
            for(int k = 0; k < (1 << m); k ++){
                if((j & k) || (k & s[i - 1]) || ((k << 1) & k) || ((k << 2) & k)) continue;
                for(int l = 0; l < (1 << m); l ++){
                    if((j & l) || (k & l) || (l & s[i]) || ((l << 1) & l) || ((l << 2) & l)) continue;
                    dp[i % 2][k][l] = max(dp[i % 2][k][l], dp[(i - 1) % 2][j][k] + cnt[l]);
                }
            }
        }
    }
    LL ans = 0;
    for(int i = 0; i < (1 << m); i ++){
        for(int j = 0; j < (1 << m); j ++){
            ans = max(ans, dp[(n - 1) % 2][i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}