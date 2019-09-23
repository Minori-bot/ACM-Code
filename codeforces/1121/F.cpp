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
const int N = 500005;
int n, k, x[N], y[N], w[N], b[N<<1], t[N<<3];
LL tree[N<<3], lazy[N<<3];
vector<pair<int, int>> f[N<<1];

void push_up(int rt){
    if(tree[rt << 1 | 1] <= tree[rt << 1]) tree[rt] = tree[rt << 1], t[rt] = t[rt << 1];
    else tree[rt] = tree[rt << 1 | 1], t[rt] = t[rt << 1 | 1];
}

void push_down(int rt){
    int l = rt << 1, r = rt << 1 | 1;
    lazy[l] += lazy[rt], lazy[r] += lazy[rt];
    tree[l] += lazy[rt], tree[r] += lazy[rt];
    lazy[rt] = 0;
}

void buildTree(int rt, int l, int r){
    if(l == r){
        tree[rt] = -b[l], t[rt] = l;
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(rt << 1, l, mid);
    buildTree(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

void add(int rt, int l, int r, int al, int ar, int val){
    if(l == al && r == ar){
        lazy[rt] += val, tree[rt] += val;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(rt);
    if(ar <= mid) add(rt << 1, l, mid, al, ar, val);
    else if(al > mid) add(rt << 1 | 1, mid + 1, r, al, ar, val);
    else add(rt << 1, l, mid, al, mid, val), add(rt << 1 | 1, mid + 1, r, mid + 1, ar, val);
    push_up(rt);
}

pair<LL, int> query(int rt, int l, int r, int ql, int qr){
    if(l == ql && r == qr){
        return make_pair(tree[rt], t[rt]);
    }
    int mid = (l + r) >> 1;
    push_down(rt);
    if(qr <= mid) return query(rt << 1, l, mid, ql, qr);
    else if(ql > mid) return query(rt << 1 | 1, mid + 1, r, ql, qr);
    else{
        pair<LL, int> a = query(rt << 1, l, mid, ql, mid);
        pair<LL, int> b = query(rt << 1 | 1, mid + 1, r, mid + 1, qr);
        return a.first >= b.first ? a : b;
    }
}

int main(){

    n = read();
    for(int i = 1; i <= n; i ++){
        x[i] = read(), y[i] = read(), w[i] = read();
        b[++k] = x[i], b[++k] = y[i];
    }
    sort(b + 1, b + k + 1);
    k = (int)(unique(b + 1, b + k + 1) - b - 1);
    for(int i = 1; i <= n; i ++){
        x[i] = (int)(lower_bound(b + 1, b + k + 1, x[i]) - b);
        y[i] = (int)(lower_bound(b + 1, b + k + 1, y[i]) - b);
        if(x[i] > y[i]) swap(x[i], y[i]);
        f[x[i]].emplace_back(y[i], w[i]);
    }
    buildTree(1, 1, k);
    LL ans = 0;
    int cx = b[k] + 1, cy = b[k] + 1;
    for(int i = k; i >= 1; i --){
        for(auto &e: f[i]){
            add(1, 1, k, e.first, k, e.second);
        }
        pair<LL, int> p = query(1, 1, k, i, k);
        if(ans < p.first + b[i]){
            ans = p.first + b[i];
            cx = b[i], cy = b[p.second];
        }
    }
    printf("%lld\n%d %d %d %d\n", ans, cx, cx, cy, cy);
    return 0;
}