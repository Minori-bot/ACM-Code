#include <bits/stdc++.h>
#define INF 2333333333333333333
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
const int N = 500005;
int _, n;
int a[N], b[N];
LL dp[N][5];
 
int main(){
 
    for(_ = read(); _; _ --){
        n = read();
        for(int i = 1; i <= n; i ++){
            a[i] = read(), b[i] = read();
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= 2; j++) dp[i][j] = INF;
        }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= 2; j ++){
                for(int k = 0; k <= 2; k ++){
                    if(a[i] + j != a[i - 1] + k){
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
                    }
                }
            }
        }
        printf("%lld\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
    }
    return 0;
}
