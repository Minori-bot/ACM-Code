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
const int N = 50005;
int n, m, cnt;
bool vis[N];
LL a[N<<2], p[N];
vector<pair<int, LL>> g[N];

void dfs(int s, LL cur){
    vis[s] = true, p[s] = cur;
    for(auto &u: g[s]){
        if(!vis[u.first]) dfs(u.first, cur ^ u.second);
        else a[++cnt] = (cur ^ u.second ^ p[u.first]);
    }
}

namespace XorBasis{

    int t = 0;

    void build(){
        t = cnt;
        for(int i = 1; i <= cnt; i ++){
            for(int j = i + 1; j <= cnt; j ++){
                if(a[j] > a[i]) swap(a[j], a[i]);
            }
            if(a[i] == 0){
                t = i - 1;
                break;
            }
            for(int k = 63; k >= 0; k --){
                if(a[i] & (1LL << k)){
                    for(int j = 1; j <= cnt; j ++){
                        if(i != j && (a[j] & (1LL << k))) a[j] ^= a[i];
                    }
                    break;
                }
            }
        }
    }

    LL query(LL val){
        LL ret = val;
        for(int i = 1; i <= t; i ++){
            if((ret ^ a[i]) > ret) ret ^= a[i];
        }
        return ret;
    }
}

using XorBasis::build;
using XorBasis::query;

int main(){

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++){
        int u, v;
        LL w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(1, 0);
    build();
    printf("%lld\n", query(p[n]));

    return 0;
}