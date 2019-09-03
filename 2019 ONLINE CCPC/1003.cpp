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
const int N = 200005;
int _, n, q, tot, st[N][31], lb[N], tree[20*N], lc[20*N], rc[20*N], root[N];
int l, r, k;

namespace SuffixArray{

    char s[N];
    int sa[N], t[N], t2[N], c[N], rnk[N], height[N];

    void build(int m, int n){
        n ++;
        int *x = t, *y = t2;
        for(int i = 0; i < m; i ++) c[i] = 0;
        for(int i = 0; i < n; i ++) c[x[i] = s[i]] ++;
        for(int i = 0; i < m; i ++) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i --) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1){
            int p = 0;
            for(int i = n - k; i < n; i ++) y[p++] = i;
            for(int i = 0; i < n; i ++){
                if(sa[i] >= k) y[p++] = sa[i] - k;
            }
            for(int i = 0; i < m; i ++) c[i] = 0;
            for(int i = 0; i < n; i ++) c[x[y[i]]] ++;
            for(int i = 0; i < m; i ++) c[i] += c[i - 1];
            for(int i = n - 1; i >= 0; i --) sa[--c[x[y[i]]]] = y[i];
            swap(x, y);
            p = 1, x[sa[0]] = 0;
            for(int i = 1; i < n; i ++){
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && sa[i - 1] + k < n &&
                        sa[i] + k < n && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p ++;
            }
            if(p >= n) break;
            m = p;
        }

        n --;
        int k = 0;
        for(int i = 0; i <= n; i ++) rnk[sa[i]] = i;
        for(int i = 0; i < n; i ++){
            if(!rnk[i]) continue;
            if(k) k --;
            int j = sa[rnk[i] - 1];
            while(i + k < n && j + k < n && s[i + k] == s[j + k]) k ++;
            height[rnk[i]] = k;
        }
    }
}
using SuffixArray::sa;
using SuffixArray::rnk;
using SuffixArray::height;

void initST(){
    //lb[0] = -1; for(int i = 1; i <= n; i ++) lb[i] = lb[i >> 1] + 1;
    for(int i = 1; i <= n; i ++) st[i][0] = height[i];
    for(int j = 1; j < 31; j ++){
        for(int i = 0; i + (1 << j) - 1 <= n; i ++){
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int l, int r){
    int t = lb[r - l + 1];
    return min(st[l][t], st[r - (1 << t) + 1][t]);
}

int lcp(int x, int y){
    if(x == y) return n;
    if(x > y) swap(x, y);
    return rmq(x + 1, y);
}

int buildTree(int l, int r){
    int cur = ++ tot;
    if(l == r) return cur;
    int mid = (l + r) >> 1;
    lc[cur] = buildTree(l, mid);
    rc[cur] = buildTree(mid + 1, r);
    return cur;
}

int insert(int rt, int l, int r, int pos){
    int cur = ++ tot;
    tree[cur] = tree[rt] + 1, lc[cur] = lc[rt], rc[cur] = rc[rt];
    if(l == r) return cur;
    int mid = (l + r) >> 1;
    if(pos <= mid) lc[cur] = insert(lc[rt], l, mid, pos);
    else rc[cur] = insert(rc[rt], mid + 1, r, pos);
    return cur;
}

int query(int a, int b, int l, int r, int k){
    if(l == r){
        return l;
    }
    int sum = tree[lc[b]] - tree[lc[a]];
    int mid = (l + r) >> 1;
    if(k <= sum) return query(lc[a], lc[b], l, mid, k);
    return query(rc[a], rc[b], mid + 1, r, k - sum);
}

int solve(int L, int R){
    int x, y;
    int l = 1, r = rnk[L];
    int len = R - L + 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(lcp(mid, rnk[L]) >= len) r = mid;
        else l = mid + 1;
    }
    x = l;
    l = rnk[L], r = n;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(lcp(rnk[L], mid) >= len) l = mid;
        else r = mid - 1;
    }
    y = l;
    if(k > y - x + 1) return -1;
    return query(root[x - 1], root[y], 0, n - 1, k) + 1;
}

int main(){

    lb[0] = -1; for(int i = 1; i < N; i ++) lb[i] = lb[i >> 1] + 1;
    for(scanf("%d", &_); _; _ --){
        tot = 0;
        scanf("%d%d", &n, &q);
        scanf("%s", SuffixArray::s);
        SuffixArray::build(128, n);
        initST();
        root[0] = buildTree(0, n - 1);
        for(int i = 1; i <= n; i ++){
            root[i] = insert(root[i - 1], 0, n - 1, sa[i]);
        }
        while(q --){
            scanf("%d%d%d", &l, &r, &k);
            l --, r --;
            printf("%d\n", solve(l, r));
        }
    }
    return 0;
}