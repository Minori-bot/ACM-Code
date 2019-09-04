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
const int N = 300005;
const int M = 1000005;
int n, m, cur, k, c[M], lx, ly, ans[N], maxn;
struct Query{
    int op, id, x, y;
    Query(){}
    Query(int op, int id, int x, int y): op(op), id(id), x(x), y(y){}
}v[N<<1], aux[N<<1], a[N<<1];

inline void add(int x, int val){
    for(; x <= maxn; x += lowbit(x)) c[x] = max(c[x], val);
}

inline int query(int x){
    int ret = 0;
    for(; x; x -= lowbit(x)) ret = max(ret, c[x]);
    return ret;
}

void CDQ(int l, int r){
    if(l == r) return;
    int mid = (l + r) >> 1;
    CDQ(l, mid), CDQ(mid + 1, r);
    for(int i = l; i <= r ; i ++){
        aux[i - l] = v[i];
    }
    int i = 0, j = mid + 1 - l;
    for(int k = l; k <= r; k ++){
        if(i > mid - l){
            if(aux[j].op == 2){
                int tmp = query(aux[j].y);
                if(tmp) ans[aux[j].id] = min(ans[aux[j].id], aux[j].x + aux[j].y - tmp);
            }
            v[k] = aux[j++];
        }
        else if(j > r - l){
            if(aux[i].op == 1) add(aux[i].y, aux[i].x + aux[i].y);
            v[k] = aux[i++];
        }
        else if(aux[i].x <= aux[j].x){
            if(aux[i].op == 1) add(aux[i].y, aux[i].x + aux[i].y);
            v[k] = aux[i++];
        }
        else{
            if(aux[j].op == 2){
                int tmp = query(aux[j].y);
                if(tmp) ans[aux[j].id] = min(ans[aux[j].id], aux[j].x + aux[j].y - tmp);
            }
            v[k] = aux[j++];
        }
    }
    for(int k = 0; k < mid - l + 1; k ++){
        if(aux[k].op == 1){
            for(int x = aux[k].y; x <= maxn; x += lowbit(x)) c[x] = 0;
        }
    }
}

int main(){

    full(ans, INF);
    n = read(), m = read();
    lx = -INF, ly = -INF;
    for(int i = 1; i <= n; i ++){
        int x = read() + 1, y = read() + 1;
        v[++cur] = Query(1, 0, x, y);
    }
    for(int i = 1; i <= m; i ++){
        int opt = read(), x = read() + 1, y = read() + 1;
        if(opt == 1){
            v[++cur] = Query(opt, 0, x, y);
        }
        else{
            v[++cur] = Query(opt, ++k, x, y);
        }
    }
    for(int i = 1; i <= cur; i ++){
        a[i] = v[i];
        lx = max(lx, v[i].x);
        ly = max(ly, v[i].y);
    }
    maxn = max(lx, ly) + 1;
    CDQ(1, cur);
    for(int i = 1; i <= cur; i ++){
        v[i] = a[i], v[i].y = maxn - v[i].y;
    }
    CDQ(1, cur);
    for(int i = 1; i <= cur; i ++){
        v[i] = a[i], v[i].x = maxn - v[i].x;
    }
    CDQ(1, cur);
    for(int i = 1; i <= cur; i ++){
        v[i] = a[i], v[i].x = maxn - v[i].x, v[i].y = maxn - v[i].y;
    }
    CDQ(1, cur);
    for(int i = 1; i <= k; i ++){
        printf("%d\n", ans[i]);
    }
    return 0;
}