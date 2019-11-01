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
const int N = 200010;
int n, m, t, fa[N], dist[N], siz[N];
bool ans[N];
struct Edge{
    int u, v, l, r;
    Edge(){}
    Edge(int u, int v, int l, int r): u(u), v(v), l(l), r(r){}
};
struct Node{
    int u, v, s;
    Node(){}
    Node(int u, int v, int s): u(u), v(v), s(s){}
};
vector<Edge> e;
vector<int> v[N<<2];
map<pair<int, int>, int> p;
stack<Node> st;

inline pair<int, int> find(int p){
    int val = 0;
    while(p != fa[p]) val ^= dist[p], p = fa[p];
    return make_pair(p, val);
}

void buildTree(int rt, int l, int r){
    if(l == r){
        v[rt].clear();
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(rt << 1, l, mid);
    buildTree(rt << 1 | 1, mid + 1, r);
}

void insert(int rt, int l, int r, int il, int ir, int val){
    if(l == il && r == ir){
        v[rt].pb(val);
        return;
    }
    int mid = (l + r) >> 1;
    if(ir <= mid) insert(rt << 1, l, mid, il, ir, val);
    else if(il > mid) insert(rt << 1 | 1, mid + 1, r, il, ir, val);
    else insert(rt << 1, l, mid, il, mid, val), insert(rt << 1 | 1, mid + 1, r, mid + 1, ir, val);
}

void dfs(int rt, int l, int r){
    int cur = (int)st.size();
    bool ok = true;
    for(auto i: v[rt]){
        int u = e[i].u, v = e[i].v;
        auto retx = find(u), rety = find(v);
        int x = retx.first, dx = retx.second;
        int y = rety.first, dy = rety.second;
        if(siz[x] > siz[y]) swap(x, y), swap(dx, dy);
        if(x != y){
            st.emplace(x, y, siz[y]);
            fa[x] = y, siz[y] += siz[x], dist[x] = dx ^ dy ^ 1;
        }
        else{
            if(!(dx ^ dy) && x == y){
                ok = false;
                break;
            }
            else if((dx ^ dy) && x == y){
                continue;
            }
        }
    }
    if(ok){
        if(l == r){
            ans[l] = true;
        }
        else{
            int mid = (l + r) >> 1;
            dfs(rt << 1, l, mid), dfs(rt << 1 | 1, mid + 1, r);
        }
    }
    while(st.size() > cur){
        int x = st.top().u, y = st.top().v, s = st.top().s;
        st.pop();
        fa[x] = x, dist[x] = 0, siz[y] = s;
    }
}

int main(){

    n = read(), m = read(), t = read();
    for(int i = 0; i < m; i ++){
        int u = read(), v = read(), l = read(), r = read();
        if(u > v) swap(u, v);
        e.emplace_back(u, v, l + 1, r);
        p[make_pair(u, v)] = i;
    }
    for(int i = 1; i <= n; i ++){
        fa[i] = i, siz[i] = 1, dist[i] = 0;
    }
    buildTree(1, 1, t + 1);
    for(int i = 0; i < e.size(); i ++){
        if(e[i].l <= e[i].r) insert(1, 1, t + 1, e[i].l, e[i].r, i);
    }
    dfs(1, 1, t + 1);
    for(int i = 1; i <= t; i ++){
        printf(ans[i] ? "Yes\n" : "No\n");
    }

    return 0;
}