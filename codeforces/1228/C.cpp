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
const int MOD = 1000000007;
LL x, n;
vector<int> p;
void calc(LL y){
    for(int i = 2; i <= sqrt(y) + 0.5; i ++){
        if(y % i == 0){
            while(y % i == 0) y /= i;
            p.pb(i);
        }
    }
    if(y != 1) p.pb(y);
}
 
int main(){
 
    __fastIn;
 
    cin >> x >> n;
    calc(x);
    LL ans = 1;
    for(auto i: p){
        LL m = n, cur = 0;
        while(m >= i) cur += m / i, m /= i;
        ans *= fpow(i, cur, MOD);
        ans %= MOD;
    }
    cout << ans << endl;
 
    return 0;
}