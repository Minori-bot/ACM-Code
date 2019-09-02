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
const int N = 20005;
int n, cnt, head[N], a, b, c, size[N], rt, ans, dis[N], sum;
LL res, cnt1[3000], cnt2[3000];
bool vis[N];
struct Edge { int v, next, w; } edge[N<<1];

void init(){
    cnt = res = 0;
    full(vis, false), full(head, -1);
}

void addEdge(int a, int b, int c){
    edge[cnt].v = b, edge[cnt].w = c, edge[cnt].next = head[a], head[a] = cnt ++;
}

void dfs(int s, int fa){
    size[s] = 1;
    int mp = 0;
    for(int i = head[s]; i != -1; i = edge[i].next){
        int u = edge[i].v;
        if(vis[u] || u == fa) continue;
        dfs(u, s);
        mp = max(mp, size[u]);
        size[s] += size[u];
    }
    mp = max(mp, sum - size[s]);
    if(mp < ans) ans = mp, rt = s;
}

void getDis(int s, int fa){
    res += cnt2[(2019 - dis[s] % 2019) % 2019];
    cnt1[dis[s]] ++;
    for(int i = head[s]; i != -1; i = edge[i].next){
        int u = edge[i].v;
        if(vis[u] || u == fa) continue;
        dis[u] = (dis[s] + edge[i].w) % 2019;
        getDis(u, s);
    }
}

void calc(int s){
    cnt2[0] ++;
    for(int i = head[s]; i != -1; i = edge[i].next){
        int u = edge[i].v;
        if(vis[u]) continue;
        dis[u] = edge[i].w % 2019;
        getDis(u, s);
        for(int j = 0; j <= 2018; j ++) cnt2[j] += cnt1[j];
        full(cnt1, 0);
    }
    full(cnt2, 0);
}

void solve(int s){
    vis[s] = true, calc(s);
    for(int i = head[s]; i != -1; i = edge[i].next){
        int u = edge[i].v;
        if(vis[u]) continue;
        ans = INF, sum = size[u];
        dfs(u, 0), solve(rt);
    }
}

int main(){

    freopen("data.txt", "r", stdin);
    while(~scanf("%d", &n)){
        init();
        for(int i = 1; i <= n - 1; i ++){
            scanf("%d%d%d", &a, &b, &c);
            addEdge(a, b, c), addEdge(b, a, c);
        }
        ans = INF, sum = n;
        dfs(1, 0), solve(rt);
        printf("%lld\n", res);
    }
    return 0;
}