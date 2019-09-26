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
const int N = 100005;

int n, m, pos[N], a[N], c[N], ans[N];
struct Query{
    int id, x, y;
    Query(){}
    Query(int id, int x, int y): id(id), x(x), y(y){}
    bool operator < (const Query &rhs) const {
        if(x != rhs.x) return x > rhs.x;
        return id < rhs.id;
    }
};
vector<Query> v;
inline void add(int k, int val){
    for(; k <= n; k += lowbit(k)) c[k] += val;
}

inline int query(int k){
    int ret = 0;
    for(; k; k -= lowbit(k)) ret += c[k];
    return ret;
}

int main(){

    n = read(), m = read();
    for(int i = 1; i <= n; i ++){
        a[i] = read(), pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = i + i; j <= n; j += i){
            int x = pos[i], y = pos[j];
            if(x > y) swap(x, y);
            v.emplace_back(0, x, y);
        }
    }
    for(int i = 1; i <= m; i ++){
        int l = read(), r = read();
        v.emplace_back(i, l, r);
    }
    sort(v.begin(), v.end());
    for(auto &e: v){
        if(!e.id) add(e.y, 1);
        else ans[e.id] = query(e.y);
    }
    for(int i = 1; i <= m; i ++){
        printf("%d\n", ans[i]);
    }
    return 0;
}