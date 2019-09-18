#include <bits/stdc++.h>
#define INF 2000000000
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
const int N = 200005;
int n, m, a[N], tree[N<<2][15], y[15];
LL ans[N<<2];

void push_up(int rt){
    ans[rt] = INF;
    for(int i = 1; i <= 10; i ++){
        if(tree[rt << 1][i] != INF && tree[rt << 1 | 1][i] != INF){
            ans[rt] = min(ans[rt], 1LL * tree[rt << 1][i] + tree[rt << 1 | 1][i]);
        }
        tree[rt][i] = min(tree[rt << 1][i], tree[rt << 1 | 1][i]);
    }
    ans[rt] = min(ans[rt], min(ans[rt << 1], ans[rt << 1 | 1]));
}

void buildTree(int rt, int l, int r){
    ans[rt] = INF;
    if(l == r){
        int t = a[l];
        for(int i = 1; i <= 10; i ++){
            int x = t % 10;
            if(!x) tree[rt][i] = INF;
            else tree[rt][i] = a[l];
            t /= 10;
        }
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(rt << 1, l, mid);
    buildTree(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

void insert(int rt, int l, int r, int pos, int val){
    if(l == r){
        int t = val;
        for(int i = 1; i <= 10; i ++){
            int x = t % 10;
            if(!x) tree[rt][i] = INF;
            else tree[rt][i] = val;
            t /= 10;
        }
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) insert(rt << 1, l, mid, pos, val);
    else insert(rt << 1 | 1, mid + 1, r, pos, val);
    push_up(rt);
}

LL query(int rt, int l, int r, int ql, int qr){
    if(l == ql && r == qr){
        LL res = INF;
        for(int i = 1; i <= 10; i ++){
            if(y[i] != INF && tree[rt][i] != INF){
                res = min(res, 1LL * y[i] + tree[rt][i]);
            }
        }
        for(int i = 1; i <= 10; i ++){
            y[i] = min(y[i], tree[rt][i]);
        }
        return min(ans[rt], res);
    }
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(rt << 1, l, mid, ql, qr);
    else if(ql > mid) return query(rt << 1 | 1, mid + 1, r, ql, qr);
    else return min(query(rt << 1, l, mid, ql, mid), query(rt << 1 | 1, mid + 1, r, mid + 1, qr));
}

LL solve(int l, int r){
    for(int i = 1; i <= 15; i ++) y[i] = INF;
    LL t = query(1, 1, n, l, r);
    return t == INF ? -1 : t;
}

int main(){

    n = read(), m = read();
    for(int i = 1; i <= n; i ++) a[i] = read();
    buildTree(1, 1, n);
    while(m --){
        int opt = read(), l = read(), r = read();
        if(opt == 1){
            insert(1, 1, n, l, r);
        }
        else{
            printf("%lld\n", solve(l, r));
        }
    }
    return 0;
}