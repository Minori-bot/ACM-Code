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
int n;
bool vis[N];
struct Node{
    int x, y, z, id;
    Node(){}
    Node(int x, int y, int z, int id): x(x), y(y), z(z), id(id){}
    bool operator < (const Node &rhs) const {
        if(x != rhs.x) return x < rhs.x;
        if(y != rhs.y) return y < rhs.y;
        return z < rhs.z;
    }
};
vector<Node> v;
 
int main(){
 
    n = read();
    for(int i = 0; i < n; i ++){
        int x = read(), y = read(), z = read();
        v.emplace_back(x, y, z, i + 1);
    }
    sort(v.begin(), v.end());
    bool f = false;
    auto t = v.front();
    for(auto &c: v){
        if(vis[c.id]) continue;
        if(!f){
            f ^= 1, t = c;
        }
        else{
            if(c.x == t.x && c.y == t.y){
                vis[c.id] = vis[t.id] = true;
                cout << t.id << " " << c.id << endl;
                f ^= 1;
            }
            else{
                t = c;
            }
        }
    }
    f = false;
    for(auto &c: v){
        if(vis[c.id]) continue;
        if(!f){
            f ^= 1, t = c;
        }
        else{
            if(c.x == t.x){
                vis[c.id] = vis[t.id] = true;
                cout << t.id << " " << c.id << endl;
                f ^= 1;
            }
            else{
                t = c;
            }
        }
    }
    f = false;
    for(auto &c: v){
        if(vis[c.id]) continue;
        if(!f){
            f ^= 1, t = c;
        }
        else{
            vis[c.id] = vis[t.id] = true;
            cout << t.id << " " << c.id << endl;
            f ^= 1;
        }
    }
 
    return 0;
}