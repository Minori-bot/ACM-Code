#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pb push_back
using namespace std;
using LL = long long;
using pii = pair<int, int>;

inline int lowbit(int x) { return x & (-x); }
template <typename A>
inline A __lcm(A a, A b){ return a / __gcd(a, b) * b; }
template <typename A, typename B, typename C>
inline A fpow(A x, B p, C lyd) {
    A ans = 1;
    for(; p; p >>= 1, x = 1LL * x * x % lyd)if(p & 1)ans = 1LL * x * ans % lyd;
    return ans;
}

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 10;
int n, m, cnt;
vector<int> w, post, vis, sum, ind, dp;
vector<int> g[N], rg[N], G[N];

void dfs(int s){
    vis[s] = 1;
    for(auto u: rg[s]){
        if(!vis[u]) dfs(u);
    }
    post.pb(s);
}

void kosaraju(int s, int scc){
    vis[s] = scc;
    sum[scc] += w[s];
    for(auto u: g[s]){
        if(vis[u] == -1) kosaraju(u, scc);
    }
}

int bfs(){
    dp = vector<int>(cnt);
    queue<int> q;
    for(int i = 0; i < cnt; i ++){
        if(!ind[i]){
            q.push(i);
            dp[i] = sum[i];
        }
    }
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(auto u: G[s]){
            dp[u] = max(dp[u], dp[s] + sum[u]);
            if(!-- ind[u]) q.push(u);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);

    cin >> n >> m;
    w.resize(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> w[i];
    }
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        rg[v].pb(u);
    }
    vis = vector<int>(n + 1);
    sum = vector<int>(n + 1);
    for(int i = 1; i <= n; i ++){
        if(!vis[i]) dfs(i);
    }
    reverse(post.begin(), post.end());
    fill(vis.begin(), vis.end(), -1);
    for(auto s: post){
        if(vis[s] == -1) kosaraju(s, cnt ++);
    }
    ind = vector<int>(cnt);
    for(int s = 1; s <= n; s ++){
        for(auto u: g[s]){
            if(vis[s] != vis[u]) G[vis[s]].pb(vis[u]), ind[vis[u]] ++;
        }
    }
    cout << bfs() << endl;

    return 0;
}

