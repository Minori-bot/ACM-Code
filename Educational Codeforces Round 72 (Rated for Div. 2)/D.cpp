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
 
const int N = 5005;
int n, m, cnt, k, head[N], col[N<<1], dfn[N];
bool cycle, in[N];
struct Edge { int v, next, id; } edge[N<<1];
 
void addEdge(int a, int b, int c){
    edge[cnt].v = b, edge[cnt].id = c, edge[cnt].next = head[a], head[a] = cnt ++;
}
 
void dfs(int s){
    dfn[s] = ++ k;
    in[s] = true;
    for(int i = head[s]; i != -1; i = edge[i].next){
        int u = edge[i].v, id = edge[i].id;
        if(!dfn[u]){
            col[id] = 1;
            dfs(u);
        }
        else if(in[u]){
            col[id] = 2;
            cycle = true;
        }
        else{
            col[id] = 1;
        }
    }
    in[s] = false;
}
 
int main(){
 
    full(head, -1);
    n = read(), m = read();
    for(int i = 1; i <= m; i ++){
        int u = read(), v = read();
        addEdge(u, v, i);
    }
    for(int i = 1; i <= n; i ++){
        if(!dfn[i]) dfs(i);
    }
    printf(cycle ? "2\n" : "1\n");
    for(int i = 1; i <= m; i ++){
        printf("%d%c", col[i], " \n"[i == m]);
    }
 
    return 0;
}