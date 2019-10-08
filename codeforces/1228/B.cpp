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
const int N = 1005;
const int p = 1000000007;
int a[N][N], r[N], c[N], h, w;
bool ok = false;
 
void calcR(){
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= r[i]; j ++) a[i][j] = 1;
        a[i][r[i] + 1] = 0;
    }
}
 
void calcC(){
    for(int i = 1; i <= w; i ++){
        for(int j = 1; j <= c[i]; j ++){
            if(a[j][i] == 0){
                ok = true;
                return;
            }
            a[j][i] = 1;
        }
        if(a[c[i] + 1][i] == 1){
            ok = true;
            return;
        }
        a[c[i] + 1][i] = 0;
    }
}
 
LL solve(){
    LL cnt = 0;
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            if(a[i][j] == -1) cnt ++;
        }
    }
    return fpow(2, cnt, p);
}
 
int main(){
 
    full(a, -1);
    h = read(), w = read();
    for(int i = 1; i <= h; i ++) r[i] = read();
    for(int i = 1; i <= w; i ++) c[i] = read();
    calcR();
    calcC();
    if(ok) puts("0");
    else printf("%lld\n", solve());
 
    return 0;
}
