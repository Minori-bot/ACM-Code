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
const int N = 50;
const int p = 1000000007;
int n;
LL a[N], s, inv[N];

LL C(LL y, int x){
    if(y < 0 || x < 0 || y < x) return 0;
    y %= p;
    if(y == 0 || x == 0) return 1;
    LL ans = 1;
    for(int i = 0; i <= x - 1; i ++){
        ans *= (y - i);
        ans %= p;
    }
    for(int i = 1; i <= x; i ++){
        ans *= inv[i];
        ans %= p;
    }
    return ans;
}

int main(){

    __fastIn;

    cin >> n >> s;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= 20; i ++){
        inv[i] = fpow(i, p - 2, p);
    }
    LL ans = C(n + s - 1, n - 1);
    for(int k = 1; k <= (1 << n) - 1; k ++){
        LL t = n + s, z = 0;
        for(int i = 0; i < n; i ++){
            if((k >> i) & 1){
                z ++;
                t -= a[i + 1];
            }
        }
        t -= z + 1;
        if(z & 1){
            ans = ans + p - C(t, n - 1);
            ans %= p;
        }
        else{
            ans += C(t, n - 1);
            ans %= p;
        }
    }
    cout << ans << endl;

    return 0;
}