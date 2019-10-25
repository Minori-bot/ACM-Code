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
const int N = 3000;
int n;
bool vis[N];
vector<pair<pair<int, int>, pair<int, int>>> v;
 
int main(){
 
    n = read();
    for(int i = 0; i < n; i ++){
        int x = read(), y = read(), z = read();
        v.emplace_back(make_pair(x, y), make_pair(z, i));
    }
    sort(v.begin(), v.end());
    int m = n;
    for(int i = 0; i < n - 1; i ++){
        auto x = v[i], y = v[i];
        if(vis[x.second.second]) continue;
        int index = n;
        for(int j = i + 1; j < n; j ++){
            if(!vis[v[j].second.second]){
                y = v[j];
                index = j;
                break;
            }
        }
        for(int j = index + 1; j < n; j ++){
            auto z = v[j];
            if(vis[z.second.second]) continue;
            int x1 = min(x.first.first, y.first.first), x2 = max(x.first.first, y.first.first);
            int y1 = min(x.first.second, y.first.second), y2 = max(x.first.second, y.first.second);
            int z1 = min(x.second.first, y.second.first), z2 = max(x.second.first, y.second.first);
            if(z.first.first >= x1 && z.first.first <= x2 && z.first.second >= y1 && z.first.second <= y2
            && z.second.first >= z1 && z.second.first <= z2) y = z;
        }
        vis[x.second.second] = vis[y.second.second] = true;
        m -= 2;
        cout << x.second.second + 1 << " " << y.second.second + 1 << endl;
        if(!m) break;
    }
    return 0;
}
