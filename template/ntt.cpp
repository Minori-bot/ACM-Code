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
const int N = 4000005;
const int p = 998244353, g = 3, invg = 332748118;

int n, m, k, len = 1, r[N];
LL a[N], b[N], c[N];

void ntt(LL y[], int len, int type){
    for(int i = 0; i < len; i ++){
        if(i < r[i]) swap(y[i], y[r[i]]);
    }
    for(int h = 2; h <= len; h <<= 1){
        LL wn = fpow(type == 1 ? g : invg, (p - 1) / h, p);
        for(int i = 0; i < len; i += h){
            LL w = 1;
            for(int j = i; j < i + h / 2; j ++){
                LL t = y[j], u = w * y[j + h / 2] % p;
                y[j] = (t + u) % p, y[j + h / 2] = (t + p - u) % p;
                w = w * wn % p;
            }
        }
    }
}

int main(){

    n = read(), m = read();
    for(int i = 0; i <= n; i ++){
        a[i] = read();
        a[i] = (a[i] + p) % p;
    }
    for(int i = 0; i <= m; i ++){
        b[i] = read();
        b[i] = (b[i] + p) % p;
    }
    while(len <= n + m) len <<= 1, k ++;
    for(int i = 0; i < len; i ++){
       r[i] = (r[i >> 1] >> 1) | ((i & 1) << (k - 1));
    }
    ntt(a, len, 1);
    ntt(b, len, 1);
    for(int i = 0; i < len; i ++){
        c[i] = a[i] * b[i] % p;
    }
    ntt(c, len, -1);
    LL inv = fpow(len, p - 2, p);
    for(int i = 0; i <= n + m; i ++){
        printf("%lld%c", (c[i] * inv) % p, " \n"[i == n + m]);
    }

    return 0;
}