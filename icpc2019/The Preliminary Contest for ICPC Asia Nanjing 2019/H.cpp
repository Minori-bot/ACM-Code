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
int _, n, k, a[N], pos[N], mn[N<<2], mx[N<<2], ans[N];

void push_up(int rt){
    mn[rt] = min(mn[rt << 1], mn[rt << 1 | 1]);
    mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void buildTree(int rt, int l, int r){
    if(l == r){
        mn[rt] = mx[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(rt << 1, l, mid);
    buildTree(rt << 1 | 1, mid + 1, r);
}

void insert(int rt, int l, int r, int p, int k){
    if(l == r){
        mn[rt] = mx[rt] = k;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) insert(rt << 1, l, mid, p, k);
    else insert(rt << 1 | 1, mid + 1, r, p, k);
    push_up(rt);
}

int query(int rt, int l, int r, int L, int R, int val){
    if(l == r){
        if(!mn[rt] || mn[rt] < L || mn[rt] > R) return -1;
        return l;
    }
    int mid = (l + r) >> 1;
    int ret = -1;
    if(val <= mid){
        ret = query(rt << 1, l, mid, L, R, val);
    }
    else{
        if(mn[rt << 1 | 1] <= R && mx[rt << 1 | 1] >= L){
            ret = query(rt << 1 | 1, mid + 1, r, L, R, val);
        }
        if(ret == -1) ret = query(rt << 1, l, mid, L, R, val);
    }
    return ret;
}

int main(){

    for(_ = read(); _; _ --){
        n = read(), k = read();
        for(int i = 1; i <= n; i ++){
            a[i] = read();
            pos[a[i]] = i;
        }
        buildTree(1, 1, n);
        for(int i = 1; i <= n; i ++) insert(1, 1, n, a[i], i);
        for(int i = 1; i <= n; i ++){
            insert(1, 1, n, i, 0);
            int t = query(1, 1, n, max(1, pos[i] - k), min(n, pos[i] + k), i);
            insert(1, 1, n, i, pos[i]);
            if(t == -1) ans[i] = 1;
            else ans[i] = 1 + ans[t];
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}