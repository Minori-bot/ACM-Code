#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define full(a, b) memset(a, b, sizeof a)
#define __fastIn ios::sync_with_stdio(false), cin.tie(0)
#define pb push_back
using namespace std;
using LL = long long;
inline int lowbit(int x) { return x & (-x); }
inline int read() {
    int ret = 0, w = 0; char ch = 0;
    while(!isdigit(ch)) {
        w |= ch == '-', ch = getchar();
    }
    while(isdigit(ch)) {
        ret = (ret << 3) + (ret << 1) + (ch ^ 48);
        ch = getchar();
    }
    return w ? -ret : ret;
}
template <typename A>
inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C lyd) {
    A ans = 1;
    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
    return ans;
}
const int N = 100;
int _, n;
vector<LL> a, b, t;

int main(){

    for(scanf("%d", &_); _; _ --){
        scanf("%d", &n);
        a.resize(n + 1), b.resize(n + 1);
        t.resize(n + 1);
        for(int i = 1; i <= n; i ++){
            scanf("%lld%lld", &a[i], &b[i]);
        }
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &t[i]);
        }
        LL cur = 0;
        for(int i = 1; i <= n; i ++){
            LL go = t[i] + a[i] - b[i - 1];
            cur += go;
            if(i == n) break;
            LL wait = (b[i] - a[i]) % 2 == 0 ? (b[i] - a[i]) / 2 : LL((b[i] - a[i]) / 2) + 1;
            cur = max(cur + wait, b[i]);
        }
        printf("%lld\n", cur);
    }

    return 0;
}