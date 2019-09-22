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
const int N = 200;
int _, n;
LL m, a, b, c;
struct Rec{
    LL d, h, w;
    Rec(){}
    Rec(int d, int h, int w): d(d), h(h), w(w){}
    bool operator < (const Rec &rhs) const {
        return w < rhs.w;
    }
};
vector<Rec> v;
int main(){
 
    for(scanf("%d", &_); _; _ --){
        v.clear();
        scanf("%d%lld", &n, &m);
        LL mx = 0;
        for(int i = 0; i < n; i ++){
            scanf("%lld%lld", &a, &b);
            v.emplace_back(a, b, b - a);
            mx = max(mx, a);
        }
        if(mx >= m){
            puts("1");
            continue;
        }
        sort(v.begin(), v.end());
        if(v[0].w >= 0){
            puts("-1");
            continue;
        }
        m -= mx;
        printf("%lld\n", (LL)(ceil(m * 1.0 / llabs(v[0].w))) + 1);
    }
    return 0;
}