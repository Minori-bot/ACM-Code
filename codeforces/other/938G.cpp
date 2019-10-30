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
int n, m, t, q, k, fa[N], dist[N], siz[N];
class Edge{
public:
    int u, v, w, l, r;
    Edge(){}
    Edge(int u, int v, int w, int l, int r): u(u), v(v), w(w), l(l), r(r){}
};
 
class Query{
public:
    int u, v;
    Query(){}
    Query(int u, int v): u(u), v(v){}
};
 
class XorBasis{
private:
    int a[35];
 
public:
    XorBasis(){
        full(a, 0);
    }
    void insert(int val){
        for(int i = 30; i >= 0; i --){
            if(val & (1 << i)){
                if(a[i] == 0){
                    a[i] = val;
                    return;
                }
                val ^= a[i];
            }
        }
    }
 
    int query(int val){
        int ret = val;
        for(int i = 30; i >= 0; i --){
            if((ret ^ a[i]) < ret) ret ^= a[i];
        }
        return ret;
    }
};
 
class Node{
public:
    int u, v, size;
    Node(){}
    Node(int u, int v, int size): u(u), v(v), size(size){}
};
 
Query query[N];
vector<Edge> e;
map<pair<int, int>, int> p;
vector<int> v[N<<2];
stack<Node> st;
vector<int> ans;
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
 
pair<int, int> find(int p){
    int val = 0;
    while(p != fa[p]) val ^= dist[p], p = fa[p];
    return make_pair(p, val);
}
 
 
void dfs(int rt, int l, int r, XorBasis xb){
    int cur = (int)st.size();
    for(auto &i: v[rt]){
        int u = e[i].u, v = e[i].v;
        auto retx = find(u), rety = find(v);
        int x = retx.first, y = rety.first;
        int dx = retx.second, dy = rety.second;
        if(x == y){
            xb.insert(dx ^ dy ^ e[i].w);
            continue;
        }
        else{
            if(siz[x] > siz[y]){
                swap(x, y), swap(dx, dy);
            }
            st.emplace(x, y, siz[y]);
            fa[x] = y, dist[x] = dx ^ dy ^ e[i].w, siz[y] += siz[x];
        }
    }
    if(l == r){
        int u = query[l].u, v = query[l].v;
        int dx = find(u).second, dy = find(v).second;
        ans.pb(xb.query(dx ^ dy));
    }
    else{
        int mid = (l + r) >> 1;
        dfs(rt << 1, l, mid, xb), dfs(rt << 1 | 1, mid + 1, r, xb);
    }
    while(st.size() > cur){
        int u = st.top().u, v = st.top().v, s = st.top().size;
        st.pop();
        siz[v] = s, fa[u] = u, dist[u] = 0;
    }
}
 
int main(){
 
    n = read(), m = read();
    for(int i = 1; i <= n; i ++){
        fa[i] = i, dist[i] = 0, siz[i] = 1;
    }
    for(int i = 0; i < m; i ++){
        int u = read(), v = read(), w = read();
        if(u > v) swap(u, v);
        e.emplace_back(u, v, w, 1, -1);
        p[make_pair(u, v)] = i;
    }
    q = read(), k = m - 1, t = 1;
    while(q --){
        int opt = read(), u = read(), v = read();
        if(u > v) swap(u, v);
        if(opt == 1){
            int w = read();
            e.emplace_back(u, v, w, t, -1);
            p[make_pair(u, v)] = ++ k;
        }
        else if(opt == 2){
            e[p[make_pair(u, v)]].r = t - 1;
            p.erase(make_pair(u, v));
        }
        else{
            query[t ++] = Query(u, v);
        }
    }
    t --;
    buildTree(1, 1, t);
    for(int i = 0; i < e.size(); i ++){
        if(e[i].r == -1) e[i].r = t;
        if(e[i].l <= e[i].r) insert(1, 1, t, e[i].l, e[i].r, i);
    }
    XorBasis xb = XorBasis();
    dfs(1, 1, t, xb);
    for(auto x: ans) printf("%d\n", x);
 
    return 0;
}