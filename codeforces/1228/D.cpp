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
int n, m, col[N], cnt[5];
bool vis[N];
vector<int> g[N];
 
void calc(){
    col[1] = 1, cnt[1] += 1, vis[1] = true;
    for(auto &s: g[1]) vis[s] = true;
    for(int i = 1; i <= n; i ++){
        if(!vis[i]) col[i] = 1, cnt[1] ++;
    }
    for(int i = 2; i <= n; i ++){
        if(vis[i]){
            for(auto &s: g[i]){
                if(!col[s]) col[s] = 3, cnt[3] ++;
            }
            col[i] = 2, cnt[2] ++;
            break;
        }
    }
    for(int i = 1; i <= n; i ++){
        if(!col[i]) col[i] = 2, cnt[2] ++;
    }
}
 
bool solve(){
    for(int i = 1; i <= n; i ++){
        for(auto &s: g[i]){
            if(col[s] == col[i]) return false;
        }
        if(col[i] == 1 && g[i].size() != cnt[2] + cnt[3]) return false;
        else if(col[i] == 2 && g[i].size() != cnt[1] + cnt[3]) return false;
        else if(col[i] == 3 && g[i].size() != cnt[2] + cnt[1]) return false;
    }
    return (cnt[1] && cnt[2] && cnt[3]);
}
 
int main(){
 
    n = read(), m = read();
    for(int i = 1; i <= m; i ++){
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }
    calc();
    bool f = solve();
    if(!f) puts("-1");
    else{
        for(int i = 1; i <= n; i ++){
            printf("%d%c", col[i], " \n"[i == n]);
        }
    }
    
    return 0;
}